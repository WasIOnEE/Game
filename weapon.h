#ifndef WEAPON_H
#define WEAPON_H

#include "QPixmap"
#include "bullet.h"

class Weapon
{
public:
    bool shot;              // Переменная состояния стрельбы
    QTimer *bulletTimer;

    QObject* owner;
    int FireRate; //Миллисекунды
    int Damage;
    Bullet bullet;
    QPixmap Texture;

    Weapon();
};

#endif // WEAPON_H
