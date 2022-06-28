#include "globals.h"
#include <QSize>

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
}

namespace Animations {
    Animation* CHARACTER_IDLE = new Animation("assets/character/idle.png", QSize(Consts::CHARACTER_WIDTH, Consts::CHARACTER_HEIGHT));
    Animation* BOMB = new Animation("assets/bomb/bomb.png", QSize(Consts::BOMB_WIDTH, Consts::BOMB_HEIGHT));
	Animation* START_BUTTON = new Animation("/assets/start_button.png", QSize(Consts::START_BUTTON_WIDTH, Consts::START_BUTTON_HEIGHT));
}


