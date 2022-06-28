#include "../consts.h"
Character::Character(QGraphicsItem *parent, TileMap *tile_map) : 
	ImageRect(parent, "../" + CHARACTER_IMAGE, "", CHARACTER_WIDTH, CHARACTER_HEIGHT, true), 
	HP(MAX_HP)
	{
		this->tile_map = tile_map;
		HP_bar = new HPBar(this);
	}

Character::~Character() {
	delete HP_bar;
}

Character::HP() {return _HP;}

Character::setHP(int HP) {
	_HP = HP;
	HP_Bar->setHP(HP);
}

void Character::process(double delta) {
	RectF rect = ImageRect :: boundingRect()
	if (velocity.y() > 0 && tile_map.is_on_ground(rect)) 
		velocity.setY(0);
	QPointF d = velocity * delta;
	if (tile_map.collides_with_rect(rect.adjusted(d.x(), d.y(), 0, 0))) 
		d = QPointF();
	setPos(pos() + d);
}