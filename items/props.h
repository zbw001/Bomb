#ifndef PROPS_H
#define PROPS_H
#include "sprite.h"
#include "../globals.h"
#include <QGraphicsItem>
#include <QMap>
#include <QPoint>
#include <QPair>
#include <QRectF>
#include <QObject>
class Ui : public QObject, public QGraphicsItem {
Q_OBJECT
private:
    Sprite* left_ui[3];
    Sprite* left_p[3];
    Sprite* pass;
    //Sprite* right_ui[3],right_p[3];
    int now_bomb;
public:
    Ui(QGraphicsItem *parent);
    ~Ui();
    int get_bomb();
    void change_bomb(int x);
    bool collides_with_rect(QRectF rect);
    double dis_to_ground(QRectF rect);
    int getBlock(int x, int y);
    void setBlock(int x, int y, int b);
    QRectF boundingRect() const override;

    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
#endif // PROPS_H
