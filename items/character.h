#include "image_rect.h"
#include "../physics_object.h"
#include "../scenes/TileMap.h"
#include <QString>

class Character : public ImageRect, public PhysicsObject {
public:
    Character(QGraphicsItem *parent, TileMap* tile_map);
	~Character();
	void process(double delta);
	QPointF velocity;
	map<QString, int> inventory;
	void setHP();
	int HP();
private:
	int _HP;
	HPBar* HP_bar;
	TileMap* tile_map;
};