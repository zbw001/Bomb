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
    //assert(Animations::START_BUTTON);
    this->button = new Sprite(nullptr, *Animations::START_BUTTON, true, true, "开始游戏", Qt::black, QFont(Fonts::default_font_family, 16, QFont::Normal));
    qDebug() << this->button->boundingRect();
    QObject::connect(this->button, &Sprite::mousePressed, [manager](QGraphicsSceneMouseEvent* e) {manager->change_scene("game");});
    button->setPos(350, 250);
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    this->setSceneRect(Consts::SCENE_RECT);
    this->addItem(button);
    QGraphicsView* view2 = manager->getView();
    view2->setFixedSize(Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT);
}

StartScene::~StartScene() {
    delete button;
}
