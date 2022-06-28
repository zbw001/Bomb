#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "scene.h"

class GameScene: public Scene {
Q_OBJECT
public:
    GameScene();
    void enter();
};