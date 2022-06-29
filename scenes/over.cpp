#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QObject>
#include "../items/sprite.h"
#include "over.h"


OverScene::OverScene(SceneManager* manager) : Scene(manager) {
	this->setSceneRect(QRect(0, 0, 1600, 900));
    
    
    button = new Sprite(nullptr, *Animations::START_BUTTON, true, true, "重新开始");
    button->setPos(350, 400);
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    QObject::connect(button, &Sprite::mousePressed, [manager](QGraphicsSceneMouseEvent* e) {manager->change_scene("start");});
    this->addItem(button);
    manager->getView()->setSceneRect(this->sceneRect());
}
