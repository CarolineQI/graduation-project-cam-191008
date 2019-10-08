#ifndef GSWIDGET_H
#define GSWIDGET_H

#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
#include<QDebug>
#include<QGraphicsView>
#include"myitem.h"
#include"myview.h"
#include<QTimer>
namespace Ui {
class GSWidget;
}

class GSWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GSWidget(QWidget *parent = 0);
    ~GSWidget();

private:
    Ui::GSWidget *ui;
};

#endif // GSWIDGET_H
