#ifndef START_H
#define START_H
#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "../items/sprite.h"
#include "scene.h"
#include "scene_manager.h"

class StartScene: public Scene {
    Q_OBJECT
public:
    Q_INVOKABLE StartScene(SceneManager* manager);
    ~StartScene();
private:
    Sprite* button;
    Sprite* background;
};

#endif
