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
    extern const int EXPLOSION1_SIZE;
	extern const int NUM_PLAYERS;
	extern const int NUM_CHARACTERS_PER_PLAYER;
    extern const double K_KNOCK;
    extern const double K_HURT;
    extern const double BLOCK_DAMAGE_DISTANCE;
    extern const double MU;
    extern const int GAME_SCENE_WIDTH;
    extern const int GAME_SCENE_HEIGHT;
}

namespace Animations {
	extern Animation* CHARACTER_IDLE;
    extern Animation* CHARACTER_DIE;
	extern Animation* BOMB ;
	extern Animation* START_BUTTON;
	extern Animation* HPBAR_BACKGROUND;
	extern Animation* HPBAR_BAR;
	extern Animation* BLOCKS[];
    extern Animation* EXPLOSION1;
}

namespace Scenes {
    extern QMap<QString, QMetaObject> scenes;
    extern const QString init_scene;
}

