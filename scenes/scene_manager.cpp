#include "scene_manager.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QMap>
#include <QMetaObject>

extern QMap<QString, QMetaObject> scenes;
extern const QString init_scene;

SceneManager::SceneManager() {}
void SceneManager::init() {
    view = new QGraphicsView();
	current_scene = nullptr;
    change_scene(init_scene);
    view -> setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view -> show();
}
SceneManager::~SceneManager() {
	if (current_scene) delete current_scene;
	delete view;
}
void SceneManager::change_scene(QString scene_name) {
	if (current_scene) delete current_scene;
	current_scene = qobject_cast<QGraphicsScene*>(scenes[scene_name].newInstance(Q_ARG(SceneManager*, this)));
    view->setScene(current_scene);
}
QGraphicsView* SceneManager::getView() {
	return view;
}
