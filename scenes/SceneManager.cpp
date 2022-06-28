#include "SceneManager.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <string>
#include <map>
#include "scene.h"
extern std::map<std::string, Scene*> scenes;
extern const std::string init_scene = "start";
SceneManager::SceneManager() {}
void SceneManager::init() {
    view = new QGraphicsView();
    change_scene(init_scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> show();
}
SceneManager::~SceneManager() {
	delete view;
}
void SceneManager::change_scene(std::string scene_name) {
	scenes[scene_name]->enter();
    view->setScene(scenes[scene_name]);
}
QGraphicsView* SceneManager::getView() {
	return view;
}
