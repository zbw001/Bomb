#include "scene.h"
#include "scene_manager.h"
#include "../items/sprite.h"
#include <QObject>

class OverScene: public Scene {
    Q_OBJECT
public:
    Q_INVOKABLE OverScene(SceneManager* manager);
    ~OverScene();
    Sprite *button;
    Sprite *background;
    Sprite *text;
};
