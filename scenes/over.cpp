#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QObject>
#include <QPointF>
#include "../items/sprite.h"
#include "../animation.h"
#include "over.h"
#include "../globals.h"


OverScene::OverScene(SceneManager* manager) : Scene(manager) {
    this->setSceneRect(QRect(0, 0, 1600, 900));
    this->background = new Sprite(nullptr, *Animations::BACKGROUND, false);
    this->background->setScale(0.48);
    this->addItem(background);
    this->text = new Sprite(nullptr, Animation(), false, Globals::winner == 0 ? "蓝方获胜" : "红方获胜", Qt::gray, QFont(Fonts::default_font_family, 200, QFont::Normal));
    this->addItem(this->text);
    button = new Sprite(nullptr, *Animations::START_BUTTON, true, "重新开始", Qt::white, QFont(Fonts::default_font_family, 50, QFont::Normal));
    button->setPos((QPointF(Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT) - QPointF(Consts::START_BUTTON_WIDTH, Consts::START_BUTTON_HEIGHT)) / 2 + QPointF(0, 200));
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    QObject::connect(button, &Sprite::mousePressed, [manager](QGraphicsSceneMouseEvent* e) {manager->change_scene("game");});
    this->addItem(button);
    this->setSceneRect(QRect(0, 0, Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT));
    manager->getView()->setSceneRect(this->sceneRect());
    manager->getView()->fitInView(QRect(0, 0, Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT));
}

OverScene::~OverScene() {
    delete this->text;
    delete this->button;
    delete this->background;
}
