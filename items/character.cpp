#include "../globals.h"
#include "character.h"
#include <QDebug>
#include <QPointF>
#include <QtGlobal>
#include <QGraphicsScene>

Character::Character(QGraphicsItem *parent, TileMap *tile_map) : 
    Sprite(parent, {{"idle", *Animations::CHARACTER_IDLE}, {"die", *Animations::CHARACTER_DIE}}, "idle", false)
	{
		this->tile_map = tile_map;
		HP_bar = new HPBar(this);
        HP_bar->setPos(QPointF(7, 0));
        setHP(Consts::MAX_HP);
        setData(0, QVariant("character"));
        dead = false;
	}


bool Character::isDead() {return dead;}

Character::~Character() {
	delete HP_bar;
}

int Character::HP() {return _HP;}

void Character::setHP(int HP) {
	_HP = HP;
    HP_bar->setHP(HP);
}

void Character::hurt(int delta) {
    assert(! dead);
    delta = qMin(delta, HP());
    setHP(HP() - delta);
    if (HP() <= 0) {
        dead = true;
        setAnimation("dead");
        connect(this, &Sprite::animationFinished, [this](){this->scene()->removeItem(this);});
    }
}

void Character::process(double delta) {
    //qDebug() << delta;
    qDebug() << QGraphicsItem::scenePos();
	velocity.setY(velocity.y() + Consts::GRAVITY * delta);
    QRectF rect = Sprite :: sceneBoundingRect();
    if (velocity.y() > 0 && tile_map->dis_to_ground(rect) < Consts::EPS) {
        setPos(pos() - QPointF(0, tile_map->dis_to_ground(rect)));
        velocity.setY(0);
        if (velocity.x() > 0) {
            velocity.setX(qMax(0.0, velocity.x() - delta * Consts::MU));
        } else velocity.setX(qMin(0.0, velocity.x() + delta * Consts::MU));
    }
	QPointF d = velocity * delta;
    if (tile_map -> collides_with_rect(rect.adjusted(d.x(), d.y(), 0, 0))) {
        d.setX(0);
        velocity.setX(0);
    }
	setPos(pos() + d);
}
