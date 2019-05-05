#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <Character.h>
#include "customscene.h"

extern int G_Field_Width;
extern int G_Field_Height;
extern int G_Screen_Width;
extern int G_Screen_Height;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLine *l1;

public slots:
    void slotBullet(QPointF start, QPointF end);
    void slotScroll(int x, int y);
    void slotHitTarget(QGraphicsItem *item,QGraphicsItem *item2); // Слот попадения
    void slotSpawnWeapon();
    void slotTakeItem();

private slots:
    void slotCreateTarget(); // Слот для создания мишеней

private:
    QTimer *timerTarget;        // Таймер для создания мишеней
    static QList<QGraphicsItem *> targets;  // Список мишеней

    Ui::MainWindow *ui;
    CustomScene *scene;
    Character *player;
    QTimer *tick;
};

#endif // MAINWINDOW_H
