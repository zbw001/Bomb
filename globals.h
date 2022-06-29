#include <QString>
#include <QFont>
#include <QRect>
#include "animation.h"

namespace Fonts {
	extern QString default_font_family;
}

namespace Consts {
	extern const int FPS;
	extern const int CHARACTER_WIDTH;
	extern const int CHARACTER_HEIGHT;
	extern const int MAX_HP;
    extern const int BOMB_WIDTH;
    extern const int BOMB_HEIGHT;
    extern const int BOMB_RADIUS;
	extern const int START_BUTTON_WIDTH;
	extern const int START_BUTTON_HEIGHT;
	extern const int TILEMAP_WIDTH;
	extern const int TILEMAP_HEIGHT;
	extern const int BLOCK_SIZE;
	extern const double EPS;
	extern const int HPBAR_WIDTH;
	extern const int HPBAR_HEIGHT;
	extern const int VIEW_WIDTH;
	extern const int VIEW_HEIGHT;
	extern const int GRAVITY;
}

namespace Animations {
	extern Animation* CHARACTER_IDLE;
	extern Animation* BOMB ;
	extern Animation* START_BUTTON;
	extern Animation* HPBAR_BACKGROUND;
	extern Animation* HPBAR_BAR;
	extern Animation* BLOCKS[];
}

namespace Scenes {
    extern QMap<QString, QMetaObject> scenes;
    extern const QString init_scene;
}

