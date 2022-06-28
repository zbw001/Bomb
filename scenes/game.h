#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "../items/tile_map.h"
#include "scene.h"

class GameScene: public Scene {
    Q_OBJECT
public:
    TileMap* tile_map;
    Q_INVOKABLE GameScene(SceneManager* manager);
    ~GameScene();
};

#endif