#include "sprite.h"

Sprite::Sprite(QGraphicsItem *parent, Animation *animation, bool has_shape, const QString &text, const QColor &color, const QFont &font) : QGraphicsItem(parent) {
    this->setText(text, color, font);
    animation = nullptr;
    this->setAnimation(animation);
    this->has_shape = has_shape;
}

Sprite::~Sprite() {
    Sprite::setAnimation(nullptr);
}

void Sprite::animationChanged() {
    QGraphicsItem::update();
}

void Sprite::setText(const QString &text, const QColor &color, const QFont &font) {
    this->text = text;
	this->color = color;
	this->font = font;
}

void Sprite::setAnimation(Animation* animation) {
    if (this->animation) {
        if (this->animation->isPlaying())
            this->animation->stop();
        QObject::disconnect(this->animation, nullptr, this, nullptr);
    }
    this->animation = animation;
    if (this->animation) {
        this->animation->start();
        QObject::connect(this->animation, &Animation::animationChanged, this, &Sprite::animationChanged);
    }
}

QRectF Sprite::boundingRect() const {
    return QRectF(animation->getPixmap()->rect());
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap *pixmap = animation->getPixmap();
    QRect rect = pixmap->rect();
    painter->drawPixmap(rect, *pixmap);
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
    emit mousePressed(event);
}
