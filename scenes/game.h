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
#include <QPair>
#include <QPoint>
#include "../items/tile_map.h"
#include "scene.h"
#include "../items/character.h"
#include "../items/bomb.h"

enum GameState {
    WAITING_FOR_PLAYER,
    PLAYING_ANIMATION
};

class GameScene: public Scene {
    Q_OBJECT
private:
    GameState state;
    TileMap* tile_map;
    QHash<int, QHash<int, Character*> > characters;
    QPair<int, int> cur_character_id;
    Character *cur_character;
    Bomb* createBomb();
public:
    Q_INVOKABLE GameScene(SceneManager* manager);
    ~GameScene();
public slots:
    void bombExploded(Bomb *bomb);
};

#endif
