#include "animation.h"

Animation::Animation(int x)
{
    Count = x;
    px = new QPixmap[x];
    c= 0;
    z = 0;
}

void Animation::set(int x, QString str)
{
    if(x<Count)
        px[x].load(str);
}

QPixmap Animation::next()
{
    if(z == zM)
    {
        z = 1;
        if(c+1 == Count)
            c=0;
        else
            c++;
        return px[c];
    }
    else
    {
        z++;
        return px[c];
    }
}
QPixmap Animation::current()
{
    return px[c];
}

Animation::~Animation()
{
    delete[] px;
}
