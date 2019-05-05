#include "enemy.h"
#include "QPainter"
#include "QPixmap"
#include "QDebug"
#include "QGraphicsScene"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Enemy::Enemy(QObject *parent) : QObject(parent), aTexture(7)
{
    isWalking = false;
    aUpd = 1;
    aTexture.zM = 3;
    aTexture.set(0,"Recources/Images/Zombie/Zombie1.png");
    aTexture.set(1,"Recources/Images/Zombie/Zombie2.png");
    aTexture.set(2,"Recources/Images/Zombie/Zombie3.png");
    aTexture.set(3,"Recources/Images/Zombie/Zombie4.png");
    aTexture.set(4,"Recources/Images/Zombie/Zombie5.png");
    aTexture.set(5,"Recources/Images/Zombie/Zombie6.png");
    aTexture.set(6,"Recources/Images/Zombie/Zombie7.png");
    Size = QRectF(-40,-40,80,80);
    FullSize = Size;
    FullSize.setY(FullSize.y()-6);
    FullSize.setHeight(FullSize.height()+6);
    isAttacking = false;
}

QRectF Enemy::boundingRect() const
{
    return FullSize;   // Ограничиваем область, в которой лежит цель
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* Отрисовываем зеленый квадрат
     * */
    painter->setBrush(Qt::red);
    if(aUpd)
    {
        if(isWalking)
        {
            painter->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),aTexture.next());
        }
        else
        {
            aTexture.c = 0;
            painter->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),aTexture.current());
        }
    }
    else
    {
        painter->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),aTexture.current());
    }
    aUpd = false;

    /* Отрисовываем полоску жизни
     * соизмеримо текущему здоровью
     * относительно максимального здоровья
     * */
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->drawRect(FullSize.x(),FullSize.y(), (int)FullSize.width()*health/maxHealth,4);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Enemy::hit(int damage)
{
    health -= damage;// Уменьшаем здоровье мишени
    this->update(FullSize);    // Перерисовываем мишень
    // Если здоровье закончилось, то инициируем смерть мишени
    if(health <= 0) this->deleteLater();
}
Enemy::~Enemy()
{

}

void Enemy::tick()
{
    aUpd = true;
    moveToTarget();
}
void Enemy::moveToTarget(int nx, int ny)
{
    if(nx == 0 && ny == 0)
    {
        if(target->hp->getAlive())
        {
            if(isAttacking)
            {

            }
            else
            {
                isWalking = true;
                QLineF lineToTarget(QPointF(0, 0), mapFromScene(QPointF(target->x(),target->y())));
                // Угол поворота в направлении к цели
                qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
                if (lineToTarget.dy() < 0)
                    angleToTarget = TwoPi - angleToTarget;
                angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

                /* В Зависимости от того, слева или справа находится Цель от Героя,
                 * устанавливаем направление поворота Героя в данном тике таймера
                 * */
                if (angleToTarget >= 0 && angleToTarget < Pi) {
                    // Rotate left
                    setRotation(rotation() - angleToTarget * 180 /Pi);
                } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
                    // Rotate right
                    setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
                }
                setPos(mapToParent(0, -5));
                SendDamage();
            }
        }
    }
    else
    {

    }
}

void Enemy::SendDamage()
{
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << this->mapToScene(-25, -25)
                                                       << this->mapToScene(0, 25)
                                                       << this->mapToScene(0, 25)
                                                       << this->mapToScene(0,-25));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == target)
        {
            isAttacking = true;
            isWalking = false;
            attackTimer.singleShot(300,this,SLOT(Attack()));
        }
    }
}

void Enemy::Attack()
{
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << this->mapToScene(-40, -40)
                                                       << this->mapToScene(0, 40)
                                                       << this->mapToScene(0, 40)
                                                       << this->mapToScene(0,-40));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == target)
        {
            target->slotReceiveDamage(Damage);
        }
    }
    isAttacking = false;
}
