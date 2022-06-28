#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QObject>

class Scene : public QGraphicsScene {
    Q_OBJECT
public:
	Scene(QObject *parent);
    virtual void enter() = 0;
};
#endif
