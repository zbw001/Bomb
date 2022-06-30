#include "sprite.h"
#include <QDebug>
#include <QSizeF>
#include <QTransform>

Sprite::Sprite(QGraphicsItem *parent, const Animation &animation, bool event_enabled, const QString &text, const QColor &color, const QFont &font) : QGraphicsItem(parent) {
    this->setText(text, color, font);
    animations["default"] = animation;
    cur_animation = "";
    this->setAnimation("default");
    this->event_enabled = event_enabled;
    finished = false;
}

Sprite::Sprite(QGraphicsItem *parent, const QHash<QString, Animation> &animations, const QString &default_animation, bool event_enabled, const QString &text, const QColor &color, const QFont &font) : QGraphicsItem(parent) {
    this->setText(text, color, font);
    this->animations = animations;
    cur_animation = "";
    this->setAnimation(default_animation);
    this->event_enabled = event_enabled;
    finished = false;
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
    finished = false;
    cur_index = 0;
    assert(animations.contains(name));
    cur_animation = name;
    Animation animation = animations[name];
    cur_timer = QObject::startTimer(1000 / animation.fps);
    update();
}

void Sprite::flipHorizontal() {
    QTransform transform(this->transform());
    qreal m11 = transform.m11();    // Horizontal scaling
    qreal m12 = transform.m12();    // Vertical shearing
    qreal m13 = transform.m13();    // Horizontal Projection
    qreal m21 = transform.m21();    // Horizontal shearing
    qreal m22 = transform.m22();    // vertical scaling
    qreal m23 = transform.m23();    // Vertical Projection
    qreal m31 = transform.m31();    // Horizontal Position (DX)
    qreal m32 = transform.m32();    // Vertical Position (DY)
    qreal m33 = transform.m33();    // Addtional Projection Factor
    qreal scale = m11;
    m11 = -m11;
    if(m31 > 0)
        m31 = 0;
    else
        m31 = (boundingRect().width() * scale);
    transform.setMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);
    setTransform(transform);
}

void Sprite::flipVertical() {
    QTransform transform(this->transform());
    qreal m11 = transform.m11();    // Horizontal scaling
    qreal m12 = transform.m12();    // Vertical shearing
    qreal m13 = transform.m13();    // Horizontal Projection
    qreal m21 = transform.m21();    // Horizontal shearing
    qreal m22 = transform.m22();    // vertical scaling
    qreal m23 = transform.m23();    // Vertical Projection
    qreal m31 = transform.m31();    // Horizontal Position (DX)
    qreal m32 = transform.m32();    // Vertical Position (DY)
    qreal m33 = transform.m33();    // Addtional Projection Factor
    qreal scale = m22;
    m22 = -m22;
    if(m32 > 0)
        m32 = 0;
    else
        m32 = (boundingRect().height() * scale);
    transform.setMatrix(m11, m12, m13, m21, m22, m23, m31, m32, m33);
    setTransform(transform);
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
    path.addRect(boundingRect());
    return path;
}

void Sprite::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event_enabled) {
        //qDebug("点击事件");
        emit mousePressed(event);
    } else QGraphicsItem::mousePressEvent(event);
}

void Sprite::timerEvent(QTimerEvent *e) {
    Animation &animation = animations[cur_animation];
    if (cur_index + 1 >= animation.length()) {
        if (animation.repeat) {
            cur_index = 0;
            update();
        } else {
            if (!finished) {
                finished = true;
                emit animationFinished();
            }
        }
    } else {
        cur_index ++;
        update();
    }
}

void Sprite::setAnimation(const QString &key, const Animation &animation) {
    animations[key] = animation;
    Sprite::setAnimation(key);
}

QPixmap Sprite::getPixmap() const {
    if (animations[cur_animation].isEmpty()) {
        QPixmap ret(Consts::VIEW_WIDTH, Consts::VIEW_HEIGHT); ret.fill(Qt::transparent);
        return ret;
    }
    //qDebug() << cur_animation << " " << cur_index;
    //qDebug() << animations[cur_animation].length();
    return animations[cur_animation][cur_index];
}

QPointF Sprite::center() {
    QSizeF size = boundingRect().size();
    return pos() + QPointF(size.width() / 2.0, size.height() / 2.0);
}
