#ifndef DIALOGBUTTON_H
#define DIALOGBUTTON_H

#include <QWidget>
#include<QColorDialog>
#include<QDebug>
namespace Ui {
class DialogButton;
}

class DialogButton : public QWidget
{
    Q_OBJECT

public:
    DialogButton(QWidget *parent = 0);
    DialogButton(QString str,QIcon icon,QWidget *parent = 0);
    ~DialogButton();
    void setDialogName(QString str);
    void setIcon(QIcon icon);

private slots:
    void on_Button_pressed();

    void on_Button_clicked(bool checked);

private:
    Ui::DialogButton *ui;
signals:
    void pressed();
    void clicked(bool is_click);
};

#endif // DIALOGBUTTON_H
