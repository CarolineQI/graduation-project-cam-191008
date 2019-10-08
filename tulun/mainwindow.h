#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QTimer>
#include<QTime>
#include<QMdiSubWindow>
#include"tulunitem.h"
#include<QGridLayout>
#include"canva.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
   // QMdiSubWindow *newwin;
//    QGraphicsScene* scence;
//    QGraphicsView* view;
//    tulunItem* driveItem;
//    QTimer *timer;
    canva* newwin;
    int rotation=10;
    canva* activeCanva() const;
private slots:

    void on_pushButton_clicked();
    void on_jiaolian_clicked();
signals:
    //gvoid addJLItem();
};

#endif // MAINWINDOW_H
