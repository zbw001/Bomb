#include "tile_map.h"
const int height=600;
const int width=800;
const int siz=10;//每个方块的大小
TileMap::TileMap(){
    main_map = new QGraphicsRectItem();
    main_map->setRect(0,0,800,600);
    for (int i=1;i<=width/siz;i++){
        for (int j=1;j<=height/siz;j++){
            vis[i][j]=0;
            if (j==height/siz){
                fmap[i][j]=new QGraphicsRectItem(main_map);
                fmap[i][j]->setRect(0,0,10,10);
                fmap[i][j]->setPos((i-1)*siz,(j-1)*siz);
                //this->addItem(fmap[i][j]);
                vis[i][j]=1;
            }
        }
    }
    //scene->addItem(main_map);
 //   this->setPixmap(QPixmap("blablabla"));//输入文件路径
}
TileMap::~TileMap(){
    for (int i=1;i<=width/siz;i++){
        for (int j=1;j<=height/siz;j++){
            if (vis[i][j]){
                delete(fmap[i][j]);
                vis[i][j]=0;
                //this->removeItem(fmap[i][j]);
            }
        }
    }
    main_map->scene()->removeItem(main_map);
    delete(main_map);
}
bool TileMap::check(QGraphicsRectItem* rect){
    int fx1=rect->x(),fy1=rect->y(),fx2=rect->x()+50,fy2=rect->y()+50;
    for (int i=1;i<=width/siz;i++){
        for (int j=1;j<=height/siz;j++){
            if (vis[i][j]){
                int gx=(i-1)*siz,gy=(j-1)*siz;
                if (gx>=fx1&&gx<=fx2&&gy>=fy1&&gy<=fy2) return true;
                if (gx+siz>=fx1&&gx+siz<=fx2&&gy>=fy1&&gy<=fy2) return true;
                if (gx>=fx1&&gx<=fx2&&gy+siz>=fy1&&gy+siz<=fy2) return true;
                if (gx+siz>=fx1&&gx+siz<=fx2&&gy+siz>=fy1&&gy+siz<=fy2) return true;
            }
        }
    }
    return false;
}
QGraphicsRectItem* TileMap::get_map(){
    return main_map;
}
/*const int bomb_size;
void TileMap::bomb(QGraphicsRectItem* rect){
    int fx1=rect->x()-bomb_size,fy1=rect->y()-bomb_size,fx2=rect->x()+rect->width()+bomb_size,fy2=rect->y()+rect->height()+bomb_size;
    for (int i=1;i<=width/siz;i++){
        for (int j=1;j<=height/siz;j++){
            if (vis[i][j]){
                int gx=(i-1)*siz,gy=(j-1)*siz;
                bool flag=false;
                if (gx>=fx1&&gx<=fx2&&gy>=fy1&&gy<=fy2) flag=true;
                if (gx+siz>=fx1&&gx+siz<=fx2&&gy>=fy1&&gy<=fy2) flag=true;
                if (gx>=fx1&&gx<=fx2&&gy+siz>=fy1&&gy+siz<=fy2) flag=true;
                if (gx+siz>=fx1&&gx+siz<=fx2&&gy+siz>=fy1&&gy+siz<=fy2) flag=true;
                if (flag){
                    delete(fmap[i][j]);
                    vis[i][j]=0;
                }
            }
        }
    }    
}
*/
int min(int x,int y) {
    return x<y?x:y;
}

int max(int x,int y) {
    return x>y?x:y;
}

bool TileMap::collides_with_rect(QGraphicsRectItem *rect) {
    int lx=rect->x(),rx=rect->x()+rect->width();
    int ly=rect->y(),ry=rect->y()+rect->height();
    for(int i=1;i<=width/siz;i++) {
        for(int j=1;j<=height/siz;j++) {
            if(vis[i][j]) {
                int gx=(i-1)*siz,gy=(j-1)*siz;
                bool flag=false;
                if(max(lx,gx)<=min(rx,gx+siz)&&max(ly,gy)<=min(ry,gy+siz)) return true;
                if(flag) return true;
            }
        }
    }
    return false;
}

bool TileMap::is_on_ground(QGraphicsRectItem *rect) {
    return this->collides_with_rect(rect);
/*    int lx=rect->x(),rx=rect->x()+rect->width();
    int ly=rect->y(),ry=rect->y()+rect->height();
    for(int i=1;i<=width/siz;i++) {
        for(int j=1;j<=height/siz;j++) {
            if(vis[i][j]) {
                int gx=(i-1)*siz,gy=(j-1)*siz;
                bool flag=false;
                
                if(flag) return true;
            }
        }
    }
    return false;*/
}
