#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include "QGraphicsItem"
#include <QTimer>
#include <QPainter>

extern int G_Field_Width;
extern int G_Field_Height;

class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bullet(QPointF start, QPointF end, QObject *parent = nullptr);
    Bullet(QObject* parent = nullptr);
    ~Bullet();
    void setCallbackFunc(bool (*func) (QGraphicsItem * item));

    QPixmap Texture;
    QRectF Size;
    int Velocity;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool (*callbackFunc)(QGraphicsItem * item);

    QTimer *timerBullet;

private slots:
    void slotTimerBullet();

public slots:

signals:
    void Hit(QGraphicsItem* item, QGraphicsItem*);
};

#endif // BULLET_H
