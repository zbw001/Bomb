#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QHash>
#include "../items/tile_map.h"
#include "scene.h"
#include "../items/character.h"

class GameScene: public Scene {
    Q_OBJECT
private:
    TileMap* tile_map;
    QHash<int, QHash<int, Character*> > characters;
public:
    Q_INVOKABLE GameScene(SceneManager* manager);
    ~GameScene();
};

#endif
