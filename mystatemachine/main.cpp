#include<QApplication>
#include<QPushButton>
#include<QState>
#include<QStateMachine>
#include<QFinalState>

#include<QSignalTransition>
#include<QPropertyAnimation>

#include<QMessageBox>
#include<QObject>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QPushButton button("State Machine");
//    //创建状态机和三个状态，并将三个状态添加到状态机中
//    QStateMachine machine;
//    QState *s1=new QState(&machine);
//    QState *s2=new QState(&machine);
//    QState *s3=new QState(&machine);

//   // QFinalState *s4=new QFinalState(s3);
//    //QObject::connect(s3,&QState::entered,&button,&QPushButton::showMinimized);

//    //为按钮部件的geometry属性分配一个值，当进入该状态时会设置该值
//    s1->assignProperty(&button,"geometry",QRect(100,100,120,50));
//    s2->assignProperty(&button,"geometry",QRect(300,100,120,50));
//    s3->assignProperty(&button,"geometry",QRect(200,200,120,50));
//    //----------------1-----------------------
////    //使用按钮部件的单击信号来完成三个状态的切换
////    s1->addTransition(&button,SIGNAL(clicked()),s2);
////    s2->addTransition(&button,SIGNAL(clicked()),s3);
////    s3->addTransition(&button,SIGNAL(clicked()),s1);
//    //----------------2------------------------
//    QSignalTransition *transition1=s1->addTransition(&button,
//                                                     &QPushButton::clicked,s2);
//    QSignalTransition *transition2=s2->addTransition(&button,
//                                                     &QPushButton::clicked,s3);
//    QSignalTransition *transition3=s3->addTransition(&button,
//                                                     &QPushButton::clicked,s1);
//    QPropertyAnimation *animation=new QPropertyAnimation(&button,"geometry");


//    transition1->addAnimation(animation);
//    transition2->addAnimation(animation);
//    transition3->addAnimation(animation);

   QMessageBox *messabgBox=new QMessageBox;
   messabgBox->addButton(QMessageBox::Ok);
   messabgBox->setText("Button geometry has been set!");
   messabgBox->setIcon(QMessageBox::Information);
   QState *s1=new QState();
   QState *s2=new QState();
   s2->assignProperty(&button,"geometry",QRectF(0,0,50,50));
   QObject::connect(s2,&QState::entered,messabgBox,&QMessageBox::exec);
   s1->addTransition(&button,&QPushButton::clicked,s2);

    //设置状态机的初始状态并启动状态机
    //machine.setInitialState(s1);
   // machine.start();
    button.show();
    return app.exec();
}
