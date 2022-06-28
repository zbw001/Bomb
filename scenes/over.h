#include <QApplication>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QPushButton>
#include <QTimer>
#include <QObject>
#include "scene_manager.h"

class OverScene: public QGraphicsScene {
    Q_OBJECT
public:
    Q_INVOKABLE OverScene(SceneManager* manager);
};