#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "scene.h"

class OverScene: public Scene {
Q_OBJECT
public:
    OverScene();
    void enter();
};