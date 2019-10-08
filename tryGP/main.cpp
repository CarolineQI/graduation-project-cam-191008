#include "gswidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GSWidget w;
   w.show();
   /* QGraphicsScene scence;
    QGraphicsRectItem *item=new QGraphicsRectItem(0,0,100,100);
    scence.addItem(item);
    qDebug()<<scence.itemAt(50,50,QTransform());
    QGraphicsView view(&scence);
    view.setForegroundBrush(QColor(255,255,0,100));
    view.resize(400,300);
    view.show();
    QGraphicsView view2(&scence);
    view2.resize(400,300);
    view2.show();
    scence.setForegroundBrush(QColor(255,255,0,100));
    scence.setBackgroundBrush(QPixmap(":/25.jpg"));*/


    return a.exec();
}
