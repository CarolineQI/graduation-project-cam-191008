#ifndef MDICHILDWINDOW_H
#define MDICHILDWINDOW_H

#include <QMainWindow>
#include"diagramscene.h"
#include"diagramitem.h"
#include<QGraphicsView>
#include<QTimer>
class MdiChildWindow:public QMainWindow
{
public:
    explicit MdiChildWindow(QMenu* itemMenu);
    void newFile();
    QGraphicsView* view;
    DiagramScene* scene;

//    bool loadFile(const QString &fileName);
//    bool save();
//    bool saveAs();
//    bool saveFile(const QString &fileName);
//    QString userFriendlyCurrentFile();
//    QString currentFile() { return curFile; }

//protected:
//    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

//private slots:
//    void documentWasModified();

private:
//    bool maybeSave();
//    void setCurrentFile(const QString &fileName);
//    QString strippedName(const QString &fullFileName);

    QString curFile;
    bool isUntitled;
    QMenu* myItemMenu;
    QTimer* m_SceneContral;
};

#endif // MDICHILDWINDOW_H
