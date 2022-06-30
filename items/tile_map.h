#ifndef TILEMAP_H
#define TILEMAP_H

#include "sprite.h"
#include "../globals.h"
#include <QGraphicsItem>
#include <QMap>
#include <QPoint>
#include <QPair>
#include <QRectF>
#include <QObject>


class TileMap : public QObject, public QGraphicsItem {
Q_OBJECT
private:
    QHash<QPair<int,int>, Sprite *> sprites;
    QHash<QPair<int,int>, int> block_type;
    void make_map1();
public:
    TileMap(QGraphicsItem *parent);
    ~TileMap();
    bool collides_with_rect(QRectF rect);
    double dis_to_ground(QRectF rect);
    QPainterPath shape() const override;
    int getBlock(int x, int y);
    void setBlock(int x, int y, int b);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    Sprite* getBlockItem(int x, int y);
};

#endif
