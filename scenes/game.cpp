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

GameScene::GameScene(SceneManager* manager) : Scene(manager) {
    this->setSceneRect(QRect(-1600, -900, 3200, 1800));
	this->tile_map = new TileMap(nullptr);
    characters[0][0] = new Character(nullptr, tile_map);
	this->addItem(characters[0][0]);
    this->addItem(tile_map);
    manager->getView()->setSceneRect(this->sceneRect());
	manager->getView()->fitInView(this->sceneRect());
}

GameScene::~GameScene() {
    QHashIterator<int, QHash<int, Character*> > i(this->characters);
    while (i.hasNext()) {
        QHashIterator<int, Character*> j(i.value());
        while (j.hasNext()) {
            delete j.value();
            j.next();
        }
        i.next();
    }
	delete tile_map;
}
