#include <QTimer>
#include <QPoint>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QPainterPath>
#include <QPointF>
#include <QDebug>
#include <cmath>
#include <QCursor>
#include <QLineF>
#include <QGraphicsLineItem>
#include "game.h"
#include <QPen>
#include "../items/tile_map.h"
#include "../items/character.h"
#include "../globals.h"
#include "../items/props.h"
Bomb* GameScene::createBomb(QGraphicsItem* character, QString bomb_type) {
    Bomb* bomb = nullptr;
    if (bomb_type == "normal") {
        bomb = new Bomb(nullptr, tile_map, character, *Animations::BOMB1, *Animations::EXPLOSION1);
        QObject::connect(bomb, &Bomb::exploded, this, [this, bomb_type](Bomb *bomb){this->bombExploded(bomb, bomb_type);});
    }
    if (bomb_type == "attractive") {
        bomb = new Bomb(nullptr, tile_map, character, *Animations::BOMB2, *Animations::EXPLOSION2);
        QObject::connect(bomb, &Bomb::exploded, this, [this, bomb_type](Bomb *bomb){this->bombExploded(bomb, bomb_type);});
    }
    if (bomb_type == "repulsive") {
        bomb = new Bomb(nullptr, tile_map, character, *Animations::BOMB3, *Animations::EXPLOSION3);
        QObject::connect(bomb, &Bomb::exploded, this, [this, bomb_type](Bomb *bomb){this->bombExploded(bomb, bomb_type);});
    }
    return bomb;
}

double getLength(QPointF p) {
    return sqrt(p.x() * p.x() + p.y() * p.y());
}

void GameScene::bombExploded(Bomb *bomb, QString bomb_type) {
    // 炸弹破坏造成破坏
    if (bomb_type == "normal") {
        for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
            for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
                Character *c = characters[i][j];
                if (!c->isDead()) {
                    double dis = getLength(c->center() - bomb->center());
                    double strength = 2 * atan(Consts::CHARACTER_WIDTH / 2.0 / dis) / M_PI;
                    c->velocity += (Consts::K_KNOCK * strength) * ((c->center() - bomb->center()) / dis);
                    if (getLength(c->velocity) > Consts::EPS) c->setAnimation("hurt");
                    c->hurt(int(Consts::K_HURT * strength));
                }
            }
        }
        int _ = int (Consts::BLOCK_DAMAGE_DISTANCE / Consts::BLOCK_SIZE) + 3;
        for (int i = int(bomb->center().x()) / Consts::BLOCK_SIZE - _; i <= int(bomb->center().x()) / Consts::BLOCK_SIZE + _ ; i++) {
            for (int j = int(bomb->center().y()) / Consts::BLOCK_SIZE - _; j <= int(bomb->center().y()) / Consts::BLOCK_SIZE + _ ; j++) {
                if (tile_map->getBlock(i, j)) {
                    QPointF p = tile_map->getBlockItem(i, j)->center();
                    if (getLength(bomb->center() - p) <= Consts::BLOCK_DAMAGE_DISTANCE) {
                        tile_map->setBlock(i, j, 0);
                    }
                }
            }
        }
    } else if (bomb_type == "attractive") {
        for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
            for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
                Character *c = characters[i][j];
                if (!c->isDead()) {
                    double dis = getLength(c->center() - bomb->center());
                    double strength = 2 * atan(Consts::CHARACTER_WIDTH * 8 / 2.0 / dis) / M_PI; // 吸引的话，需要缓慢的衰减
                    c->velocity -= (Consts::K_ATTRACTIVE * strength) * ((c->center() - bomb->center()) / dis);
                    if (getLength(c->velocity) > Consts::EPS) c->setAnimation("hurt");
                }
            }
        }
    } else {
        for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
            for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
                Character *c = characters[i][j];
                if (!c->isDead()) {
                    double dis = getLength(c->center() - bomb->center());
                    double strength = 2 * atan(Consts::CHARACTER_WIDTH / 2.0 / dis) / M_PI;
                    c->velocity += (Consts::K_REPULSIVE * strength) * ((c->center() - bomb->center()) / dis);
                    if (getLength(c->velocity) > Consts::EPS) c->setAnimation("hurt");
                }
            }
        }
    }
}

QPair<int,int> _next(QPair<int,int> pi) {
    pi.first ++;
    if (pi.first >= Consts::NUM_PLAYERS) {
        pi.first = 0;
        pi.second ++;
	}
    if (pi.second >= Consts::NUM_CHARACTERS_PER_PLAYER) {
        pi.second = 0;
    }
	return pi;
}

