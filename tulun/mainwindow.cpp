#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextEdit>
#include<QLabel>
#include"canva.h"
#include<QVBoxLayout>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

}

MainWindow::~MainWindow()
{
    delete ui;
}
canva* MainWindow::activeCanva()const
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
      {  return qobject_cast<canva *>(activeSubWindow);}
    return 0 ;
}
void MainWindow::on_pushButton_clicked()
{
    canva* newwin = new canva;
    newwin->setWindowTitle("test");
    newwin->setAttribute(Qt::WA_DeleteOnClose);
    newwin->resize(200,200);
    ui->mdiArea->addSubWindow(newwin);
    newwin->show();     //在非构造函数不加show()，不显示
}

void MainWindow::on_jiaolian_clicked()
{
     //activeCanva()->SaddJLItem();
        emit activeCanva()->addJLItem();
        qDebug()<<"here";

}
