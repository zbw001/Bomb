#ifndef PROPS_H
#define PROPS_H
#include "sprite.h"
#include "../globals.h"
#include <QGraphicsItem>
#include <QMap>
#include <QPoint>
#include <QPair>
#include <QRectF>
#include <QString>
#include <QObject>
class Ui : public QObject, public QGraphicsItem {
Q_OBJECT
private:
    Sprite* left_ui[3];
    Sprite* left_p[3];
    Sprite* pass;
    Sprite* left_word;
    int current_bomb;
    bool passed;
public:
    Ui(QGraphicsItem *parent);
    bool isPassed();
    void setPassed(bool passed);
    int getCurrentBomb();
    QString getCurrentBombName();
    void setCurrentBomb(int x);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
#endif // PROPS_H
