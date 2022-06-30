#include "globals.h"
#include <QSize>
#include <QMap>
#include <QRect>

namespace Fonts {
	QString default_font_family;
}

namespace Consts {
	const int FPS = 60;
    const int CHARACTER_WIDTH = int(192/2.3);
    const int CHARACTER_HEIGHT = int(256/2.3);
    const int BOMB_WIDTH = 64;
    const int BOMB_HEIGHT = 64;
	const int BOMB_RADIUS = 64;
	const int MAX_HP = 100;
	const int START_BUTTON_WIDTH = 190;
	const int START_BUTTON_HEIGHT = 49;
    const int TILEMAP_WIDTH = 6400 / 64 + 1;
    const int TILEMAP_HEIGHT = 3600 / 64 + 1;
	const int HPBAR_WIDTH = 64;
	const int HPBAR_HEIGHT = 17;
	const int BLOCK_SIZE = 64;
    const double EPS = 10;
	const int VIEW_WIDTH = 1600;
	const int VIEW_HEIGHT = 900;
    const int GRAVITY = 1200;
    const int EXPLOSION1_SIZE = 500;
	const int NUM_PLAYERS = 2;
	const int NUM_CHARACTERS_PER_PLAYER = 3;
    const double K_KNOCK = 1000;
    const double K_HURT = 20;
    const double BLOCK_DAMAGE_DISTANCE = BLOCK_SIZE * 3;
    const double MU = 25;
}

namespace Animations {
    Animation* CHARACTER_IDLE = nullptr;
    Animation* CHARACTER_DIE = nullptr;
    Animation* BOMB = nullptr;
    Animation* START_BUTTON = nullptr;
    Animation* HPBAR_BACKGROUND = nullptr;
    Animation* HPBAR_BAR = nullptr;
    Animation* BLOCKS[] = {
        nullptr
    };
    Animation* EXPLOSION1 = nullptr;
}

namespace Scenes {
    QMap<QString, QMetaObject> scenes;
    const QString init_scene = "start";
}




