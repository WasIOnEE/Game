#ifndef ANIMATION_H
#define ANIMATION_H

#include "QPixmap"


class Animation
{
public:
    Animation(int x);

    int Count;
    QPixmap* px;
    int c; // Счетчик текущего кадра
    int z, zM; // Задержка по тику

    QPixmap next();
    QPixmap current();
    void set(int x, QString str);
    ~Animation();
};

#endif // ANIMATION_H
