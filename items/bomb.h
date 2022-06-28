#include "sprite.h"
#include "../physics_object.h"
#include "tile_map.h"

#include <QPointF>
#include <QPainter>
#include <QGraphicsItem>

class Bomb : public ImageRect, public PhysicsObject {
public:
    Bomb(QGraphicsItem *parent, TileMap* tile_map);
	void process(double delta);
	QPointF velocity;
	QPainterPath shape() const override;
	
signals:
	void exploded(Bomb* bomb);
	void animation_finished(Bomb* bomb);

private:
	TileMap* tile_map;
};
