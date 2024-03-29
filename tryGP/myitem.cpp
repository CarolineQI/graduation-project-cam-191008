#include "myitem.h"
#include<QPainter>
#include<QCursor>
#include<QKeyEvent>
#include<QGraphicsSceneHoverEvent>
#include<QGraphicsSceneContextMenuEvent>
#include<QMenu>
MyItem::MyItem()
{
    brushColor=Qt::red;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}
QRectF MyItem::boundingRect()const   //返回绘制图形的矩形区域
{

    qreal adjust=0.5;
    return QRectF(-0-adjust,-10-adjust/2,20+adjust,20+adjust);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)//执行实际绘图操作
{
    if(hasFocus())
    {
        painter->setPen(QPen(QColor(255,255,255,200)));
    }else {
        painter->setPen(QPen(QColor(100,100,100,100)));
    }
    painter->setBrush(brushColor);
    painter->drawRect(-10,-10,20,20);
}
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    setCursor(Qt::ClosedHandCursor);
    QGraphicsItem::mousePressEvent(event);
}

void MyItem::keyPressEvent(QKeyEvent *event)
{
//    if(event->key()==Qt::Key_Down)
//    {
//        moveBy(0,10);
//    }
    switch (event->key()) {
    case Qt::Key_1:
    {
        QGraphicsBlurEffect *blurEffect=new QGraphicsBlurEffect;
        blurEffect->setBlurHints(QGraphicsBlurEffect::QualityHint);
        blurEffect->setBlurRadius(8);
        setGraphicsEffect(blurEffect);
        break;
    }
    case Qt::Key_2:
    {
        QGraphicsColorizeEffect *colorizeEffect=new QGraphicsColorizeEffect;
        colorizeEffect->setColor(Qt::white);
        colorizeEffect->setStrength(0.6);
        setGraphicsEffect(colorizeEffect);
        break;
    }
    case Qt::Key_3:
    {
        QGraphicsDropShadowEffect *dropShadowEffect=new QGraphicsDropShadowEffect;
        dropShadowEffect->setColor(QColor(63,63,63,100));
        dropShadowEffect->setBlurRadius(2);
        dropShadowEffect->setOffset(10);
        setGraphicsEffect(dropShadowEffect);
        break;
    }
    case Qt::Key_4:
    {
        QGraphicsOpacityEffect* opacityEffect=new QGraphicsOpacityEffect;
        opacityEffect->setOpacity(0.4);
        setGraphicsEffect(opacityEffect);
        break;
    }
    case Qt::Key_5:
    {
        graphicsEffect()->setEnabled(false);
        break;
    }
    }
//    QGraphicsItem::keyPressEvent(event);
}

void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    setToolTip("lalallala");
}

void MyItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction* moveAction=menu.addAction("move back");
    QAction* selectedAction=menu.exec(event->screenPos());
    if(selectedAction==moveAction)
    {
        setPos(0,0);
    }
}
void MyItem::advance(int phase)
{
    if(!phase)
    {
        return;
    }
    int value=qrand()%100;
    if(value<25)
    {
        setRotation(45);
        moveBy(qrand()%10,qrand()%10);
    }else if(value<50){
        setRotation(-45);
        moveBy(-qrand()%10,-qrand()%10);
    }else if (value<75) {
        setRotation(30);
        moveBy(-qrand()%10,qrand()%10);
    }else {
        setRotation(-30);
        moveBy(qrand()%10,-qrand()%10);
    }

}
