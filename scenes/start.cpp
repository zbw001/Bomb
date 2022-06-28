#include "start.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QDebug>
#include <QPixmap>
#include "scene_manager.h"
#include "items/sprite.h"
#include "../globals.h"

StartScene::StartScene(SceneManager* manager) : Scene(manager) {
    this->button = new Sprite(nullptr, Animations::START_BUTTON, false, "开始游戏");
    QObject::connect(this->button, &Sprite::mousePressed, [manager](QGraphicsSceneMouseEvent* e) {manager->change_scene("game");});
    button->setPos(350, 250);
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    this->setSceneRect(0, 0, 800, 600);
    this->addItem(button);
    QGraphicsView* view2 = manager->getView();
    view2->setFixedSize(800, 600);
}

StartScene::~StartScene() {
    delete button;
}