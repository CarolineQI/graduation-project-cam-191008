#include "canva.h"
#include "ui_canva.h"

canva::canva(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::canva)
{
    ui->setupUi(this);
    mView=new QGraphicsView(ui->centralwidget);
    //mView->resize(500,500);

    mScence=new QGraphicsScene(this);

    driveItem=new tulunItem;
    driveItem->addItem();
    mScence->addItem(driveItem);

   // connect(this,SIGNAL(addJLItem()),this,SLOT(SaddJLItem()));
    mView->setScene(mScence);
    setCentralWidget(mView);
    mView->show();

}

canva::~canva()
{
    delete ui;
}
void canva::SaddJLItem()
{
  // driveItem=new tulunItem;
   tulunItem* ll=new tulunItem;
  // mScence->addItem(driveItem);
   mScence->addItem(ll);
}
