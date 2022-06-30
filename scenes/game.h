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
#include <QGraphicsPathItem>
#include <QGraphicsItemGroup>
#include <QGraphicsSceneMouseEvent>
#include "../items/tile_map.h"
#include "scene.h"
#include "../items/character.h"
#include "../items/bomb.h"
#include "../physics_object.h"

enum GameState {
    WAITING_FOR_PLAYER_MOVE,
    WAITING_FOR_PLAYER_BOMB,
    WAITING_FOR_PLAYER_ITEM,
    PLAYING_ANIMATION
};

class GameScene: public Scene, PhysicsObject {
    Q_OBJECT
private:
    QGraphicsItemGroup* cursor_indicator;
    GameState state;
    TileMap* tile_map;
    QHash<int, QHash<int, Character*> > characters;
    QPair<int, int> cur_character_id;
    Character *cur_character;
    Bomb* createBomb(QGraphicsItem* character);
    Sprite* background;
public:
    Q_INVOKABLE GameScene(SceneManager* manager);
    void process(double delta) override;
    ~GameScene();
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
public slots:
    void bombExploded(Bomb *bomb);
    void animationFinished(GameState next_state);
};

#endif
