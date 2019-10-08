#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QImage>
#include<QLabel>
#include<QIcon>
#include<QListWidgetItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("HUST CAD");
    setWindowIcon(QIcon(":/cam/resource/HUST.png"));
    creatFileWindow();
    //menuWidget

    ui->buildButton->setIcon(QIcon(":/cam/resource/start(gray)/build.png"));
    ui->openButton->setIcon(QIcon(":/cam/resource/start(gray)/open.png"));
    ui->saveButton->setIcon(QIcon(":/cam/resource/start(gray)/save.png"));
    ui->saveAsButton->setIcon(QIcon(":/cam/resource/start(gray)/saveasMain.png"));
    ui->beginwidget-> setStyleSheet("QPushButton:hover{background-color: rgb(180, 180, 180);border:rgb(180, 180, 180);}"
                                    "QPushButton:checked{background-color: rgb(180, 180, 180);border:rgb(180, 180, 180);}");
    ui->tabWidget->setStyleSheet("QTabBar::tab {"
                                 "border-color: black; "
                                 "border-width: 3px; "
                                 "border-bottom:none; "
                                 "border-top-left-radius: 6px; "
                                 "border-top-right-radius: 6px; "
                                 "background-color: rgb(244, 245, 242); "
                                 "color:black; "
                                 "min-width:30ex;"
                                 "min-height:10ex;}"
                                "QTabBar::tab:!selected{ "
                                "background:none;"
                                "color:black; "
                                "border:none; }"
                                "QTabBar::tab:selected{"
                                "background: rgb(244, 245, 242);} "
                                " QTabWidget::pane { "
                                " border:rgb(244, 245, 242)"
                                 "background-color: rgb(244, 245, 242);}"
                                 "QTabWidget::tab-bar { background:none;}" );



     ui->stackedWidget->setCurrentIndex(1);
    connect(ui->buildButton,&QPushButton::clicked,this,&MainWindow::newFile);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileStackWidgetChange(int id)
{
   ui->fileStackedWidget->setCurrentIndex(id); 
//   ui->fileButtonListWidget->currentItem()->setBackgroundColor(QColor(226, 226, 226));

}
void MainWindow::newFile()
{


    MdiChildWindow *child = createMdiChild();
    child->resize(400,400);
    child->setWindowModality(Qt::WindowModal);
    child->newFile();
    child->show();
}

void MainWindow::returnButtonPressed()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->fileStackedWidget->setCurrentWidget(0);
    setCurrentIndex();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    lastTadIndex=ui->tabWidget->currentIndex();
    if(index==0)
    {
        ui->fileStackedWidget->setCurrentWidget(ui->beginFilePage);
        ui->stackedWidget->setCurrentWidget(ui->filePage);
    }
}

MdiChildWindow* MainWindow::createMdiChild()
{
    MdiChildWindow *child = new MdiChildWindow(itemMenu);
    ui->mdiArea->addSubWindow(child);
    return child;
}

QListWidgetItem* MainWindow::creatFileWindowButton
(const QString &text, const QString &image, int& buttonId)
{
    static int i=0;
    QListWidgetItem* item=new QListWidgetItem;
    item->setSizeHint(fileButtonSize);
    item->setIcon(QIcon(QPixmap(image)));
    item->setToolTip(text);
    ui->fileButtonListWidget->addItem(item);
    buttonId=i++;
    return item;
}

void MainWindow::creatFileWindow()
{

    //![0] main
     ui->returnPushButton->setStyleSheet("QPushButton{background-color:rgb(230, 230,230);}");
     ui->returnPushButton->setIconSize(QSize(100,100));
     ui->returnPushButton->setIcon(QIcon(":/cam/resource/start(gray)/return.png"));
     ui->returnPushButton->setCheckable(true);
     ui->returnPushButton->setToolTip("Return To MainWindow");
      creatFileWindowButton(tr("Quick Operating"),
                            ":/cam/resource/start(gray)/start.png",
                            beginButton);
      creatFileWindowButton(tr("Build New File"),
                            ":/cam/resource/start(gray)/newfile.png",
                            newFileButton);
      creatFileWindowButton(tr("Open File"),
                            ":/cam/resource/start(gray)/openfile.png",
                            openFileButton);
      connect(ui->returnPushButton,SIGNAL(pressed()),
              this,SLOT(returnButtonPressed()));
      connect(ui->fileButtonListWidget,SIGNAL(currentRowChanged(int)),
            this,SLOT(fileStackWidgetChange(int)));
      ui->fileButtonListWidget->setIconSize(fileButtonSize);
      ui->fileButtonListWidget->setStyleSheet(
                  "QListWidget::Item:hover{background:lightgray; }"
                  "QListWidget::item:selected{background-color:rgb(230, 230,230);}"
                  );
      //![0]

}

void MainWindow::createMenus()
{
    itemMenu=menuBar()->addMenu(tr("Item"));
   // itemMenu->addAction();
//    itemMenu->addSeparator();
}


void MainWindow::setCurrentIndex()
{
    ui->tabWidget->setCurrentIndex(lastTadIndex);
}
