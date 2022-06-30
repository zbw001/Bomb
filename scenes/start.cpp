#include "start.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QDebug>
#include <QPointF>
#include <QPixmap>
#include <QRect>
#include "scene_manager.h"
#include "items/sprite.h"
#include "../globals.h"

StartScene::StartScene(SceneManager* manager) : Scene(manager) {
    this->background = new Sprite(nullptr, *Animations::BACKGROUND, false);
    this->background->setScale(0.48);
    this->addItem(background);

    //assert(Animations::START_BUTTON);
    this->button = new Sprite(nullptr, *Animations::START_BUTTON, true, "开始游戏", Qt::white, QFont(Fonts::default_font_family, 50, QFont::Normal));
    //qDebug() << this->button->boundingRect();
    QObject::connect(this->button, &Sprite::mousePressed, [manager](QGraphicsSceneMouseEvent* e) {manager->change_scene("game");});
    button->setPos((QPointF(Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT) - QPointF(Consts::START_BUTTON_WIDTH, Consts::START_BUTTON_HEIGHT)) / 2);
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    this->addItem(button);
    this->setSceneRect(QRect(0, 0, Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT));

    manager->getView()->setSceneRect(this->sceneRect());
    manager->getView()->fitInView(QRect(0, 0, Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT));
}

StartScene::~StartScene() {
    delete button;
}
