#ifndef TILEMAP_H
#define TILEMAP_H
#include<QGraphicsPixmapItem>
#include<QGraphicsRectItem>
class TileMap{
private:
    QGraphicsRectItem *fmap[105][105];
public:
    QGraphicsRectItem *main_map;
    int vis[105][105];
    TileMap();
    ~TileMap();
    bool check(QGraphicsRectItem* rect);
    QGraphicsRectItem* get_map();
    bool collides_with_rect(QGraphicsRectItem *rect);
    bool is_on_ground(QGraphicsRectItem *rect);
};
#endif