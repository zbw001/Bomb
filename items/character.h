#ifndef CHARACTER_H
#define CHARACTER_H
#include "sprite.h"
#include "../physics_object.h"
#include "HP_bar.h"
#include "tile_map.h"
#include <QString>
#include <QMap>
#include <QObject>

class Character : public Sprite, public PhysicsObject {
Q_OBJECT
public:
    Character(QGraphicsItem *parent, TileMap* tile_map);
	~Character();
	void process(double delta);
	QPointF velocity;
	QMap<QString, int> inventory;
    void setHP(int HP);
	int HP();
private:
	int _HP;
	HPBar* HP_bar;
	TileMap* tile_map;
};
#endif
