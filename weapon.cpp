#include "weapon.h"
#include "QTimer"

Weapon::Weapon() : bullet()
{
    FireRate = 350;
    Damage = 3;
    shot = false;
    bulletTimer = new QTimer();
    bullet.Velocity = 30;
}
