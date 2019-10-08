#include "diagramitem.h"
#include<QPainter>
#include<QTimer>
//! [-1]
ItemPart::ItemPart(ActType actType, QGraphicsItem *parent)
    :QGraphicsObject(parent)
{
    myActType=actType;
}
//! [-1]

//! [0]
CamItem::CamItem(ActType actType,
                 TLShapeType TLST,
                 PlaneCAMData planeCAMData,
                 QGraphicsItem* parent)
    :ItemPart(actType,parent)
{
    m_pCAMData=planeCAMData;
    m_TLShapeType=TLST;
}
QRectF CamItem::boundingRect()const
{
    return m_RectF;
}
void CamItem::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
   // myJLItem=new JLItem(myActType,this);
    painter->setPen(QPen(Qt::blue,2));
    painter->setBrush(Qt::NoBrush);
    switch (m_TLShapeType) {
    case TLShapeType::PlaneCam:
    {
        //draw base circle
        painter->setPen(m_PenBase);
        painter->drawEllipse(QPointF(0,0),m_pCAMData.m_fBR,m_pCAMData.m_fBR);

        painter->setPen(m_PenHCAct);
        painter->drawLines(m_pCAMData.m_arcPoints);

        painter->setPen(QPen(QBrush(Qt::blue),1,Qt::DashLine));
        painter->drawLine(QPointF(0,0),QPointF(0,0));
        break;
    }
    case TLShapeType::CylindricalCam:
    {
        painter->drawRect(-200,-400,200,400);
        break;
    }
    case TLShapeType::ConicalCam:
       {
        static const QPointF points[4] = {
             QPointF(-10.0, -80.0),
             QPointF(-20.0, -10.0),
             QPointF(80.0, 30.0),
             QPointF(90.0, 70.0)
         };
         painter->drawConvexPolygon(points, 4);
        break;
    }

    default:
        break;
    }
}

//void CamItem::rotate()
//{
////    QParallelAnimationGroup *parallelAnimation=new QParallelAnimationGroup(this);
//    QPropertyAnimation* animation=new QPropertyAnimation(this,"rotation");
//    animation->setDuration(2000);
//    animation->setStartValue(0);
//    animation->setEndValue(360);
//    animation->start();

//}
//! [0]

//! [1]
JLItem::JLItem(ItemPart::ActType actType, QGraphicsItem *parent)
    :QGraphicsObject(parent){
    myActType=actType;
}
QRectF JLItem::boundingRect()const
{
    return QRectF(-25,-25,50,50);
}
void JLItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(m_JLPen);
    painter->setBrush(Qt::white);
    switch (myActType) {
    case ItemPart::ActType::MoveHorizontal:
        painter->drawLine(QPointF(-25,0),QPointF(25,0));
        for(float left=-25;left<25;left+=5)
        {
             painter->drawLine(QPointF(left,-5),QPointF(left+5,0));
        }
        break;
    case ItemPart::ActType::MoveVertical:
        painter->drawLine(QPointF(-15,-25),QPointF(-15,25));
        painter->drawLine(QPointF(15,-25),QPointF(15,25));
        for(float up=-25;up<25;up+=5)
        {
             painter->drawLine(QPointF(-15,up),QPointF(-20,up+5));
             painter->drawLine(QPointF(20,up),QPointF(15,up+5));
        }
        break;
    case ItemPart::ActType::Rotate:
        painter->drawLine(QPointF(0,0),QPointF(-20,20));
        painter->drawLine(QPointF(0,0),QPointF(20,20));
        painter->drawEllipse(QPointF(0,0),qreal(8),qreal(8));
        painter->drawLine(QPointF(-25,20),QPointF(25,20));
        for(float left=-25;left<25;left+=5)
        {
             painter->drawLine(QPointF(left,25),QPointF(left+5,20));
        }
        break;
    default:
        break;
    }

}

//![1]


