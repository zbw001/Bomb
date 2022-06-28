#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QDebug>
#include "game.h"
#include "../items/tile_map.h"
#include "../items/character.h"

const int height=600;
const int width=800;
const int siz=10;//每个方块的大小
GameScene::GameScene(SceneManager* manager) : Scene(manager) {
    this->setSceneRect(0,0,800,600);
	QGraphicsView* view2=manager->getView();
    view2->setFixedSize(800,600);
    /*Person * red_person = new Person();
    Person * blue_person = new Person();
    red_person->setRect(0,0,100,100);
    blue_person->setRect(0,0,100,100);
    red_person->setPos(400,100);
    blue_person->setPos(400,600);
    this->addItem(red_person);
    this->addItem(blue_person);*/
    this->tile_map = new TileMap();
    this->addItem(p->get_map());
}

GameScene::~GameScene() {
	delete tile_map;
}