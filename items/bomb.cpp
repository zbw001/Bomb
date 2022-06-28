#include "../globals.h"

Bomb::Bomb(QGraphicsItem *parent, TileMap *tile_map) : 
	Bomb(parent, "../" + Bomb_IMAGE, "", Bomb_WIDTH, Bomb_HEIGHT, true) {
		this->tile_map = tile_map;
	}

void Bomb::process(double delta) {
	QPointF d = velocity * delta;
	setPos(pos() + d);
	if (!QGraphicsItem :: collidingItems().empty()) {
		// 希望他检测有交矩形的算法足够高效...
		velocity = QPointF();
		emit exploded(this);
		
	}
}

QPainterPath Bomb :: shape() const {
	QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
