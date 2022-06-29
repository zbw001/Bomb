#ifndef HP_BAR_H
#define HP_BAR_H
#include "sprite.h"
#include <QObject>

// 自身只是一个背景
class HPBar : public Sprite {
Q_OBJECT
public:
    HPBar(QGraphicsItem *parent);
	~HPBar();
	void setHP(int HP);
private:
	Sprite *bar;
};
#endif
