#include "tile_map.h"
#include <QVariant>
#include <QRectF>
#include <QObject>
#include <QDebug>
#include <QtGlobal>
#include <stdlib.h>
#include <algorithm>

QPainterPath TileMap::shape() const {
    return QPainterPath();
}

void TileMap::make_map1() {
    for(int i=0;i<Consts::TILEMAP_WIDTH;i++) {
        for(int j=0;j<Consts::TILEMAP_HEIGHT;j++) {
            if(j<=27&&j>=20) setBlock(i,j,2);
        }
    }
}

void swap(int &x,int &y) {
    int t=x;x=y;y=t;
}
int max(int x,int y) {
    return x>y?x:y;
}

TileMap::TileMap(QGraphicsItem *parent) : QGraphicsItem(parent) {

    int maph[100],mapf[100][100];
    memset(maph,0,sizeof(maph));
    memset(mapf,0,sizeof(mapf));
    maph[0]=10,maph[Consts::TILEMAP_WIDTH-1]=10;
    for(int i=1;i+1<Consts::TILEMAP_WIDTH;i++) {
        if(rand()%4==0) maph[i]=-1;
    }
    for(int i=1;i<Consts::TILEMAP_WIDTH/2;i++) {
        maph[i]+=maph[i-1];
    }
    for(int i=Consts::TILEMAP_WIDTH-2;i>=Consts::TILEMAP_WIDTH/2;i--) {
        maph[i]+=maph[i+1];
    }
    for(int i=0;i<Consts::TILEMAP_WIDTH;i++) {
        for(int j=27;j>=27-maph[i]+1;j--) mapf[i][j]=1;
    }
    for(int i=0;i<Consts::TILEMAP_WIDTH;i++) {
        for(int j=0;j<Consts::TILEMAP_HEIGHT;j++) if(mapf[i][j]) {
            int fl=0,fr=0,fu=0;
            if(i==0||mapf[i-1][j]==0) fl=1;
            if(i+1==Consts::TILEMAP_WIDTH||mapf[i+1][j]==0) fr=1;
            if(j==0||mapf[i][j-1]==0) fu=1;
            int tp=4;
            if(fl&&fr&&fu) tp=9;
            else if(fl&&fr) tp=10;
            else if(fl&&fu) tp=11;
            else if(fl) tp=3;
            else if(fr&&fu) tp=2;
            else if(fr) tp=5;
            else if(fu) tp=1;
            setBlock(i,j,tp);
        }
    }
    int flag[100];
    memset(flag,0,sizeof(flag));
    for(int i=0;i<7;i++) {
        int L=Consts::TILEMAP_WIDTH/4,R=L*3;
        int getl=rand()%(R-L+1)+L,getr=rand()%(R-L+1)+L;
        if(getl>getr) swap(getl,getr);
        int y=max(maph[getl],maph[getr])+rand()%10+1;
        while(flag[y]) {
            y=max(maph[getl],maph[getr])+rand()%10+1;
        }
        flag[y]=1;
        for(int x=getl;x<=getr;x++) setBlock(x,27-y+1,7);
    }
/*    for (int i = 0; i < Consts::TILEMAP_WIDTH; i++) {
        for (int j = 0; j < Consts::TILEMAP_HEIGHT; j++) {
            if (j == 27) {
                setBlock(i, j, 1);
            }
        }
    }*/
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
