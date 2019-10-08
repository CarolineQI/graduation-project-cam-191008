#ifndef TULUNITEM_H
#define TULUNITEM_H

#include<QGraphicsItem>
#include<QPainter>
class tulunItem:public QGraphicsItem
{
private:
    QPainter *myPainter;
   // void addItem();
public:
    tulunItem();
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void addItem();
};

#endif // TULUNITEM_H
