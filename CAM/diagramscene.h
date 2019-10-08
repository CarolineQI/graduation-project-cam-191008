#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include "diagramitem.h"
#include <QGraphicsScene>
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

class DiagramScene:public QGraphicsScene
{

    Q_OBJECT

public:

    explicit DiagramScene(QMenu *itemMenu, QObject *parent = 0);

//    QColor itemColor() const { return myItemColor; }
//    void setItemColor(const QColor &color);

public slots:
    //void setMode(Mode mode);
   // void editorLostFocus(DiagramTextItem *item);

signals:
//    void itemInserted(CamItem *item);
//    void itemSelected(QGraphicsItem *item);

protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) Q_DECL_OVERRIDE;

private:
//    bool isItemChange(int type);

    QMenu *myItemMenu;
   // Mode myMode;
    bool leftButtonDown;
    QPointF startPoint;

//    QColor myItemColor;

    DiagramItem::ActionType myActionType;
    CamItem::ActType myTLActType;
    CamItem::TLShapeType myTLShapeType;
    CDJItem::ActType myCDJActType;
    CDJItem::CDJShapeType myCDJShapeType;

    DiagramItem* myDiagramItem;

    QPointF myCAMPos;
    QPointF myCDJPos;

};

#endif // DIAGRAMSCENE_H
