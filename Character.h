#ifndef Character_H
#define Character_H

#include <QGraphicsItem>
#include "weapon.h"
#include "windows.h"
#include "healthbar.h"
#include "animation.h"

extern int G_Field_Width;
extern int G_Field_Height;

class Character : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = nullptr);
    ~Character();
    Animation aTexture;
    QRectF Size;
    QPointF target; //Позиция мышки
    int gX, gY;
    int Velocity;
    Weapon weapon;
    HealthBar *hp;
    bool aUpd; // Актуальна ли анимация
    bool isWalking; //Идет ли персонаж
private:


signals:
    void signalBullet(QPointF start, QPointF end);

    void signalScroll(int x, int y);

    void signalTakeItem();

public slots:
    // Слот для получения данных о положении курсора
    void slotTarget(QPointF point);
    // слот для обработки разрешения стрельбы
    void slotShot(bool shot);

    void slotTick();

    void slotReceiveDamage(int dmg);
private slots:
    // Игровой слот
    void slotBulletTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

private:
    qreal angle;
};

#endif // Character_H
