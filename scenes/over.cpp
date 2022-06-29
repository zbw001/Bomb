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
	this->setSceneRect(Consts::SCENE_RECT);
    
    
    button = new Sprite(nullptr, *Animations::START_BUTTON, true, true, "重新开始");
    button->setPos(350, 400);
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    QObject::connect(button, &Sprite::mousePressed, [manager](QGraphicsSceneMouseEvent* e) {manager->change_scene("start");});
    this->addItem(button);

    QGraphicsView* view2 = manager->getView();
    view2->setFixedSize(Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT);
}
