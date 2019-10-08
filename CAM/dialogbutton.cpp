#include "dialogbutton.h"
#include "ui_dialogbutton.h"

DialogButton::DialogButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogButton)
{
    ui->setupUi(this);
    //ui->DialogWidget->setStyleSheet("QWidget:hover{background-color: rgb(107, 107, 107);}");
    ui->Button->setStyleSheet("QPushButton{border:none;color:rgb(255, 255, 255);}"
                              "QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}"
                              "QPushButton:pressed{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}");

}
DialogButton::DialogButton(QString str,QIcon icon,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogButton)
{
    ui->setupUi(this);
    setDialogName(str);
    setIcon(icon);
}

DialogButton::~DialogButton()
{
    delete ui;
}

void DialogButton::setDialogName(QString str)
{
    ui->DialogName->setText(str);
}
void DialogButton::setIcon(QIcon icon)
{
    ui->Button->setIcon(icon);

}

void DialogButton::on_Button_pressed()
{
     emit pressed();
}

void DialogButton::on_Button_clicked(bool checked)
{
    emit clicked(checked);
}

