#include "sprite.h"
#include "../physics_object.h"
#include "tile_map.h"

#include <QPointF>
#include <QPainter>
#include <QGraphicsItem>
#include <QObject>

class Bomb : public Sprite, public PhysicsObject {
Q_OBJECT
public:
    Bomb(QGraphicsItem *parent, TileMap* tile_map);
	void process(double delta) override;
	QPointF velocity;
	QPainterPath shape() const override;
	
signals:
	void exploded(Bomb* bomb);
	void animation_finished(Bomb* bomb);

private:
	TileMap* tile_map;
};
