#include <QTimer>
#include <QPoint>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QDebug>
#include <cmath>
#include "game.h"
#include "../items/tile_map.h"
#include "../items/character.h"
#include "../globals.h"

Bomb* GameScene::createBomb() {
    Bomb* bomb = new Bomb(nullptr, tile_map);
    QObject::connect(bomb, &Bomb::exploded, this, &GameScene::bombExploded);
    return bomb;
}

double getLength(QPointF p) {
    return sqrt(p.x() * p.x() + p.y() * p.y());
}

void GameScene::bombExploded(Bomb *bomb) {
    // 炸弹破坏造成破坏
    for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
        for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
            Character *c = characters[i][j];
            if (!c->isDead()) {
                double dis = getLength(c->center() - bomb->center());
                double strength = 2 * atan(Consts::CHARACTER_WIDTH / 2.0 / dis) / 2 / M_PI;
                c->velocity += (Consts::K_KNOCK * strength) * ((c->center() - bomb->center()) / dis);
                c->hurt(int(Consts::K_HURT * strength));
            }
        }
    }
}

QPair<int,int> _next(QPair<int,int> pi) {
	pi.second ++;
	if (pi.second >= Consts::NUM_CHARACTERS_PER_PLAYER) {
		pi.second = 0;
		pi.first ++;
	}
	return pi;
}

GameScene::GameScene(SceneManager* manager) : Scene(manager) {
    this->setSceneRect(QRect(- Consts::GAME_SCENE_WIDTH * 0.5, - Consts::GAME_SCENE_HEIGHT * 0.5, Consts::GAME_SCENE_WIDTH * 2, Consts::GAME_SCENE_HEIGHT * 2));
	this->tile_map = new TileMap(nullptr);
    this->addItem(tile_map);
	for (int player_id = 0; player_id < Consts::NUM_PLAYERS; player_id++) {
		for (int character_id = 0; character_id < Consts::NUM_CHARACTERS_PER_PLAYER; character_id ++) {
			characters[player_id][character_id] = new Character(nullptr, tile_map);
            QPoint p = QPoint(700 + character_id * 100, 300);
            if (player_id == 0) p.setX(- p.x());
            p = p + QPoint(Consts::GAME_SCENE_WIDTH / 2, Consts::GAME_SCENE_HEIGHT / 2);
			characters[player_id][character_id]->setPos(p - QPoint(Consts::CHARACTER_WIDTH / 2, Consts::CHARACTER_HEIGHT / 2));
            this->addItem(characters[player_id][character_id]);
        }
	}
    state = GameState::WAITING_FOR_PLAYER;
    cur_character_id = QPair<int, int>(0, 0);
    cur_character = characters[0][0];
    // 纯纯的调试语句
    Bomb* _bomb = createBomb();
    //_bomb->setPos(_bomb->pos() + QPoint(1400 + 3200, -500 + 1800));
    this->addItem(_bomb);
    manager->getView()->setSceneRect(this->sceneRect());
    manager->getView()->fitInView(QRect(0, 0, Consts::GAME_SCENE_WIDTH, Consts::GAME_SCENE_HEIGHT));
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
