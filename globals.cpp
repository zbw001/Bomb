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
    const double EPS = 5;
	const int VIEW_WIDTH = 1600;
	const int VIEW_HEIGHT = 900;
    const int GRAVITY = 1200;
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




