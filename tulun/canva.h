#ifndef CANVA_H
#define CANVA_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsView>
#include"tulunitem.h"
namespace Ui {
class canva;
}

class canva : public QMainWindow
{
    Q_OBJECT

signals:
   void addJLItem();
public:
    explicit canva(QWidget *parent = 0);
    ~canva();
public slots:
    void SaddJLItem();

private:
    Ui::canva *ui;
    QGraphicsScene* mScence;
    QGraphicsView* mView;
    tulunItem* driveItem;
    QTimer *mTimer;



};

#endif // CANVA_H
