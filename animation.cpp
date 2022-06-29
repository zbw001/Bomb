#include "animation.h"
#include <QDebug>

Animation::Animation(int fps, bool repeat) {
	this->fps = fps;
	this->repeat = repeat;
}

Animation::Animation(const QString &res, const QSize &size) {
	addFrame(res, size);
	this->fps = 1;
	this->repeat = false;
}

void Animation::addFrame(const QString &res, const QSize &size = QSize()) {
    QPixmap pixmap = QPixmap();
    pixmap.load(res);
    if (size.isValid())
        pixmap = pixmap.scaled(size.width(), size.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    append(pixmap);
}
