#include "physics_manager.h"

PhysicsObject::PhysicsObject() {
	physics_manager->addObject(this);
}

PhysicsObject::~PhysicsObject() {
	physics_manager->removeObject(this);
}

void PhysicsObject::setProcessEnabled(bool enabled) {
	this->enabled = enabled;
}

bool PhysicsObject::isProcessEnabled() {
	return this->enabled;
}