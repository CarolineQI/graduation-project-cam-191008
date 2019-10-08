#include "mdichildwindow.h"

MdiChildWindow::MdiChildWindow(QMenu* itemMenu)
{


    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;

    myItemMenu=itemMenu;
    scene=new DiagramScene(myItemMenu,this);
    scene->setSceneRect(0,0,5000,5000);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    view=new QGraphicsView(scene);
    setCentralWidget(view);

//    m_SceneContral=new QTimer(this);
//    connect(m_SceneContral,SIGNAL(timeout()),scene,SLOT(advance()));
//    m_SceneContral->start(1000/100);

}
void MdiChildWindow::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;
    curFile = tr("document%1.txt").arg(sequenceNumber++);
    setWindowTitle(curFile + "[*]");
//    setWindowFlags(1);

}
