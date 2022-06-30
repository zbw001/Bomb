#include "animation.h"
#include <QDebug>
#include <QRect>
#include <QPixmap>
#include <QBitmap>
#include <QImage>
#include <QColor>
#include <QPainter>
#include <QtGlobal>

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

Animation Animation::crop(int width, int height) {
    Animation ret(*this);
    for (int i = 0; i < ret.length(); i++) {
        ret[i] = ret[i].copy(QRect(0, 0, width, height));
    }
    return ret;
}


Animation Animation::setColor(QColor color) {
    Animation ret(*this);
    for (int i = 0; i < ret.length(); i++) {
        QPixmap pix = QPixmap(ret[i]);
        QBitmap mask = pix.createHeuristicMask();
        QPainter p(&pix);
        p.setPen(color);
        p.drawPixmap(pix.rect(), mask, mask.rect());
        p.end();
        ret[i] = pix;
    }
    return ret;
}
