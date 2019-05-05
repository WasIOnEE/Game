#include "Character.h"
#include "QPainter"
#include "QDebug"
#include "QGraphicsSceneMouseEvent"
#include "QTimer"

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

Character::Character(QObject *parent) : QObject(parent), QGraphicsItem () , weapon(), aTexture(7)
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
    Size = QRectF(-50,-80,100,100);
    angle = 0;
    setRotation(angle);
    target = QPointF(0,0);

    //weapon.bulletTimer = new QTimer(); // Инициализируем таймер создания пуль
    connect(weapon.bulletTimer, &QTimer::timeout, this, &Character::slotBulletTimer);
    weapon.bulletTimer->start(weapon.FireRate); // Стреляем 6 раз в секунду
    Velocity = 15;
    hp = new HealthBar;
    hp->setAlive(1);
    hp->maxHealth = 100;
    hp->currentHealth = hp->maxHealth;
}

Character::~Character()
{
    delete hp;
}

QRectF Character::boundingRect() const
{
    return Size; //Колид-модель объекта
}

void Character::paint(QPainter *p, const QStyleOptionGraphicsItem *opt, QWidget *w)
{
    p->setBrush(Qt::red);
    if(aUpd)
    {
        if(isWalking)
        {
            p->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),aTexture.next());
        }
        else
        {
            aTexture.c = 0;
            p->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),aTexture.current());
        }
    }
    else
    {
        p->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),aTexture.current());
    }
    aUpd = 0;
    Q_UNUSED(opt);
    Q_UNUSED(w);
}

void Character::slotTick()
{
    aUpd = 1;
    isWalking = false;
    if(hp->currentHealth<=0) // Получаем урон
    {
        hp->setAlive(0);
    }
    if(hp->getAlive())
    {
        if(GetAsyncKeyState(VK_LEFT))
        {
            isWalking = true;
            setPos(this->x()-Velocity,this->y());
            if(this->x()<=0)
                this->setX(0);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            isWalking = true;
            setPos(this->x()+Velocity,this->y());
            if(this->x() >= G_Field_Width)
                this->setX(G_Field_Width);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(VK_UP))
        {
            isWalking = true;
            setPos(this->x(),this->y()-Velocity);
            if(this->y() <= 0)
                this->setY(0);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            isWalking = true;
            setPos(this->x(),this->y()+Velocity);
            if(this->y() >= G_Field_Height)
                this->setY(G_Field_Height);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(CHAR('A')))
        {
            isWalking = true;
            setPos(this->x()-Velocity,this->y());
            if(this->x()<=0)
                this->setX(0);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(CHAR('D')))
        {
            isWalking = true;
            setPos(this->x()+Velocity,this->y());
            if(this->x() >= G_Field_Width)
                this->setX(G_Field_Width);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(CHAR('W')))
        {
            isWalking = true;
            setPos(this->x(),this->y()-Velocity);
            if(this->y() <= 0)
                this->setY(0);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(CHAR('S')))
        {
            isWalking = true;
            setPos(this->x(),this->y()+Velocity);
            if(this->y() >= G_Field_Height)
                this->setY(G_Field_Height);
            if(x() < 960)
            {
                hp->setPos(5,-25);
            }
            else if(x() > G_Field_Width-960)
            {
                hp->setPos(G_Field_Width-1895,-25);
            }
            else
            {
                hp->setPos(x()-945,-25);
            }
            emit signalScroll(1,1);
        }
        if(GetAsyncKeyState(CHAR('F')))
        {
            emit signalTakeItem();
        }

        QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
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
    }
}

void Character::slotTarget(QPointF point)
{
    if(hp->getAlive())
    {
        // Определяем расстояние до цели
        target = point;
        QLineF lineToTarget(QPointF(0, 0), mapFromScene(target));
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
    }
}
void Character::slotBulletTimer()
{
    // Если стрельба разрешена, то вызываем сигнал на создание пули
    if(weapon.shot) emit signalBullet(QPointF(this->x(),this->y()), target);

}
void Character::slotShot(bool sh)
{
    if(hp->getAlive())
        this->weapon.shot = sh;  // Получаем разрешение или запрет на стрельбу
    else
        this->weapon.shot = 0;
}

void Character::slotReceiveDamage(int dmg)
{
    if(hp->currentHealth<=0) // Получаем урон
    {
        hp->setAlive(0);
    }
    else
    {
        hp->currentHealth -= dmg;
        if(hp->currentHealth<=0)
        {
            hp->setAlive(0);
        }
        else
        {
            hp->setAlive(1);
        }
    }
    hp->update();
}
