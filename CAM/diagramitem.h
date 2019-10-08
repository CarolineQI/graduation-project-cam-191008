#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H
#include<QGraphicsItem>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QGraphicsSceneMouseEvent>
#include<QPen>
#include<QtMath>

//! [-1]
class ItemPart:public QGraphicsObject
{
public:
    enum ActType{MoveHorizontal,MoveVertical,Rotate};


    ItemPart(ActType actType,QGraphicsItem*parent=0);
protected:
    ActType myActType;
};
//! [-1]

//! [1]
class JLItem: public QGraphicsObject
{
public:
    JLItem(ItemPart::ActType CDJAT,QGraphicsItem* parent=0);
    QRectF boundingRect()const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem*option,
               QWidget *widget=0)Q_DECL_OVERRIDE;
private:
    ItemPart::ActType myActType;
   const QPen m_JLPen=QPen(QBrush(Qt::gray),1);

};
//![1]

//! [0]

struct PlaneCAMData
{
    //normal planeCAM
    //********DATA**************
    enum upRule{uUniform,uAccelerate,uSinAcc,uCosAcc};
    enum downRule{dUniform,dAccelerate,dSinAcc,dCosAcc};
    double m_fBR;//base circle r
    double m_H;//xing cheng
    int m_nTCAng;//tui cheng ang
    int m_nYXZAng;//yuan xiu zhi ang
    int m_nHCAng;//hui cheng ang
    int m_nJXZAng;//jin xiu zhi ang

    QPointF m_JXZsP;
    QPointF m_TCsP;
    QPointF m_YXZsP;
    QPointF m_HCsP;

    QPointF* m_linePoints[361];
//    QPointF* m_arcPoints[361];

    QVector<QPointF> m_arcPoints;
    upRule m_upRule;
    downRule m_downRule;
    PlaneCAMData::PlaneCAMData(double fBaseR,
                               double H,
                               int nTCAng,
                               int nYXZAng,
                               int nHCAng,
                               int nJXZAng,
                               upRule uR,
                               downRule dR)
    {
        m_fBR=fBaseR;
        m_H=H;
        m_nTCAng=nTCAng;
        m_nYXZAng=nYXZAng;
        m_nHCAng=nHCAng;
        m_nJXZAng=nJXZAng;
        m_upRule=uR;
        m_downRule=dR;

        int JXZsP=0;
        int TCsP=JXZsP+m_nJXZAng;
        int YXZsP=TCsP+m_nTCAng;
        int HCsP=YXZsP+m_nYXZAng;
        for(int i=0;i<=360;i++)
        {
            double x=((double)i/360.0-0.5)*i;
            double y;
            x=i;
            if(i<TCsP)
            {
                y=m_fBR;
            }else if (i<YXZsP){
                y=m_fBR+(i-TCsP)*m_H/float(m_nTCAng);
            }else if (i<HCsP) {
                y=m_fBR+m_H;
            }else{
                y=m_fBR+(1.0-(i-HCsP)/float(m_nHCAng))*m_H;
            }

        m_linePoints[i]=new QPointF(x,y);
        m_arcPoints.push_back(QPointF(cos(M_PI/180.0*i)*m_linePoints[i]->y(),sin(M_PI/180.0*i)*m_linePoints[i]->y()));
        }

        m_JXZsP=QPointF();
        m_TCsP=QPointF();
        m_YXZsP=QPointF();
        m_HCsP=QPointF();

    }
    PlaneCAMData():PlaneCAMData(100,100,90,20,90,160,
                        upRule::uUniform,downRule::dUniform){}


    //********DATA**************
};

class CamItem:public ItemPart
{

public:
//    enum TLActType{Straight,Rotate};
    enum TLShapeType{PlaneCam,CylindricalCam,ConicalCam};

    CamItem(ActType actType,
            TLShapeType TLST,
            PlaneCAMData planeCAMData,
            QGraphicsItem* parent=0);

    QRectF boundingRect()const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget=0)Q_DECL_OVERRIDE;

//    void rotate();

    PlaneCAMData m_pCAMData;
private:
    QGraphicsItem* m_JLItem;
    TLShapeType m_TLShapeType;
    QRectF m_RectF;


    const QPen m_PenTCAct=QPen(QColor(Qt::blue),2,Qt::SolidLine);//tui cheng pen
    const QPen m_PenYXZAct=QPen(QColor(Qt::green),2,Qt::SolidLine);//yuan xiu zhi pen
    const QPen m_PenHCAct=QPen(QColor(Qt::red),2,Qt::SolidLine);//hui cheng pen
    const QPen m_PenJXZAct=QPen(QColor(Qt::yellow),2,Qt::SolidLine);//jinxiuzhi pen
    const QPen m_PenBase=QPen(QBrush(Qt::black),1,Qt::DashLine);//base circle pen


};
//! [0]

//! [2]

struct CDJData
{
    enum  OffsetDir{left,right};//pianjuDirection
    double m_fRollerR;//gun zi ban jing
    OffsetDir m_OffsetDir;
    double m_fOffsetDis;//pianju
    double m_fCenterDis;//zhong xin ju
    double m_fLength;//gan chang
    int m_nH;//xingcheng(straight)/baifu(rotate)

    CDJData::CDJData(double fRollerR,
                     OffsetDir offsetDir,
                     double fOffsetDis,
                     double fCenterDis,
                     double fLength,
                     int nH)
    {
        m_fRollerR=fRollerR;
        m_OffsetDir=offsetDir;
        m_fOffsetDis=fOffsetDis;
        m_fCenterDis=fCenterDis;
        m_fLength=fLength;
        m_nH=nH;
    }

    CDJData():CDJData(20,right,0,0,100,100){}
};

class CDJItem:public ItemPart
{
public:

//    enum CDJActType{Straight,Rotate};
    enum CDJShapeType{Roller,Point,Plane};

    CDJItem(ActType actType,
            CDJShapeType CDJST,
            QPointF endPoint,
            QPointF startPoint=QPointF(0,0),
            CDJData data=CDJData(),
            QGraphicsItem* parent=0);

    QRectF boundingRect()const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget=0)Q_DECL_OVERRIDE;

    CDJData m_CDJData;

private:
    CDJShapeType m_CDJShapeType;
    QPointF m_StartPoint;
    QPointF m_EndPoint;

    QGraphicsItem* myJLItem;

};
//! [2]

//! [3]
class DiagramItem: public QGraphicsObject
{
public:
    enum ActionType{Active,Passive};

    DiagramItem(ActionType actionType,
                CamItem::ActType TLAT,
                CamItem::TLShapeType TLST,
                CDJItem::ActType CDJAT,
                CDJItem::CDJShapeType CDJST,
                QGraphicsItem* parent=0);

     QRectF boundingRect()const Q_DECL_OVERRIDE;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                QWidget *widget=0)Q_DECL_OVERRIDE;

private:
     ActionType myActionType;
     CamItem::ActType myTLActType;
     CamItem::TLShapeType myTLShapeType;
     CDJItem::ActType myCDJActType;
     CDJItem::CDJShapeType myCDJShapeType;

     CamItem* myCamItem;
     JLItem* myCamJLItem;
     CDJItem* myCDJItem;
     JLItem* myCDJJLItem;
protected:
    void advance(int step) Q_DECL_OVERRIDE;
};

//! [3]
#endif // DIAGRAMITEM_H
