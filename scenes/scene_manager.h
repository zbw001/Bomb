#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QString>

class SceneManager : public QObject {
    Q_OBJECT
private:
    QGraphicsView *view;
	QGraphicsScene *current_scene;
public:
    SceneManager();
    ~SceneManager();
    QGraphicsView* getView();
    void change_scene(QString scene_name);
    void init();
};
#endif
