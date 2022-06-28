#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <string>
class SceneManager : public QObject {
    Q_OBJECT
private:
    QGraphicsView *view;
public:
    SceneManager();
    ~SceneManager();
    QGraphicsView* getView();
    void change_scene(std::string scene_name);
};
#endif