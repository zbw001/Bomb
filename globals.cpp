#include "globals.h"
#include <QSize>
#include <QMap>
#include <QRect>

namespace Fonts {
	QString default_font_family;
}

namespace Consts {
	const int FPS = 60;
	const int CHARACTER_WIDTH = 192;
	const int CHARACTER_HEIGHT = 256;
	const int BOMB_WIDTH = 128;
	const int BOMB_HEIGHT = 128;
	const int BOMB_RADIUS = 64;
	const int MAX_HP = 100;
	const int START_BUTTON_WIDTH = 190;
	const int START_BUTTON_HEIGHT = 49;
	const int TILEMAP_WIDTH = 400;
	const int TILEMAP_HEIGHT = 200;
	const int HPBAR_WIDTH = 64;
	const int HPBAR_HEIGHT = 17;
	const int BLOCK_SIZE = 64;
	const double EPS = 0.01;
	const int VIEW_WIDTH = 1600;
	const int VIEW_HEIGHT = 900;
	const QRect SCENE_RECT(-3200, -1800, 6400, 3600);
	const int GRAVITY = 10;
}

namespace Animations {
    Animation* CHARACTER_IDLE = nullptr;
    Animation* BOMB = nullptr;
    Animation* START_BUTTON = nullptr;
    Animation* HPBAR_BACKGROUND = nullptr;
    Animation* HPBAR_BAR = nullptr;
    Animation* BLOCKS[] = {
        nullptr
    };
}

namespace Scenes {
    QMap<QString, QMetaObject> scenes;
    const QString init_scene = "start";
}




