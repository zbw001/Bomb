#ifndef IMAGERECT_H
#define IMAGERECT_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QRectF>
#include <QObject>
#include <QString>
#include <QMap>
#include "../animation.h"
#include "../globals.h"

class Sprite: public QObject, public QGraphicsItem {
Q_OBJECT
public:
    Sprite(QGraphicsItem *parent, const Animation &animation, bool has_shape=false, bool event_enabled=false, const QString &text="", const QColor &color=Qt::black, const QFont &font=QFont(Fonts::default_font_family, 8, QFont::Normal));
    Sprite(QGraphicsItem *parent, const QHash<QString, Animation> &animations, const QString &default_animation, bool has_shape=false, bool event_enabled=false, const QString &text="", const QColor &color=Qt::black, const QFont &font=QFont(Fonts::default_font_family, 8, QFont::Normal));
    void setAnimation(const QString &animation);
    void setText(const QString &text, const QColor &color=Qt::black, const QFont &font=QFont(Fonts::default_font_family, 16, QFont::Normal));
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void timerEvent(QTimerEvent *e) override;
signals:
    void mousePressed(QGraphicsSceneMouseEvent* event);
private:
    QHash<QString, Animation> animations;
    QString cur_animation;
    int cur_timer, cur_index;
	QFont font;
	QColor color;
    QString text;
    bool has_shape;
    bool event_enabled;
    QPixmap getPixmap() const;
};
#endif
