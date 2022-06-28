#include "scene.h"
Scene::Scene(SceneManager *manager, QObject *parent): QGraphicsScene(parent) {
	this->manager = manager;
}