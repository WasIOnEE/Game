#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include "QGraphicsItem"
#include "QImage"
#include "Character.h"
#include "QTimer"
#include "animation.h"

class Enemy : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Character* target;
    Animation aTexture;
    QRectF Size;
    QRectF FullSize;
    explicit Enemy(QObject *parent = nullptr);
    ~Enemy();
    void hit(int damage);
    void SendDamage();
    bool isAttacking;
    bool isWalking;
    bool aUpd;
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int Damage = 5;
    int health = 5;
    int maxHealth = 5;
    QTimer attackTimer;

signals:

public slots:
    void Attack();
    virtual void moveToTarget(int x = 0, int y = 0);
    virtual void tick();
};

#endif // ENEMY_H
