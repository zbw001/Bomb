#include "animation.h"

Animation::Animation(int fps, bool repeat) {
	this->fps = fps;
	this->repeat = repeat;
	this->current_frame = 0;
	this->playing = false;
}

Animation::Animation(const QString &res, const QSize &size) {
	addFrame(res, size);
	this->fps = 1;
	this->repeat = false;
	this->current_frame = 0;
	this->playing = false;
}

Animation::~Animation() {
	for (int i = 0; i < frames.length(); i++) {
		delete frames[i];
	}
}

Animation* Animation::addFrame(const QString &res, const QSize &size = QSize()) {
    QPixmap pixmap = QPixmap();
    pixmap.load(res);
    if (size.isValid())
        pixmap = pixmap.scaled(size.width(), size.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    this->frames.append(new QPixmap(pixmap));
	return this;
}

QPixmap* Animation::getPixmap() {return frames[current_frame];}

bool Animation::isPlaying() {
	return playing;
}

void Animation::start() {
	assert(!this->playing);
	assert(!frames.empty());
	current_frame = 0;
	timer = QObject::startTimer(double(1000) / fps);
	this->playing = true;
	emit animationChanged();
}

void Animation::stop() {
	assert(this->playing);
	QObject::killTimer(timer);
	this->playing = false;
	emit animationFinished();
}

void Animation::timerEvent(QTimerEvent *event) {
	assert(this->playing);
	if (current_frame + 1 >= frames.length()) {
		if (!repeat) {
			stop();
			return;
		} else {
			current_frame = 0;
		}
	} else {
		current_frame += 1;
        emit animationChanged();
	}
}
