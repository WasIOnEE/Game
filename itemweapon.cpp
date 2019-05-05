#include "itemweapon.h"
#include "QDebug"
#include "QPainter"

ItemWeapon::ItemWeapon(QObject *parent) : QObject(parent), Weapon()
{
    Size = QRectF(-25,-25,50,50);
    Texture.load("Recources/Images/Character.png");
}

QRectF ItemWeapon::boundingRect() const
{
    return Size;
}

void ItemWeapon::paint(QPainter* p,const QStyleOptionGraphicsItem* opt, QWidget* w)
{
    qDebug()<<"str";
    p->setPen(Qt::red);
    p->setBrush(Qt::green);
    p->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),Texture);
//    p->drawRect(Size);

    Q_UNUSED(opt);
    Q_UNUSED(w);
}
