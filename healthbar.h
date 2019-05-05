#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "QObject"
#include "QColor"
#include "QGraphicsItem"

class HealthBar : public QObject, public QGraphicsItem
{
public:
    explicit HealthBar(QObject* obj = nullptr);
    //~HealthBar();
    int maxHealth;
    int currentHealth;
    QColor col;
    int width;
    int height;

    void setAlive(bool b){isAlive = b;}
    bool getAlive(){return isAlive;}
private:
    bool isAlive;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void slotRepaint();
};

#endif // HEALTHBAR_H
