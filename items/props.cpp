#include "props.h"
#include <QVariant>
#include <QRectF>
#include <QObject>
#include <QDebug>
#include <QtGlobal>
#include <QGraphicsSceneMouseEvent>

QPainterPath Ui::shape() const {
    QPainterPath p;
    p.addRect(this->boundingRect());
    return p;
}
Ui::Ui(QGraphicsItem *parent) : QGraphicsItem(parent) {
    left_ui[0] = new Sprite(this, *Animations::BOMB1, true);
    left_ui[1] = new Sprite(this, *Animations::BOMB2, true);
    left_ui[2] = new Sprite(this, *Animations::BOMB3, true);
    pass = new Sprite(this, *Animations::BOMB_PASS, true);
    pass->setPos(3 * 128, 20);
    QObject::connect(pass, &Sprite::mousePressed, this, [this](QGraphicsSceneMouseEvent* e){this->setPassed(true);});
    //left_word = new Sprite(nullptr, *Animations::START_BUTTON, true, "小炸弹", Qt::black, QFont(Fonts::default_font_family, 16, QFont::Normal));
    for (int i = 0; i < 3; i++){
        left_ui[i]->setPos(i * 128, 20);
        left_p[i] = new Sprite(static_cast<QGraphicsItem*>(this), *Animations::SELECT_BOMB, false);
        left_p[i]->setPos(i * 128, 100);
        QObject::connect(left_ui[i], &Sprite::mousePressed, this, [this, i](QGraphicsSceneMouseEvent* e){this->setCurrentBomb(i);});
    }
    setCurrentBomb(0);
}

bool Ui::isPassed() {return passed;}
void Ui::setPassed(bool passed) {
    this->passed = passed;
    if (passed) {
        this->pass->hide();
    } else this->pass->show();
}

int Ui::getCurrentBomb() {
    return current_bomb;
}
QString Ui::getCurrentBombName() {
    if (current_bomb == 0) return "normal";
    if (current_bomb == 1) return "attractive";
    return "repulsive";
}

void Ui::setCurrentBomb(int x) {
    for (int i = 0; i < 3; i++) left_p[i]->hide();
    left_p[x] -> show();
    current_bomb = x;
}
void Ui::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
    return;
}

QRectF Ui::boundingRect() const {
    return QRectF(0, 0, 1, 1);
}
