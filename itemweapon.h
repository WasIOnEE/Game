#ifndef ITEMWEAPON_H
#define ITEMWEAPON_H

#include <weapon.h>
#include "QGraphicsItem"

class ItemWeapon : public QObject, public QGraphicsItem , public Weapon
{
    Q_OBJECT
public:
    QRectF Size;
    explicit ItemWeapon(QObject *parent = nullptr);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
};

#endif // ITEMWEAPON_H
