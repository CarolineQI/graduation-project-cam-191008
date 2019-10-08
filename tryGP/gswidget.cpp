#include "gswidget.h"
#include "ui_gswidget.h"
#include<QTime>
GSWidget::GSWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GSWidget)
{
    ui->setupUi(this);

   QGraphicsScene* scence=new QGraphicsScene(this);
  //  QGraphicsRectItem *item=new QGraphicsRectItem(0,0,100,100);
//    MyItem *item=new MyItem;
//    scence->addItem(item);
//    qDebug()<<scence->itemAt(50,50,QTransform());
//    QGraphicsView *view = new QGraphicsView(scence,this);
//    view->setForegroundBrush(QColor(255,255,0,100));
//    view->setBackgroundBrush(QPixmap(":/25.png"));
//    view->resize(400,300);
//    view->show();
//   QGraphicsView* view2=new QGraphicsView(scence,this);
//    view2->resize(400,300);
//    view2->show();
//    scence->setForegroundBrush(QColor(255,255,0,100));
//    scence->setBackgroundBrush(QPixmap(":/25.jpg"));


//   MyItem *item=new MyItem;
//   //item->setZValue(1);
//   scence->addItem(item);
//   item->setPos(10,10);
//   QGraphicsRectItem *rectItem=scence->addRect(QRect(0,0,100,100),
//                                               QPen(Qt::blue),QBrush(Qt::green));
//    rectItem->setPos(20,20);

//    item->setParentItem(rectItem);
//    rectItem->setRotation(45);
//    MyView *view=new MyView;
//    view->setScene(scence);
//    view->setForegroundBrush(QColor(255,255,0,100));
//    view->setBackgroundBrush(QPixmap(":/25.png"));
//    view->resize(400,300);
//    view->show();


  qsrand( QTime(0,0,0).secsTo(QTime::currentTime()) );
  scence->setSceneRect(-200,-150,400,300);
  for(int i=0;i<5;i++)
  {
      MyItem *item=new MyItem;
      item->setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
      item->setPos(i*50-90,-50);
      scence->addItem(item);
  }
     MyView *view=new MyView;
     view->setScene(scence);
     //view->setForegroundBrush(QColor(255,255,0,100));
     view->setBackgroundBrush(QPixmap(":/25.png"));
    // view->resize(400,300);
     view->show();

     QTimer* timer=new QTimer(this);
     QObject::connect(timer,&QTimer::timeout,scence,&QGraphicsScene::advance);
             timer->start(300);

}

GSWidget::~GSWidget()
{
    delete ui;
}
