#ifndef ANIMATION_H
#define ANIMATION_H
#include <QObject>
#include <QList>
#include <QPixmap>

class Animation : public QList<QPixmap> {
public:
    Animation(int fps = -1, bool repeat = false);
	Animation(const QString &res, const QSize &size = QSize());
	void addFrame(const QString &res, const QSize &size);
	int fps;
	bool repeat;
    Animation crop(int width, int height);
};
#endif
