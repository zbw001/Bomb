#include "scene_manager.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QMap>
#include <QMetaObject>
#include "../globals.h"

SceneManager::SceneManager() {}
void SceneManager::init() {
    view = new QGraphicsView();
	current_scene = nullptr;
    change_scene(Scenes::init_scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setFixedSize(Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT);
	view -> show();
}
SceneManager::~SceneManager() {
	if (current_scene) delete current_scene;
	delete view;
}
void SceneManager::change_scene(QString scene_name) {
	//assert(Animations::START_BUTTON);
    QGraphicsScene* old = current_scene;
    current_scene = qobject_cast<QGraphicsScene*>(Scenes::scenes[scene_name].newInstance(Q_ARG(SceneManager*, this)));
    view->setScene(current_scene);
    //view->setSceneRect(current_scene->sceneRect());
    if (old) delete old;
}
QGraphicsView* SceneManager::getView() {
	return view;
}