void GameScene::process(double delta) {
    if (cursor_indicator) {
        this->removeItem(cursor_indicator);
        delete cursor_indicator;
        cursor_indicator = nullptr;
    }
    if (state == GameState::WAITING_FOR_KNOCKED_PLAYER || state == GameState::PLAYING_ANIMATION) {
        if (!ui->isPassed()) {
            ui->setPassed(true);
        }
    }
    if (state == 0 && ui->isPassed()) qDebug() << "process" << state << " " << ui->isPassed();
    if (state == GameState::WAITING_FOR_KNOCKED_PLAYER) {
        bool ok = true;
        for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
            for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
                if (characters[i][j]->isMoving() || !characters[i][j]->isAnimationFinished()) {
                    ok = false;
                }
            }
        }
        if (!ok) return;
        //qDebug() << "128" << _next_state;
        this->animationFinished(_next_state);
    }
    if (state != GameState::PLAYING_ANIMATION && cur_character->isDead()) {
        //qDebug() << "132" << GameState::WAITING_FOR_PLAYER_MOVE;
        this->animationFinished(GameState::WAITING_FOR_PLAYER_MOVE); return;
    }
    if (state == GameState::WAITING_FOR_PLAYER_ITEM) {
        // 暂不实现这一功能，直接跳过
        // qDebug() << "还未实现";
        this->animationFinished(GameState::WAITING_FOR_PLAYER_MOVE);
    }
    if (state == GameState::WAITING_FOR_PLAYER_BOMB || state == GameState::WAITING_FOR_PLAYER_ITEM || state == GameState::WAITING_FOR_PLAYER_MOVE) {
        //qDebug() << "qwq";
        QPoint _pos = manager->getView()->mapFromGlobal(QCursor::pos());
        QPointF cursorPos = manager->getView()->mapToScene(_pos);
        double d = getLength(cursorPos - this->cur_character->center());
        //qDebug() << this->cur_character->center() << " " << cursorPos;
        if ((state == GameState::WAITING_FOR_PLAYER_BOMB && d <= Consts::MAX_CURSOR_DISTANCE_BOMB) ||
            (state == GameState::WAITING_FOR_PLAYER_MOVE && d <= Consts::MAX_CURSOR_DISTANCE_MOVE) ||
            (state == GameState::WAITING_FOR_PLAYER_ITEM && d <= Consts::MAX_CURSOR_DISTANCE_ITEM)) {
            cursor_indicator = new QGraphicsItemGroup();
            QPointF velocity = Consts::K_V0 * (cursorPos - this->cur_character->center()), cur_pos = this->cur_character->center();
            // 一段应该长一点的
            const int D = 5;
            QPointF last_pos = cur_pos;
            for (int t = 0; t < Consts::FPS * 3; t ++) {
                velocity.setY(velocity.y() + Consts::GRAVITY * delta);
                cur_pos += delta * velocity;
                if (t % (2 * D) == 0) {
                    QGraphicsLineItem * i = new QGraphicsLineItem(QLineF(last_pos, cur_pos), cursor_indicator);
                    QPen pen(state == GameState::WAITING_FOR_PLAYER_BOMB ? Qt::red : Qt::blue);
                    pen.setWidth(5);
                    i->setPen(pen);
                    cursor_indicator->addToGroup(i);
                }
                if (t % D == 0) {
                    last_pos = cur_pos;
                }
            }
            this->addItem(cursor_indicator);
        }
    }
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QGraphicsScene::mousePressEvent(mouseEvent);
    if (state == GameState::WAITING_FOR_PLAYER_BOMB || state == GameState::WAITING_FOR_PLAYER_MOVE || state == GameState::WAITING_FOR_PLAYER_ITEM) {
        QPoint _pos = manager->getView()->mapFromGlobal(QCursor::pos());
        QPointF cursorPos = manager->getView()->mapToScene(_pos);
        double d = getLength(cursorPos - this->cur_character->center());
        if (state == GameState::WAITING_FOR_PLAYER_BOMB) {
            if (d <= Consts::MAX_CURSOR_DISTANCE_BOMB) {
                QPointF velocity = Consts::K_V0 * (cursorPos - this->cur_character->center()), cur_pos = this->cur_character->center();
                Bomb* bomb = createBomb(cur_character, this->ui->getCurrentBombName());
                bomb->setPos(cur_pos - QPointF(Consts::BOMB_WIDTH / 2.0, Consts::BOMB_HEIGHT / 2.0));
                bomb->velocity = velocity;
                this->addItem(bomb);
                state = GameState::PLAYING_ANIMATION;
                QObject::connect(bomb, &Bomb::destroyed, this, [this, bomb](){this->animationFinished(GameState::WAITING_FOR_KNOCKED_PLAYER); this->_next_state = WAITING_FOR_PLAYER_ITEM; QObject::disconnect(bomb, &Bomb::destroyed, this, nullptr);});
            } else if (ui->isPassed()) {
                //qDebug() << "passed";
                state = GameState::WAITING_FOR_PLAYER_ITEM;
            }
        }
        if (state == GameState::WAITING_FOR_PLAYER_MOVE) {
            if (d <= Consts::MAX_CURSOR_DISTANCE_MOVE) {
                QPointF velocity = Consts::K_V0 * (cursorPos - this->cur_character->center());
                cur_character->velocity += velocity;
                state = GameState::PLAYING_ANIMATION;
                cur_character->setAnimation("walk");
                Character *_ = cur_character;
                QObject::connect(_, &Character::stopped, this, [this, _](){this->animationFinished(GameState::WAITING_FOR_PLAYER_BOMB); QObject::disconnect(_, &Character::stopped, this, nullptr);});
            } else if (ui->isPassed()) {
                //qDebug() << "passed";
                state = GameState::WAITING_FOR_PLAYER_BOMB;
            }
        }
    }
}

