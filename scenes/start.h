#ifndef START_H
#define START_H
#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "scene.h"

class StartScene: public Scene {
Q_OBJECT
public:
    StartScene();
    void enter();
};

#endif
