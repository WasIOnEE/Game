#include "healthbar.h"
#include "QPainter"
#include "QObject"
#include "QDebug"

HealthBar::HealthBar(QObject* obj) : QObject(obj), QGraphicsItem ()
{
    col = Qt::red;
    width = 300;
    height = 15;
}

QRectF HealthBar::boundingRect() const
{
    return QRectF(0,-height/2,width,height);
}

void HealthBar::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    QPen pen;
    pen.setColor(Qt::black);
    pen.setStyle(Qt::SolidLine);
    QBrush br;
    br.setStyle(Qt::SolidPattern);
    br.setColor(col);
    painter->setPen(pen);
    painter->setBrush(br);
    painter->drawRect(QRectF(0,-height/2,width*(currentHealth)/maxHealth,height));
    br.setStyle(Qt::NoBrush);
    painter->setBrush(br);
    painter->drawRect(QRectF(0,-height/2,width,height));
}

void HealthBar::slotRepaint()
{
    this->update(QRectF(0,-height/2,width,height));
}
