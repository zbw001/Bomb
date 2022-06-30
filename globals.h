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
    extern const int HPBAR_BACKGROUND_WIDTH;
    extern const int HPBAR_BACKGROUND_HEIGHT;
    extern const int HPBAR_BAR_WIDTH;
    extern const int HPBAR_BAR_HEIGHT;
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
    extern const int MAX_CURSOR_DISTANCE_BOMB;
    extern const int MAX_CURSOR_DISTANCE_MOVE;
    extern const int MAX_CURSOR_DISTANCE_ITEM;
    extern const double K_V0;
    extern const int BACKGROUND_WIDTH;
    extern const int BACKGROUND_HEIGHT;
    extern const int MARK_SIZE;
}

namespace Globals {
    extern int winner;
}

namespace Animations {
	extern Animation* CHARACTER_IDLE;
    extern Animation* CHARACTER_DIE;
	extern Animation* BOMB ;
    extern Animation* BOMB2;
    extern Animation* BOMB3 ;
    extern Animation* SELECT_BOMB;
    extern Animation* BOMB_PASS;
	extern Animation* START_BUTTON;
	extern Animation* HPBAR_BACKGROUND;
	extern Animation* HPBAR_BAR;
	extern Animation* BLOCKS[];
    extern Animation* EXPLOSION1;
    extern Animation* BACKGROUND;
    extern Animation* MARK;
}

namespace Scenes {
    extern QMap<QString, QMetaObject> scenes;
    extern const QString init_scene;
}

