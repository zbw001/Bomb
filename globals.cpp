#include "globals.h"
#include <QSize>
#include <QMap>
#include <QRect>

namespace Fonts {
    QString default_font_family;
}

namespace Consts {
    const int FPS = 60;
    const int CHARACTER_WIDTH = int(192/2.5);
    const int CHARACTER_HEIGHT = int(256/2.5);
    const int BOMB_WIDTH = 48;
    const int BOMB_HEIGHT = 48;
    const int BOMB_RADIUS = 24;
    const int MAX_HP = 100;
    const int START_BUTTON_WIDTH = 190;
    const int START_BUTTON_HEIGHT = 49;

    const int HPBAR_BACKGROUND_WIDTH = 64;
    const int HPBAR_BACKGROUND_HEIGHT = 17;
    const int HPBAR_BAR_WIDTH = 49;
    const int HPBAR_BAR_HEIGHT = 17;
    const int BLOCK_SIZE = 48;
    const double EPS = 10;
    const int VIEW_WIDTH = 1280;
    const int VIEW_HEIGHT = 720;
    const int GRAVITY = 1200;
    const int EXPLOSION1_SIZE = 500;
    const int NUM_PLAYERS = 2;
    const int NUM_CHARACTERS_PER_PLAYER = 3;
    const double K_KNOCK = 3000;
    const double K_HURT = 100;
    const double BLOCK_DAMAGE_DISTANCE = BLOCK_SIZE * 3;
    const double MU = 3000;
    const int GAME_SCENE_WIDTH = VIEW_WIDTH * 2;
    const int GAME_SCENE_HEIGHT = VIEW_HEIGHT * 2;
    const int TILEMAP_WIDTH = int(GAME_SCENE_WIDTH / BLOCK_SIZE) + 1;
    const int TILEMAP_HEIGHT = int(GAME_SCENE_HEIGHT / BLOCK_SIZE) + 1;
    const int MAX_CURSOR_DISTANCE_BOMB = 200;
    const int MAX_CURSOR_DISTANCE_MOVE = 150;
    const int MAX_CURSOR_DISTANCE_ITEM = 200;
    const int BACKGROUND_WIDTH = 4320 / 4 * 3;
    const int BACKGROUND_HEIGHT = 2160 / 4 * 3;
    const double K_V0 = 5;
    const int MARK_SIZE = 80;
}

namespace Animations {
    Animation* CHARACTER_IDLE = nullptr;
    Animation* CHARACTER_DIE = nullptr;
    Animation* BOMB = nullptr;
    Animation* START_BUTTON = nullptr;
    Animation* HPBAR_BACKGROUND = nullptr;
    Animation* HPBAR_BAR = nullptr;
    Animation* BLOCKS[] = {
        nullptr, nullptr
    };
    Animation* EXPLOSION1 = nullptr;
    Animation* BACKGROUND = nullptr;
    Animation* MARK = nullptr;
}

namespace Scenes {
    QMap<QString, QMetaObject> scenes;
    const QString init_scene = "start";
}

namespace Globals {
    int winner;
}




