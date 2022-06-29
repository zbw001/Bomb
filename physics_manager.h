#ifdef DEFINE_GLOBALS
#define EXTERN
#else
#define EXTERN extern
#endif

#include "physics_object.h"
#include <vector>
#include <QTimerEvent>
#include <QList>
#include <QObject>

class PhysicsManager : public QObject {
	Q_OBJECT
	private:
		int timer;
		double delta;
		QList<PhysicsObject*> objects;
	public:
		void addObject(PhysicsObject *object);
		void removeObject(PhysicsObject *object);
		PhysicsManager();
		~PhysicsManager();
	protected:
    	void timerEvent(QTimerEvent *event) override;
};

EXTERN PhysicsManager* physics_manager;
