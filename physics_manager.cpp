#include "physics_manager.h"
#include "globals.h"

PhysicsManager::PhysicsManager() : QObject(nullptr) {
	delta = 1000.0 / Consts::FPS;
	timer = QObject::startTimer(1000 / Consts::FPS);
}
void PhysicsManager::addObject(PhysicsObject *object) {
	objects.push_back(object);
}
void PhysicsManager::removeObject(PhysicsObject *object) {
	int ind = objects.lastIndexOf(object);
	if (ind == -1) {
		qDebug("ERR: 不能删除不存在的 PhysicsObject！");
		assert(ind != -1);
	}
	objects.erase(objects.begin() + ind);
}
void PhysicsManager::timerEvent(QTimerEvent *event) {
	for (auto object : objects) {
		if (object->isProcessEnabled()) {
			object->process(delta);
		}
	}
}
PhysicsManager::~PhysicsManager() {
	QObject::killTimer(timer);
}