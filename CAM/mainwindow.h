#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QIcon>
#include<QPixmap>
#include<QMdiSubWindow>
#include<QAction>
#include<QToolBar>
#include<QToolButton>
#include<QButtonGroup>
#include<QStackedWidget>
#include<QMenu>
#include<QMenuBar>
#include<QMdiArea>

#include<QVBoxLayout>
#include<QGridLayout>

#include<QListWidgetItem>

#include"diagramscene.h"
#include"diagramitem.h"
#include"mdichildwindow.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
  //  void closeEvent(QCloseEvent *event)Q_DECL_OVERRIDE;

private slots:

    void fileStackWidgetChange(int);
    void newFile();
    void returnButtonPressed();
    void on_tabWidget_tabBarClicked(int index);

//    void updateMenus();
//    void updateWindowMenus();
    MdiChildWindow* createMdiChild();

private:
    Ui::MainWindow *ui;

    int  returnMainWindowButton;
    int  beginButton;
    int  newFileButton;
    int  openFileButton;
    QSize fileButtonSize=QSize(100,50);
    QStackedWidget* m_fileStackWidget;
    QButtonGroup* m_fileButtonGroup;


//    void createToolBox();
//    void createActions();
    void createMenus();
//    void createToolbars();
//    void createStatusBar();
//    QWidget *createCellWidget(const QString &text,
//                              DiagramItem::DiagramType type);

//    QToolButton* creatFileWindowButton(const QString&text, const QString&image,int buttonId);
//     QListWidgetItem*  creatFileWindowButton
//     (const QString&text, const QString&image,int &buttonId);
//    void creatFileWindow();

     // MdiChild* activeMdiChild();


    int lastTadIndex;
    void setCurrentIndex();

    QMenu* itemMenu;

//    QAction *closeAct;
//    QAction *closeAllAct;
//    QAction *tileAct;
//    QAction *cascadeAct;
//    QAction *nextAct;
//    QAction *previousAct;
//    QAction *windowMenuSeparatorAct;

   //********DATA***************


   //********DATA***************

};

#endif // MAINWINDOW_H
