#include "sprite.h"
#include <QDebug>

Sprite::Sprite(QGraphicsItem *parent, const Animation &animation, bool has_shape, bool event_enabled, const QString &text, const QColor &color, const QFont &font) : QGraphicsItem(parent) {
    this->setText(text, color, font);
    animations["default"] = animation;
    cur_animation = "";
    this->setAnimation("default");
    this->has_shape = has_shape;
    this->event_enabled = event_enabled;
}

Sprite::Sprite(QGraphicsItem *parent, const QHash<QString, Animation> &animations, const QString &default_animation, bool has_shape, bool event_enabled, const QString &text, const QColor &color, const QFont &font) : QGraphicsItem(parent) {
    this->setText(text, color, font);
    this->animations = animations;
    cur_animation = "";
    this->setAnimation(default_animation);
    this->has_shape = has_shape;
    this->event_enabled = event_enabled;
}

void Sprite::setText(const QString &text, const QColor &color, const QFont &font) {
    this->text = text;
	this->color = color;
	this->font = font;
}

void Sprite::setAnimation(const QString &name) {
    if (cur_animation != "") {
        QObject::killTimer(cur_timer);
    }
    cur_index = 0;
    assert(animations.contains(name));
    cur_animation = name;
    Animation animation = animations[name];
    cur_timer = QObject::startTimer(1000 / animation.fps);
    update();
}

QRectF Sprite::boundingRect() const {
    return QRectF(getPixmap().rect());
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap = getPixmap();
    QRect rect = pixmap.rect();
    painter->drawPixmap(rect, pixmap);
    if (text != "") {
        QPen pen(color);
        painter->setPen(pen);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setFont(font);
        painter->drawText(QRectF(rect), Qt::AlignCenter, text);
    }
}

QPainterPath Sprite::shape() const {
    QPainterPath path;
    if (!has_shape) return path;
    path.addRect(boundingRect());
    return path;
}

void Sprite::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event_enabled) {
        qDebug("点击事件");
        emit mousePressed(event);
    } else QGraphicsItem::mousePressEvent(event);
}

void Sprite::timerEvent(QTimerEvent *e) {
    Animation &animation = animations[cur_animation];
    if (cur_index + 1 >= animation.length()) {
        if (animation.repeat) {
            cur_index = 0;
            update();
        }
    } else {
        cur_index ++;
        update();
    }
}

QPixmap Sprite::getPixmap() const {
    //qDebug() << cur_animation << " " << cur_index;
    //qDebug() << animations[cur_animation].length();
    return animations[cur_animation][cur_index];
}
