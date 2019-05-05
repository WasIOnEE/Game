#ifndef ITEM_H
#define ITEM_H
#include "QPixmap"

class Item
{
public:
    bool bStackable = false;
    QPixmap Texture;
    int ID;
    int Count;
    Item();
};

#endif // ITEM_H
