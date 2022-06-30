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
#include <QMetaObject>
#define DEFINE_GLOBALS
#include "globals.h"
#include "physics_manager.h"
#include <QFileInfo>
#include <QFontDatabase>


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

void loadFonts() {
    int id = QFontDatabase::addApplicationFont(":/assets/像素Silver.ttf");
    Fonts :: default_font_family = QFontDatabase::applicationFontFamilies(id).at(0);
}

void loadAnimations() {
    Animations::CHARACTER_IDLE = new Animation(":/assets/character/idle.png", QSize(Consts::CHARACTER_WIDTH, Consts::CHARACTER_HEIGHT));
    Animations::CHARACTER_DIE = new Animation(2, false);
    Animations::BOMB = new Animation(":/assets/bomb/bomb.png", QSize(Consts::BOMB_WIDTH, Consts::BOMB_HEIGHT));
    Animations::BOMB2 = new Animation(":/assets/bomb/bomb2.png", QSize(Consts::BOMB_WIDTH, Consts::BOMB_HEIGHT));
    Animations::BOMB3 = new Animation(":/assets/bomb/bomb3.png", QSize(Consts::BOMB_WIDTH, Consts::BOMB_HEIGHT));
    Animations::SELECT_BOMB= new Animation(":/assets/bomb/select_bomb.png", QSize(Consts::BOMB_WIDTH, Consts::BOMB_HEIGHT));
    Animations::BOMB_PASS= new Animation(":/assets/bomb/pass.png", QSize(Consts::BOMB_WIDTH, Consts::BOMB_HEIGHT));
    Animations::START_BUTTON = new Animation(":/assets/start_button.png", QSize(Consts::START_BUTTON_WIDTH, Consts::START_BUTTON_HEIGHT));
    Animations::HPBAR_BACKGROUND = new Animation(":/assets/character/hp_background.png", QSize(Consts::HPBAR_BACKGROUND_WIDTH, Consts::HPBAR_BACKGROUND_HEIGHT));
    Animations::HPBAR_BAR = new Animation(":/assets/character/hp_bar.png", QSize(Consts::HPBAR_BAR_WIDTH, Consts::HPBAR_BAR_HEIGHT));
    Animations::BLOCKS[1] = new Animation(":/assets/blocks/dirt.png", QSize(Consts::BLOCK_SIZE, Consts::BLOCK_SIZE));
    Animations::EXPLOSION1 = new Animation(10, false);
    for (int i = 0; i < 50; i++)
        Animations::EXPLOSION1->addFrame(QString(":/assets/bomb/explosion1/1_") + QString::number(i) + ".png", QSize(Consts::EXPLOSION1_SIZE, Consts::EXPLOSION1_SIZE));
    Animations::CHARACTER_DIE->addFrame(":/assets/character/down.png", QSize(Consts::CHARACTER_WIDTH, Consts::CHARACTER_HEIGHT));
    Animations::CHARACTER_DIE->addFrame(":/assets/character/slide.png", QSize(Consts::CHARACTER_WIDTH, Consts::CHARACTER_HEIGHT));
    Animations::BACKGROUND = new Animation(":/assets/summer.png", QSize(Consts::BACKGROUND_WIDTH, Consts::BACKGROUND_HEIGHT));
    Animations::MARK = new Animation(":/assets/character/mark.png", QSize(Consts::MARK_SIZE, Consts::MARK_SIZE));
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    loadFonts();
    loadAnimations();
    physics_manager = new PhysicsManager();
    Scenes::scenes["start"] = StartScene :: staticMetaObject;
    Scenes::scenes["game"] = GameScene :: staticMetaObject;
    Scenes::scenes["over"] = OverScene :: staticMetaObject;
    scene_manager = new SceneManager();
    //assert(Animations::START_BUTTON);
    scene_manager->init();
    return a.exec();
}
