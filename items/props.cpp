#include "props.h"
#include <QVariant>
#include <QRectF>
#include <QObject>
#include <QDebug>
#include <QtGlobal>

QPainterPath Ui::shape() const {
    return QPainterPath();
}
//49,17,48
Ui::Ui(QGraphicsItem *parent) : QGraphicsItem(parent) {
    left_ui[0]= new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB,false);
    left_ui[1]= new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB2,false);
    left_ui[2]= new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB3,false);
    pass = new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB_PASS,true);
    pass->setPos(3 * 128, 20);
    //left_word[0] = new Sprite(nullptr, *Animations::START_BUTTON, true, "小炸弹", Qt::black, QFont(Fonts::default_font_family, 16, QFont::Normal));
    for (int i=0;i<=2;i++){
        //left_ui[i]->setData(0, QVariant("block"));
        left_ui[i]->setPos(i * 128, 20);
        left_p[i] = new Sprite(static_cast<QGraphicsItem*>(this), *Animations::SELECT_BOMB,false);
        left_p[i]->setPos(i * 128, 100);
        left_p[i]->setVisible(false);
    }
    left_p[0]->setVisible(true);
    now_bomb=0;
    /*right_ui[0]= new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB,false);
    right_ui[1]= new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB2,false);
    right_ui[2]= new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BOMB3,false);
    for (int i=0;i<=2;i++){
        //right_ui[i]->setData(0, QVariant("block"));
        right_ui[i]->setPos(46 * 48+i*128, 20);
    }*/
}

Ui::~Ui(){
    for (int i=0;i<=2;i++){
        delete(left_ui[i]);
        delete(left_p[i]);
        delete(pass);
    }
    /*foreach (Sprite* s, sprites) {
        delete s;
    }*/
}
int Ui::get_bomb(){
    return now_bomb;
}
void Ui::change_bomb(int x){
    left_p[now_bomb]->setVisible(false);
    left_p[x]->setVisible(false);
    now_bomb=x;
}
void Ui::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
    return;
}

int Ui::getBlock(int x, int y) {
    return 0;
}

void Ui::setBlock(int x, int y, int b) {
    return;
}

bool Ui::collides_with_rect(QRectF rect) {
    return true;
}

double Ui::dis_to_ground(QRectF rect) {
    return 100.0;
}
QRectF Ui::boundingRect() const {
    return QRectF(0, 0, 100,100);
}
