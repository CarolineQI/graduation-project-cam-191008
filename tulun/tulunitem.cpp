#include "tulunitem.h"
#include<QImage>
tulunItem::tulunItem()
{

   // myPainter->save();

}

QRectF tulunItem::boundingRect()const
{
    return QRectF(0,0,200,200);
}

void tulunItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{ 
    QImage tulun(100,100,QImage::Format_ARGB32);
     painter->begin(&tulun);
   // qreal penWith=1;
   // QPen pen(Qt::NoBrush,penWith,Qt::SolidLine);
    painter->setPen(QPen(QColor(200,50,50)));
    painter->drawArc(0,0,50,50,0,360*16);
    painter->setPen(QPen(QColor(50,200,50)));
    painter->drawRect(0,0,50,50);
      painter->end();
   // QBrush brush(Qt::red);
   // painter->fillRect(QRect(0,0,200,200), brush);

}

void tulunItem::addItem()
{
//    myPainter->setPen(QPen(QColor(200,50,50)));
//    myPainter->drawArc(0,0,200,200,0,360*16);
//    myPainter->setPen(QPen(QColor(50,200,50)));
//    myPainter->drawRect(0,0,200,200);
}
