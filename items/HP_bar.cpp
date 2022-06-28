#include "../consts.h"
#include "HP_bar.h"

HPBar::HPBar(QGraphicsItem * parent) : 
	ImageRect(parent, "../" + HPBAR_BACKGROUND_IMAGE, "", HPBAR_WIDTH, HPBAR_HEIGHT, false) {
	Bar = new ImageRect(this, "../" + HPBAR_BAR_IMAGE, "", HPBAR_WIDTH, HPBAR_HEIGHT, false);
}

HPBar::~HPBar() {
	delete Bar;
}

void HPBar::setHP(int HP) {
	bool implemented = false;
	assert(implemented);
}
