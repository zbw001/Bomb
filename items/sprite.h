#ifndef IMAGERECT_H
#define IMAGERECT_H

#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QRectF>
#include <QString>
#include "../animation.h"
#include "../globals.h"

class Sprite: public QGraphicsItem, public QObject {
Q_OBJECT
public:
    Sprite(QGraphicsItem *parent, Animation *animation, bool has_shape=false, const QString &text="", const QColor &color=Qt::black, const QFont &font=QFont(Fonts::default_font_family, 8, QFont::Normal));
    ~Sprite();
    void setAnimation(Animation * animation=nullptr);
    void setText(const QString &text, const QColor &color=Qt::black, const QFont &font=QFont(default_font_family, 8, QFont::Normal));
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
signals:
    void mousePressed(QGraphicsSceneMouseEvent* event);
private:
    Animation* animation;
	QFont font;
	QColor color;
    QString text;
    bool has_shape;
private slots:
    void animationChanged();
};
#endif