void GameScene::animationFinished(GameState state) {
    //qDebug() << state << GameState::WAITING_FOR_PLAYER_MOVE;
    this->state = state;
    ui->setPassed(false);
    if (state == GameState::WAITING_FOR_PLAYER_MOVE) {
        this->cur_character->setCurrent(false);
        bool* all_dead = new bool[Consts::NUM_PLAYERS];
        for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
            all_dead[i] = true;
            for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
                if (!characters[i][j]->isDead()) {
                    all_dead[i] = false;
                    break;
                }
            }
        }
        if (all_dead[0] || all_dead[1]) {
            if (all_dead[0]) {
                Globals::winner = 1;
            } else Globals::winner = 0;
            manager->change_scene("over");
            delete[] all_dead;
            return;
        }
        delete[] all_dead;
        this->cur_character_id = _next(cur_character_id);
        while (characters[cur_character_id.first][cur_character_id.second]->isDead()) cur_character_id = _next(cur_character_id);
        this->cur_character = characters[cur_character_id.first][cur_character_id.second];
        this->cur_character->setCurrent(true);
    }
}

GameScene::GameScene(SceneManager* manager) : Scene(manager) {
    this->setSceneRect(QRect(- Consts::GAME_SCENE_WIDTH * 0.5, - Consts::GAME_SCENE_HEIGHT * 0.5, Consts::GAME_SCENE_WIDTH * 2, Consts::GAME_SCENE_HEIGHT * 2));
	this->tile_map = new TileMap(nullptr);
    this->background = new Sprite(nullptr, *Animations::BACKGROUND, false);
    this->background->setPos((QPointF(Consts::GAME_SCENE_WIDTH, Consts::GAME_SCENE_HEIGHT) - QPointF(Consts::BACKGROUND_WIDTH, Consts::BACKGROUND_HEIGHT)) / 2);
    this->addItem(background);
    this->addItem(tile_map);
    this->ui = new Ui(nullptr);
    this->addItem(ui);
	for (int player_id = 0; player_id < Consts::NUM_PLAYERS; player_id++) {
		for (int character_id = 0; character_id < Consts::NUM_CHARACTERS_PER_PLAYER; character_id ++) {
            characters[player_id][character_id] = new Character(nullptr, tile_map, player_id, character_id);
            QPoint p = QPoint(700 + character_id * 100, 0);
            if (player_id == 0) p.setX(- p.x());
            p = p + QPoint(Consts::GAME_SCENE_WIDTH / 2, Consts::GAME_SCENE_HEIGHT / 2);
			characters[player_id][character_id]->setPos(p - QPoint(Consts::CHARACTER_WIDTH / 2, Consts::CHARACTER_HEIGHT / 2));
            this->addItem(characters[player_id][character_id]);
        }
    }
    this->cursor_indicator = nullptr;
    state = GameState::WAITING_FOR_PLAYER_MOVE;
    cur_character_id = QPair<int, int>(0, 0);
    cur_character = characters[0][0];
    cur_character->setCurrent(true);

    manager->getView()->setSceneRect(this->sceneRect());
    manager->getView()->fitInView(QRect(0, 0, Consts::GAME_SCENE_WIDTH, Consts::GAME_SCENE_HEIGHT));
}

GameScene::~GameScene() {
    for (int i = 0; i < Consts::NUM_PLAYERS; i++) {
        for (int j = 0; j < Consts::NUM_CHARACTERS_PER_PLAYER; j++) {
            delete characters[i][j];
        }
    }
	delete tile_map;
    delete cursor_indicator;
    delete background;
    delete ui;
}
