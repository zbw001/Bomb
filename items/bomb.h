#ifndef BOMB_H
#define BOMB_H
#include "sprite.h"
#include "../physics_object.h"
#include "../animation.h"
#include "tile_map.h"

#include <QPointF>
#include <QPainter>
#include <QGraphicsItem>
#include <QObject>

class Bomb : public Sprite, public PhysicsObject {
Q_OBJECT
public:
    Bomb(QGraphicsItem *parent, TileMap* tile_map, QGraphicsItem *owner, Animation flying, Animation explosing);
	void process(double delta) override;
	QPointF velocity;
	QPainterPath shape() const override;
	
signals:
	void exploded(Bomb* bomb);
	void animation_finished(Bomb* bomb);

private:
	TileMap* tile_map;
    bool collided;
    QGraphicsItem * owner;
};
#endif
