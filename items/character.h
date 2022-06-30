#ifndef CHARACTER_H
#define CHARACTER_H
#include "sprite.h"
#include "../physics_object.h"
#include "HP_bar.h"
#include "tile_map.h"
#include <QString>
#include <QMap>
#include <QObject>
#include <QPointF>

class Character : public Sprite, public PhysicsObject {
Q_OBJECT
public:
    Character(QGraphicsItem *parent, TileMap* tile_map, int player_id, int character_id);
	~Character();
	void process(double delta);
	QPointF velocity;
	QMap<QString, int> inventory;
    void setHP(int HP);
	int HP();
    void hurt(int delta);
    bool isDead();
    void setCurrent(bool current);
    bool isMoving();
    bool isAnimationFinished();
private:
    int player_id, character_id;
    Sprite *mark;
    bool dead;
    bool current;
	int _HP;
	HPBar* HP_bar;
    TileMap* tile_map;
signals:
    void stopped();
};
#endif
