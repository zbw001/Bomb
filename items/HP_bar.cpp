#include "../globals.h"
#include "HP_bar.h"
#include <QPointF>

HPBar::HPBar(QGraphicsItem * parent) : 
    Sprite(parent, *Animations::HPBAR_BACKGROUND, false) {
    bar = new Sprite(this, *Animations::HPBAR_BAR, false);
    bar->setPos(QPointF(Consts::HPBAR_BACKGROUND_WIDTH - Consts::HPBAR_BAR_WIDTH, 0));
}

HPBar::~HPBar() {
	delete bar;
}

void HPBar::setHP(int HP) {
    bar->setScale(double(HP) / Consts::MAX_HP);
}