//! [2]
CDJItem::CDJItem(ActType actType,
                 CDJShapeType CDJST,
                 QPointF endPoint,
                 QPointF startPoint,
                 CDJData data,
                 QGraphicsItem* parent)
    :ItemPart(actType,parent)
{
    m_CDJShapeType=CDJST;
    m_StartPoint=startPoint;
    m_EndPoint=endPoint;
    m_CDJData=data;
//    myJLItem=new JLItem(myActType,this);
//    myJLItem->setPos(myStartPoint);
}
QRectF CDJItem::boundingRect()const
{
    return QRectF();
}
void CDJItem::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(Qt::black,2));
    painter->setBrush(Qt::NoBrush);
    painter->drawLine(m_StartPoint,m_EndPoint);

    switch (m_CDJShapeType) {
    case CDJShapeType::Roller:
        painter->drawEllipse(m_EndPoint,5,5);
        painter->drawEllipse(m_EndPoint,10,10);
        break;
    case CDJShapeType::Point:
        painter->setPen(QPen(Qt::black,2));
        painter->drawPoint(m_EndPoint);
        break;
    case CDJShapeType::Plane:
        painter->drawLine(QPointF(m_EndPoint.x()-50,m_EndPoint.y()) ,QPointF(m_EndPoint.x()+50,m_EndPoint.y()));
        break;
    default:
        break;
    }
}

//! [2]


//! [3]
DiagramItem:: DiagramItem(ActionType actionType,
                          CamItem::ActType TLAT,
                          CamItem::TLShapeType TLST,
                          CDJItem::ActType CDJAT,
                          CDJItem::CDJShapeType CDJST,
                          QGraphicsItem* parent)
    :QGraphicsObject(parent)
{

    myActionType=actionType;
    myTLActType=TLAT;
    myTLShapeType=TLST;
    myCDJActType=CDJAT;
    myCDJShapeType=CDJST;

//    PlaneCAMData planeCAMData();
    myCamItem=new CamItem(myTLActType,
                          myTLShapeType,
                          PlaneCAMData(),
                          this);
    myCamJLItem=new JLItem(myTLActType,this);
    myCDJItem=new CDJItem(myCDJActType,
                          myCDJShapeType,
                          QPoint(0,150),
                          QPoint(0,0),
                          CDJData(),
                          this);
    myCDJJLItem=new JLItem(myCDJActType,this);

    myCamItem->setPos(0,0);
    myCamJLItem->setPos(0,0);
    myCDJItem->setPos(0,-260);
    myCDJJLItem->setPos(0,-260);
    myCamItem->setRotation(-(90+myCamItem->m_pCAMData.m_nJXZAng));


    QParallelAnimationGroup* animationGroup=new QParallelAnimationGroup(this);

    QPropertyAnimation *myCamAnimation=new QPropertyAnimation(myCamItem,"rotation");
    myCamAnimation->setStartValue(0);
    myCamAnimation->setEndValue(360);
    myCamAnimation->setEasingCurve(QEasingCurve::Linear);
    animationGroup->addAnimation(myCamAnimation);

    QPropertyAnimation* myCDJAnimation=new QPropertyAnimation(myCDJItem,"pos");
    myCDJAnimation->setStartValue(QPoint(0,-400));
    myCDJAnimation->setEndValue(QPoint(0,-200));
    myCDJAnimation->setEasingCurve(QEasingCurve::SineCurve);
    animationGroup->addAnimation(myCDJAnimation);


    for(int i=0;i<animationGroup->animationCount();++i)
    {
        QPropertyAnimation*anim
                =qobject_cast<QPropertyAnimation*>(animationGroup->animationAt(i));
        //anim->setEasingCurve(QEasingCurve::Linear);
        anim->setDuration(2000);
    }

    //***************setLoopCount*************************
    //By default this value is 1,
    //indicating that the animation should run once only, and then stop.
    //By changing it you can let the animation loop several times.
    //With a value of 0, the animation will not run at all,
    //and with a value of -1, the animation will loop forever until stopped.
    //****************************************************

//    animationGroup->setLoopCount(-1);
//    animationGroup->start();


}

QRectF DiagramItem::boundingRect()const
{
    return QRectF();
}
void DiagramItem::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void DiagramItem::advance(int step)
{
    if(!step)return;
    //static int timeInt=0;
    int ad=1;
    myCamItem->setRotation(myCamItem->rotation()+ad);

//    int x=myCDJItem->x();
//    int y=myCamItem->m_pCAMData.m_linePoints[myCamItem->rotation()];
//    myCDJItem->setPos(x,y);
}
//! [3]
