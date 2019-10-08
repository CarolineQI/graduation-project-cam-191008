#include "diagramscene.h"
#include<QGraphicsSceneMouseEvent>
#include<QTimer>

//! [0]
DiagramScene::DiagramScene(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent)
{
    myItemMenu = itemMenu;
   // myMode = MoveItem;
   // myItemType = DiagramItem::;
//    myItemColor = Qt::black;
    myActionType=DiagramItem::ActionType::Active;
    myTLActType=CamItem::ActType::Rotate;
    myTLShapeType=CamItem::TLShapeType::PlaneCam;
    myCDJActType=CDJItem::ActType::MoveVertical;
    myCDJShapeType=CDJItem::CDJShapeType::Roller;
    myDiagramItem=new DiagramItem(myActionType,
                                  myTLActType,
                                  myTLShapeType,
                                  myCDJActType,
                                  myCDJShapeType);
    myCAMPos=QPointF(2500,2500);
    myDiagramItem->setPos(myCAMPos);
    addItem(myDiagramItem);

  //  myDiagramItem->show();
    QTimer* main_timer = new QTimer(this);
    QObject::connect(main_timer, &QTimer::timeout,
            [=]()
    {
        update();
    });
    main_timer->start(50);//0.05秒触发一次

}
//! [0]
