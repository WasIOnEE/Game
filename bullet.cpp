#include "bullet.h"
#include <math.h>
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

Bullet::Bullet(QObject *parent) : QObject(parent), QGraphicsItem()
{
    this->setRotation(0);   // Устанавливаем начальный разворот
    this->setPos(0,0);
    Size = QRectF(0,0,4,8);
    Texture = QPixmap(5,10);
    Texture.fill(Qt::black);
    timerBullet = new QTimer();
    Velocity = 20;
}

Bullet::Bullet(QPointF start, QPointF end, QObject *parent)
    : QObject(parent), QGraphicsItem()
{
    this->setRotation(0);   // Устанавливаем начальный разворот
    this->setPos(start);    // Устанавливаем стартовую позицию
    Size = QRectF(0,0,8,24);
    Texture.load("C:/Users/WasIOn/Documents/Game/Recources/Images/Arrow.png");
    // Определяем траекторию полёта пули
    QLineF lineToTarget(start, end);
    // Угол поворота в направлении к цели
    qreal angleToTarget = ::acos(lineToTarget.dx() / lineToTarget.length());
    if (lineToTarget.dy() < 0)
        angleToTarget = TwoPi - angleToTarget;
    angleToTarget = normalizeAngle((Pi - angleToTarget) + Pi / 2);

    /* Разворачиваем пули по траектории
     * */
    if (angleToTarget >= 0 && angleToTarget < Pi) {
        /// Rotate left
        setRotation(rotation() - angleToTarget * 180 /Pi);
    } else if (angleToTarget <= TwoPi && angleToTarget > Pi) {
        /// Rotate right
        setRotation(rotation() + (angleToTarget - TwoPi )* (-180) /Pi);
    }
    // Инициализируем полётный таймер
    timerBullet = new QTimer();
    // И подключаем его к слоту для обработки полёта пули
    connect(timerBullet, &QTimer::timeout, this, &Bullet::slotTimerBullet);
    timerBullet->start(20);
}

Bullet::~Bullet()
{
    delete timerBullet;
}

QRectF Bullet::boundingRect() const
{
    return Size;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);

    painter->drawPixmap(Size.x(),Size.y(),Size.width(),Size.height(),Texture);
    //painter->drawRect(Size);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Bullet::slotTimerBullet()
{
    bool h = 0;
    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                       << mapToScene(0, 0)
                                                       << mapToScene(0, -1));
    setPos(mapToParent(0, -Velocity));

    /* Проверка выхода за границы поля
     * Если пуля вылетает за заданные границы, то пулю необходимо уничтожить
     * */
    if(this->x() < 0){
        this->deleteLater();
    }
    if(this->x() > G_Field_Width){
        this->deleteLater();
    }

    if(this->y() < 0){
        this->deleteLater();
    }
    if(this->y() > G_Field_Height){
        this->deleteLater();
    }
    foreach (QGraphicsItem *item, foundItems)
    {
        if (item == this)
            continue;
        if(!h)
        {
            h= 1;
            emit Hit(item,this);
        }
        //deleteLater(); // Уничтожаем пулю
    }
}
