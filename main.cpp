#include "scenes/game.h"
#include "scenes/over.h"
#include "scenes/start.h"
#include "scenes/scene_manager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QString>
#include <QGraphicsView>
#include <QMap>
#include <QObject>
#include <QFontDataBase>
#include <QMetaObject>
#define DEFINE_GLOBALS
#include "globals.h"
#include "physics_manager.h"

QMap<QString, QMetaObject> scenes;
const QString init_scene = "start";


/*
没有窗口，显示 QGraphicView。
所以对每个游戏界面，建一个 QGraphicScene。

开始界面，游戏界面，结束界面。

一个场景继承 scenes/scene.cpp 里面的 Scene 类
start -> 主界面
game -> 游戏界面
over -> 结束界面
*/

SceneManager * scene_manager;

void load_fonts() {
    int id = QFontDatabase::addApplicationFont("assets/像素Silver.ttf");
    Fonts :: default_font_family = QFontDatabase::applicationFontFamilies(id).at(0);
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    load_fonts();
    physics_manager = new PhysicsManager();
    scenes["start"] = StartScene :: staticMetaObject;
    scenes["game"] = GameScene :: staticMetaObject;
    //scenes["over"] = new OverScene();
    scene_manager = new SceneManager();
    scene_manager->init();
    return a.exec();
}
