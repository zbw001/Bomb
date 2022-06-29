#include "scene.h"
#include "scene_manager.h"
#include "../items/sprite.h"

class OverScene: public Scene {
    Q_OBJECT
public:
    Q_INVOKABLE OverScene(SceneManager* manager);
    Sprite *button;
};