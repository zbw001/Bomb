#include "start.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>
#include <QDebug>
#include "SceneManager.h"
//extern SceneManager
extern SceneManager* scene_manager;
StartScene::StartScene() : Scene(nullptr) {
    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(0,0,100,100);
    rect->setPos(400,300);
    rect->setFlag(QGraphicsRectItem::ItemIsFocusable);
    rect->setFocus();
    this->setSceneRect(0,0,800,600);
    this->addItem(rect);
}
void StartScene::enter(){
    QGraphicsView* view2=scene_manager->getView();
    view2->setFixedSize(800,600);
}

