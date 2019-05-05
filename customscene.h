#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H
#include "QGraphicsScene"

extern int G_Field_Width;
extern int G_Field_Height;

class CustomScene : public QGraphicsScene
{
    Q_OBJECT

signals:
    void signalTargetCoordinate(QPointF point);
    void signalShot(bool shot); // Сигнал на стрельбу
public:
    CustomScene();
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMSCENE_H
