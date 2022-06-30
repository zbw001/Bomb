#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QObject>
#include "scene_manager.h"
class Scene : public QGraphicsScene {
Q_OBJECT
	public:
		Scene(SceneManager *manager, QObject *parent=nullptr);
    protected:
		SceneManager * manager;
};
#endif
