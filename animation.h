#ifndef ANIMATION_H
#define ANIMATION_H
#include <QObject>
#include <QList>
#include <QPixmap>

class Animation : public QObject{
Q_OBJECT
	public:
		Animation(int fps, bool repeat = false);
        Animation(const QString &res, const QSize &size = QSize());
		~Animation();
		Animation* addFrame(const QString &res, const QSize &size);
        QPixmap* getPixmap();
		void start();
		void stop();
		bool isPlaying();
	signals:
		void animationFinished(); // 只会在 repeat = false 时被调用
		void animationChanged();
	private:
		bool playing = false;
		int timer;
		int current_frame;
		QList<QPixmap*> frames;
		int fps;
		bool repeat;
	protected:
        void timerEvent(QTimerEvent *event) override;
};
#endif