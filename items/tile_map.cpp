#include "tile_map.h"
#include <QVariant>
#include <QRectF>
#include <QObject>
#include <QDebug>
#include <QtGlobal>

QPainterPath TileMap::shape() const {
    return QPainterPath();
}

TileMap::TileMap(QGraphicsItem *parent) : QGraphicsItem(parent) {
    for (int i = 0; i < Consts::TILEMAP_WIDTH; i++) {
        for (int j = 0; j < Consts::TILEMAP_HEIGHT; j++) {
            if (j == 27) {
                setBlock(i, j, 1);
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
    //assert(x >= 0 && x < Consts::TILEMAP_WIDTH);
    //assert(y >= 0 && y < Consts::TILEMAP_HEIGHT);
    return block_type[QPair<int,int>(x, y)];
}

void TileMap::setBlock(int x, int y, int b) {
    //assert(x >= 0 && x < Consts::TILEMAP_WIDTH);
    //assert(y >= 0 && y < Consts::TILEMAP_HEIGHT);
    if (sprites[QPair<int,int>(x, y)]) delete sprites[QPair<int,int>(x, y)];
    block_type[QPair<int,int>(x, y)] = b;
    sprites[QPair<int,int>(x, y)] = nullptr;
    if (b) {
        sprites[QPair<int,int>(x, y)] = new Sprite(static_cast<QGraphicsItem*>(this), *Animations::BLOCKS[b], false);
        sprites[QPair<int,int>(x, y)]->setData(0, QVariant("block"));
        sprites[QPair<int,int>(x, y)]->setPos(x * Consts::BLOCK_SIZE, y * Consts::BLOCK_SIZE);
    }
}

bool TileMap::collides_with_rect(QRectF rect) {
    double lx = rect.left(), rx = rect.right();
    double ly = rect.top(), ry = rect.bottom();
    for (int bx = qMax(0, int (lx / Consts::BLOCK_SIZE - 2)); bx <= rx / Consts::BLOCK_SIZE + 2; bx++) {
        for (int by = qMax(0, int (ly / Consts::BLOCK_SIZE - 2)); by <= ry / Consts::BLOCK_SIZE + 2; by++) {
            if (block_type[QPair<int,int>(bx, by)]) {
                if (sprites[QPair<int,int>(bx, by)]->sceneBoundingRect().intersects(rect)) {
                    //qDebug() << rect << " " << sprites[QPair<int,int>(bx, by)]->sceneBoundingRect();
                    return true;
                }
            }
        }
    }
    return false;
}

double TileMap::dis_to_ground(QRectF rect) {
    double lx = rect.left(), rx = rect.right();
    double ly = rect.top(), ry = rect.bottom();
    //qDebug() << rect;
    double ret = 10000;

    for (int bx = qMax(0, int (lx / Consts::BLOCK_SIZE - 2)); bx <= rx / Consts::BLOCK_SIZE + 2; bx++) {
        for (int by = qMax(0, int (ly / Consts::BLOCK_SIZE - 2)); by <= ry / Consts::BLOCK_SIZE + 2; by++) {
            if (block_type[QPair<int,int>(bx, by)]) {
                //qDebug() << bx << " " << by;
                //qDebug() << (sprites[QPair<int,int>(bx, by)] != nullptr);
                QRectF brect = sprites[QPair<int,int>(bx, by)]->sceneBoundingRect();
                //qDebug() <<sprites[QPair<int,int>(bx, by)]->sceneBoundingRect();
                if (qAbs(brect.top() - rect.bottom()) < Consts::EPS) {
                    if (qMin(brect.right(), rect.right()) - qMax(brect.left(), rect.left()) > Consts::EPS)
                        ret = qMin(ret, rect.bottom() - brect.top());
                }
            }
        }
    }
    //qDebug() << ret;
    return ret;
}

QRectF TileMap::boundingRect() const {
    return QRectF(0, 0, Consts::TILEMAP_WIDTH * Consts::BLOCK_SIZE, Consts::TILEMAP_HEIGHT * Consts::BLOCK_SIZE);
}

void TileMap::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem *option,
                          QWidget *widget) {
    return;
}

Sprite* TileMap::getBlockItem(int x, int y) {
    return sprites[QPair<int,int>(x, y)];
}
