#include "../globals.h"
#include "HP_bar.h"
#include <QPointF>

HPBar::HPBar(QGraphicsItem * parent) : 
    Sprite(parent, *Animations::HPBAR_BACKGROUND, false) {
    bar = new Sprite(this, *Animations::HPBAR_BAR, false);
    bar->setPos(QPointF(Consts::HPBAR_BACKGROUND_WIDTH - Consts::HPBAR_BAR_WIDTH, 1));
}

HPBar::~HPBar() {
	delete bar;
}

void HPBar::setHP(int HP) {
    //qDebug() << HP;
    if (HP == 0) bar->hide();
    else bar->setAnimation("default", Animations::HPBAR_BAR->crop(Consts::HPBAR_BAR_WIDTH * (1.0 * HP / Consts::MAX_HP), Consts::HPBAR_BAR_HEIGHT));
}
