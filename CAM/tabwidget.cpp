#include "tabwidget.h"

tabwidget::tabwidget(QObject *parent)
{
QTabBar *bar = new QTabBar;
bar->setStyle(new CustomTabStyle);
setTabBar(bar);

QWidget *w = new QWidget;
bar->addTab(QIcon(":/cam/resource/start(gray)/startcurrent.png"),"");
w = new QWidget;
bar->addTab(QIcon(":/cam/resource/file(red)/file.png"),"");
}


tabwidget::~tabwidget()
{


}

