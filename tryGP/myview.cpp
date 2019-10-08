#include "myview.h"
#include<QMouseEvent>
#include<QGraphicsItem>
#include<QDebug>
MyView::MyView(QWidget *parent):QGraphicsView(parent)
{

}

void MyView::mousePressEvent(QMouseEvent *event)
{
    QPoint viewPos=event->pos();
    qDebug()<<"viewPos:"<<viewPos;
    QPointF scenePos=mapToScene(viewPos);
    qDebug()<<"scenePos:"<<scenePos;
    QGraphicsItem *item=scene()->itemAt(scenePos,QTransform());
    item->setZValue(1);
    if(item)
    {
        QPointF itemPos=item->mapFromScene(scenePos);
        qDebug()<<"itemPos:"<<itemPos;
    }
   QGraphicsView::mouseReleaseEvent(event);

}

void MyView::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        scale(1.2,1.2);
        break;
    case Qt::Key_Minus:
        scale(1/1.2,1/1.2);
        break;
    case Qt::Key_Right:
        rotate(30);
        break;
    default:
        break;
    }
    QGraphicsView::keyPressEvent(event);
}

