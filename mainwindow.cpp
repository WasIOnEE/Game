#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTimer"
#include "QDebug"
#include "bullet.h"
#include "enemy.h"
#include "QLine"
#include "itemweapon.h"

int G_Field_Width = 5000;
int G_Field_Height = 1000;
int G_Screen_Width = 500;
int G_Screen_Height = 500;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showMaximized();
    scene = new CustomScene;
    ui->graphicsView->setGeometry(0,0,1920,1280);
    player = new Character();
    ui->graphicsView->setMouseTracking(true);
    connect(scene, &CustomScene::signalTargetCoordinate, player, &Character::slotTarget);
    connect(scene, &CustomScene::signalShot, player, &Character::slotShot);
    // Соединяем сигнал на создание пули со слотом, создающим пули в игре
    connect(player, &Character::signalBullet, this, &MainWindow::slotBullet);
    connect(player, &Character::signalScroll,this,&MainWindow::slotScroll);
    connect(player, &Character::signalTakeItem,this,&MainWindow::slotTakeItem);


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(0,0,G_Field_Width,G_Field_Height+100);

    scene->addRect(0,0,G_Field_Width,G_Field_Height,QPen(Qt::green),QBrush(Qt::darkGreen));
    scene->addLine(0,G_Field_Height/2,G_Field_Width,G_Field_Height/2,QPen(Qt::black,1));
    scene->addLine(G_Field_Width/2,0,G_Field_Width/2,G_Field_Height,QPen(Qt::black,1));

    scene->addLine(0,0,0,G_Field_Height,QPen(Qt::black,5));
    scene->addLine(0,G_Field_Height,G_Field_Width,G_Field_Height,QPen(Qt::black,5));
    scene->addLine(G_Field_Width,G_Field_Height,G_Field_Width,0,QPen(Qt::black,5));
    scene->addLine(G_Field_Width,0,0,0,QPen(Qt::black,5));

    scene->addItem(player);
    scene->addItem(player->hp);
    player->hp->setPos(0,0);
    player->hp->setZValue(3);
    player->setPos(0,0);
    player->setZValue(2);

    tick = new QTimer();
    connect(tick,&QTimer::timeout,player,&Character::slotTick);
    connect(tick,&QTimer::timeout,player->hp, &HealthBar::slotRepaint);
    tick->start(20);

    timerTarget = new QTimer();
    connect(timerTarget, &QTimer::timeout, this, &MainWindow::slotCreateTarget);
    connect(timerTarget, &QTimer::timeout, this, &MainWindow::slotSpawnWeapon);
    timerTarget->start(1500);
    //player->weapon.bullet.Size = QRectF(-10,-10,20,20);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotBullet(QPointF start, QPointF end)
{
    // Добавляем на сцену пулю
    Bullet *b = new Bullet(start, end);
    b->Velocity = player->weapon.bullet.Velocity;
    b->Texture = player->weapon.bullet.Texture;
    b->Size = player->weapon.bullet.Size;
    connect(b,SIGNAL(Hit(QGraphicsItem*, QGraphicsItem*)),this,SLOT(slotHitTarget(QGraphicsItem*, QGraphicsItem*)));
    scene->addItem(b);
}

void MainWindow::slotScroll(int x, int y)
{
    ui->graphicsView->centerOn(player->x(),player->y());
    scene->update(0,0,G_Field_Width,G_Field_Height);
}

void MainWindow::slotCreateTarget()
{
    Enemy *target = new Enemy();  // Создаём цель
    scene->addItem(target);         // Помещаем цель в сцену со случайной позицией
    target->setPos(qrand() % (G_Field_Width - 80) + 40, qrand() % (G_Field_Height - 80) + 40);
    target->setZValue(1);          // Помещаем цель ниже Героя
    target->target = player;
    connect(tick,SIGNAL(timeout()),target,SLOT(tick()));
    targets.append(target);         // Добавляем цель в список
}

void MainWindow::slotHitTarget(QGraphicsItem *item, QGraphicsItem* bul)
{
    /* Получив сигнал от Пули
     * Перебираем весь список целей и наносим ему случайный урон
     * */
    foreach (QGraphicsItem *targ, targets) {
        if(targ != player)
        {
            if(targ == item){
                // Кастуем объект из списка в класс Target
                Enemy *t = qgraphicsitem_cast <Enemy *> (targ);
                t->hit(player->weapon.Damage); // Наносим урон
                Bullet *b = qgraphicsitem_cast<Bullet*>(bul);
                b->deleteLater();
                break;
            }
        }
    }
}

void MainWindow::slotSpawnWeapon()
{
    ItemWeapon *w = new ItemWeapon();
    w->Damage = qrand()%5+1;
    w->FireRate = qrand()%1200+10;
    w->bullet.Texture.fill(QColor(qrand()%255,qrand()%255,qrand()%255));
    scene->addItem(w);
    w->setPos(G_Field_Width/2,G_Field_Height/2);
    w->setZValue(1);
}

void MainWindow::slotTakeItem()
{
    QList<QGraphicsItem *> foundItems = scene->items(QPolygonF()
                                                    << player->mapToScene(-5, -5)
                                                    << player->mapToScene(-1, 5)
                                                    << player->mapToScene(1, 5)
                                                    << player->mapToScene(1,-5));
    foreach (QGraphicsItem *item, foundItems) {
        if (item == player)
            continue;
        ItemWeapon *w = dynamic_cast<ItemWeapon* >(item);
        if(w != 0)
        {
            player->weapon.Damage = w->Damage;
            player->weapon.FireRate = w->FireRate;
            player->weapon.bulletTimer->setInterval(player->weapon.FireRate);
            player->weapon.bullet.Texture = w->bullet.Texture;
            w->deleteLater();
        }
    }

}

QList<QGraphicsItem *> MainWindow::targets; // реализация списка
