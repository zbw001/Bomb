#include "../globals.h"
#include "bomb.h"
#include <QList>
#include <QVariant>
#include <QDebug>
#include <QtGlobal>
#include <QPointF>
#include <QRectF>
#include <QGraphicsScene>
#include <QGraphicsItem>

Bomb::Bomb(QGraphicsItem *parent, TileMap *tile_map, QGraphicsItem *owner) :
    Sprite(parent, {{"bomb", *Animations::BOMB}, {"explose", *Animations::EXPLOSION1}}, "bomb", false) {
		this->tile_map = tile_map;
        this->owner = owner;
        collided = false;
	}

void Bomb::process(double delta) {
    if (collided) return;
    velocity.setY(velocity.y() + Consts::GRAVITY * delta);
	QPointF d = velocity * delta;
	setPos(pos() + d);
    QList<QGraphicsItem*> items = QGraphicsItem::collidingItems();
    for (int i = 0; i < items.length(); i++) {
        QGraphicsItem* item = items[i];
        QVariant v = item->data(0);
        qDebug() << v;
        if (!v.isNull() && item != owner) {
            if (v.toString() == "character" || v.toString() == "block") {
                collided = true;
                break;
            }
        }
    }
    //qDebug() << items.length();
    if (collided) {
		// 希望他检测有交矩形的算法足够高效...
		velocity = QPointF();
		emit exploded(this);
        connect(this, &Sprite::animationFinished, [this](){this->scene()->removeItem(this); delete this;});
        Sprite::setAnimation("explose");
        QGraphicsItem::setPos(QGraphicsItem::pos() + QPointF((Consts::BOMB_WIDTH-Consts::EXPLOSION1_SIZE) / 2.0 - 5, (Consts::BOMB_HEIGHT-Consts::EXPLOSION1_SIZE) / 2.0 - 70));
	}
    if (!QRectF(0, - Consts::GAME_SCENE_HEIGHT / 3, Consts::GAME_SCENE_WIDTH, Consts::GAME_SCENE_HEIGHT / 3 + Consts::GAME_SCENE_HEIGHT).intersects(this->sceneBoundingRect())) {
        this->scene()->removeItem(this); delete this;
    }
}

QPainterPath Bomb :: shape() const {
	QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
