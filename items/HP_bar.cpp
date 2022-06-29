#include "../globals.h"
#include "HP_bar.h"

HPBar::HPBar(QGraphicsItem * parent) : 
    Sprite(parent, *Animations::HPBAR_BACKGROUND, false, false) {
    bar = new Sprite(this, *Animations::HPBAR_BAR, false, false);
}

HPBar::~HPBar() {
	delete bar;
}

void HPBar::setHP(int HP) {
    bar->setScale(double(HP) / Consts::MAX_HP);
}
