#include "start.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <stdlib.h>


#include "/../items/sprite.h"
#include "over.h"
extern SceneManager* scene_manager;
OverScene::OverScene(SceneManager* manager) : Scene(manager) {
    this->setSceneRect(0,0,800,600);
    ImageRect * textshow = new ImageRect("../assets/game_ending.png", "游戏结束", 100, 400);
    textshow->setPos(100,100);
    this->addItem(textshow);
    
    ImageRect * button = new ImageRect("../assets/start_button.png", "重新游戏", 100, 100);
    button->setPos(350, 400);
    button->setFlag(QGraphicsRectItem::ItemIsFocusable);
    button->setFocus();
    button->set_event_callback("mouse_press", [scene_manager](QGraphicsSceneMouseEvent* e) {scene_manager->change_scene("start");});
    this->addItem(button);
}

void OverScene::enter() {
    QGraphicsView* view2=scene_manager->getView();
    view2->setFixedSize(800,600);
}