#include "../globals.h"
#include "character.h"
#include <QDebug>

Character::Character(QGraphicsItem *parent, TileMap *tile_map) : 
    Sprite(parent, *Animations::CHARACTER_IDLE, true, false)
	{
		this->tile_map = tile_map;
		HP_bar = new HPBar(this);
        setHP(Consts::MAX_HP);
	}

Character::~Character() {
	delete HP_bar;
}

int Character::HP() {return _HP;}

void Character::setHP(int HP) {
	_HP = HP;
    HP_bar->setHP(HP);
}

void Character::process(double delta) {
    //qDebug() << delta;
	velocity.setY(velocity.y() + Consts::GRAVITY * delta);
    QRectF rect = Sprite :: sceneBoundingRect();
    if (velocity.y() > 0 && tile_map->dis_to_ground(rect) < Consts::EPS) {
        setPos(pos() + QPointF(0, tile_map->dis_to_ground(rect)));
        velocity.setY(0);
    }
	QPointF d = velocity * delta;
    if (tile_map -> collides_with_rect(rect.adjusted(d.x(), d.y(), 0, 0))) {
        d.setX(0);
        velocity.setX(0);
    }
	setPos(pos() + d);
}
