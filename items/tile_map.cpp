#include "tile_map.h"
#include <QRectF>
#include <QObject>
#include <QtGlobal>

QPainterPath TileMap::shape() const {
    return QPainterPath();
}

TileMap::TileMap(QGraphicsItem *parent) : QGraphicsItem(parent) {
    for (int i = 0; i < Consts::TILEMAP_WIDTH; i++) {
        for (int j = 0; j < Consts::TILEMAP_HEIGHT; j++) {
            sprites[QPoint(i, j)] = nullptr;
            block_type[QPoint(i, j)] = -1;
            if (j == 10) { 
                setBlock(i, j, 0);
            }
        }
    }
}

TileMap::~TileMap(){
    foreach (Sprite* s, sprites) {
        delete s;
    }
}

int TileMap::getBlock(int x, int y) {
    assert(x >= 0 && x < Consts::TILEMAP_WIDTH);
    assert(y >= 0 && y < Consts::TILEMAP_HEIGHT);
    return block_type[QPoint(x, y)];
}

void TileMap::setBlock(int x, int y, int b) {
    assert(x >= 0 && x < Consts::TILEMAP_WIDTH);
    assert(y >= 0 && y < Consts::TILEMAP_HEIGHT);
    if (sprites[QPoint(x, y)]) delete sprites[QPoint(x, y)];
    block_type[QPoint(x, y)] = b;
    sprites[QPoint(x, y)] = new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BLOCKS[b], true, false);
    sprites[QPoint(x, y)]->setPos(x * Consts::BLOCK_SIZE, y * Consts::BLOCK_SIZE);
}

bool TileMap::collides_with_rect(QRectF rect) {
    int lx = rect.left(), rx = rect.right();
    int ly = rect.top(), ry = rect.bottom();
    for (int bx = qMax(0, lx / Consts::BLOCK_SIZE - 2); bx <= rx / Consts::BLOCK_SIZE + 2; bx++) {
        for (int by = qMax(0, ly / Consts::BLOCK_SIZE - 2); by <= ry / Consts::BLOCK_SIZE + 2; by++) {
            if (block_type[QPoint(bx, by)] != -1) {
                if (sprites[QPoint(bx, by)]->boundingRect().intersects(rect)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool TileMap::is_on_ground(QRectF rect) {
    int lx = rect.left(), rx = rect.right();
    int ly = rect.top(), ry = rect.bottom();
    for (int bx = qMax(0, lx / Consts::BLOCK_SIZE - 2); bx <= rx / Consts::BLOCK_SIZE + 2; bx++) {
        for (int by = qMax(0, ly / Consts::BLOCK_SIZE - 2); by <= ry / Consts::BLOCK_SIZE + 2; by++) {
            if (block_type[QPoint(bx, by)] != -1) {
                if ((sprites[QPoint(bx, by)]->boundingRect().top() - rect.bottom() < Consts::EPS)) {
                    if (qMin(sprites[QPoint(bx, by)]->boundingRect().right(), rect.right()) - qMax(sprites[QPoint(bx, by)]->boundingRect().left(), rect.left()) > Consts::EPS)
                        return true;
                }
            }
        }
    }
    return false;
}

QRectF TileMap::boundingRect() const {
    return QRectF(0, 0, Consts::TILEMAP_WIDTH * Consts::BLOCK_SIZE, Consts::TILEMAP_HEIGHT * Consts::BLOCK_SIZE);
}

void TileMap::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
    return;
}
