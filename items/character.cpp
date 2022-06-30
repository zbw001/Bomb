#include "../globals.h"
#include "character.h"
#include <QDebug>
#include <QPointF>
#include <QtGlobal>
#include <QGraphicsScene>

Character::Character(QGraphicsItem *parent, TileMap *tile_map, int player_id, int character_id) :
    Sprite(parent, {{"idle", *Animations::CHARACTER_IDLE}, {"die", *Animations::CHARACTER_DIE}, {"hurt", *Animations::HURT}, {"walk", *Animations::WALK}}, "idle", false)
	{
        this->player_id = player_id;
        this->character_id = character_id;
		this->tile_map = tile_map;
        if (player_id == 0) this->mark = new Sprite(this, Animations::MARK->setColor(Qt::blue), false);
        else this->mark = new Sprite(this, Animations::MARK->setColor(Qt::red), false);
        this->mark->setPos(QPointF((Consts::CHARACTER_WIDTH - Consts::MARK_SIZE) / 2.0, -Consts::MARK_SIZE / 2.0 - 25));
        this->mark->setOpacity(0.3);
		HP_bar = new HPBar(this);
        HP_bar->setPos(QPointF(5, 0));
        setHP(Consts::MAX_HP);
        setData(0, QVariant("character"));
        dead = false;
        current = false;
	}


bool Character::isDead() {return dead;}

void Character::setCurrent(bool current) {
    this->current = current;
    if (current) this->mark->setOpacity(1);
    else this->mark->setOpacity(0.3);
}

Character::~Character() {
	delete HP_bar;
    delete mark;
}

int Character::HP() {return _HP;}

void Character::setHP(int HP) {
	_HP = HP;
    HP_bar->setHP(HP);
}

void Character::hurt(int delta) {
    if (!delta) return;
    //qDebug() << delta;
    assert(! dead);
    delta = qMin(delta, HP());
    setHP(HP() - delta);
    if (HP() <= 0) {
        dead = true;
        setAnimation("die");
        connect(this, &Sprite::animationFinished, [this](){PhysicsObject::setProcessEnabled(false); this->scene()->removeItem(this);});
    }
}

bool Character::isMoving() {
    return velocity.manhattanLength() != 0;
}

bool Character::isAnimationFinished() {
    return Sprite::finished;
}

void Character::process(double delta) {
    //qDebug() << delta;
    //qDebug() << QGraphicsItem::scenePos();
    bool moving = isMoving();
    if (qAbs(velocity.x()) > Consts::EPS || qAbs(velocity.y()) > Consts::EPS) {
        moving = true;
    }
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
    if (moving && !isMoving()) {
        emit stopped();
        this->resetTransform();
        this->flipHorizontal();
        HP_bar->resetTransform();
        HP_bar->flipHorizontal();
        this->setAnimation("idle");
    }
    if (isMoving() && qAbs(velocity.x()) > Consts::EPS) {
        HP_bar->resetTransform();
        this->resetTransform();
        if (velocity.x() < 0) {
            HP_bar->flipHorizontal();
            this->flipHorizontal();
        }
    }
    if (!QRectF(0, - Consts::GAME_SCENE_HEIGHT / 3, Consts::GAME_SCENE_WIDTH, Consts::GAME_SCENE_HEIGHT / 3 + Consts::GAME_SCENE_HEIGHT).intersects(this->sceneBoundingRect())) {
        emit stopped();
        velocity = QPointF();
        dead = true;
        PhysicsObject::setProcessEnabled(false);
        this->scene()->removeItem(this);
    }
}
