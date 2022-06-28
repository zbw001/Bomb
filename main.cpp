#include "mainwindow.h"
#include "scenes/scene.h"
#include "scenes/game.h"
#include "scenes/over.h"
#include "scenes/start.h"
#include "scenes/SceneManager.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <string>
#include <QGraphicsView>
#include <map>
#include <QObject>

std::map<std::string, Scene*> scenes;
const std::string init_scene = "start";



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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    scenes["start"] = new StartScene();
    //scenes["game"] = new GameScene();
    //scenes["over"] = new OverScene();
    scene_manager = new SceneManager();
    scene_manager->init();
    return a.exec();
}
