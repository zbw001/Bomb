#include "sprite.h"

// 自身只是一个背景
class HPBar : public sprite {
public:
    HPBar(QGraphicsItem *parent);
	~HPBar();
	void setHP(int HP);
private:
	ImageRect *bar;
};
