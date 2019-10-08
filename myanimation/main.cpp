
// //*****************----------1-------------***********************
//#include<QApplication>
//#include<QPushButton>
//#include<QPropertyAnimation>
//#include<QSequentialAnimationGroup>
//#include<QParallelAnimationGroup>
// int main(int argc, char *argv[])
//{
//   //  QApplication app(argc,argv);
//   //  QPushButton button("Animated Button");
//    // button.show();


//     //********----------1-------------
//  //    QPropertyAnimation animation(&button,"geometry");
// //     animation.setDuration(10000);
// //     animation.setStartValue(QRect(0,0,120,30));
// //    animation.setEndValue(QRect(250,250,200,60));
// //     animation.start();

//     //********----------2-------------
// //    QPropertyAnimation animation(&button,"geometry");
// //     animation.setDuration(2000);
// //     animation.setStartValue(QRect(250,0,120,30));
// //    animation.setEndValue(QRect(250,300,120,30));
// //    animation.setEasingCurve(QEasingCurve::OutBounce);
// //      animation.start();

//    //********-----------3(串行动画组)-------------
// //     //动画1
// //     QPropertyAnimation *animation1=new QPropertyAnimation(&button,"geometry");
// //     animation1->setDuration(2000);
// //     animation1->setStartValue(QRect(250,0,120,30));
// //     animation1->setEndValue(QRect(250,300,120,30));
// //     animation1->setEasingCurve(QEasingCurve::OutBounce);
// //     //动画2
// //     QPropertyAnimation *animation2=new QPropertyAnimation(&button,"geometry");
// //     animation2->setDuration(1000);
// //     animation2->setStartValue(QRect(250,300,120,30));
// //     animation2->setEndValue(QRect(250,300,200,60));
// //     //串行动画组
// //     QSequentialAnimationGroup group;
// //     group.addAnimation(animation1);
// //     group.addAnimation(animation2);
// //     group.start();



//     //********-----------4(并行动画组)-------------
//     QPushButton button1("Animated Button");
//     button1.show();
//     QPushButton button2("Animated Button2");
//     button2.show();

//      //动画1
//      QPropertyAnimation *animation1=new QPropertyAnimation(&button1,"geometry");
//      animation1->setDuration(2000);
//      animation1->setStartValue(QRect(250,0,120,30));
//      animation1->setEndValue(QRect(250,300,120,30));
//      animation1->setEasingCurve(QEasingCurve::OutBounce);
//      //动画2
//      QPropertyAnimation *animation2=new QPropertyAnimation(&button2,"geometry");
//      animation2->setDuration(2000);
//      animation2->setStartValue(QRect(400,300,120,30));
//      animation2->setEndValue(QRect(400,300,200,60));
//      //并行动画组
//      QParallelAnimationGroup group;
//      group.addAnimation(animation1);
//      group.addAnimation(animation2);
//      group.start();


//    return app.exec();
//}



#include<QApplication>
#include<QGraphicsScene>
#include<QGraphicsView>
#include"myitem.h"
#include<QPropertyAnimation>

 int main(int argc, char *argv[])
{
     QApplication app(argc,argv);
     QGraphicsScene scene;
     scene.setSceneRect(-200,-150,400,300);
     MyItem *item=new MyItem;
     scene.addItem(item);

     QGraphicsView view;
     view.setScene(&scene);
     view.show();

     //为图形项的rotation属性创建动画
     QPropertyAnimation *animation =new QPropertyAnimation(item,"rotation");
     animation->setDuration(2000);
     animation->setStartValue(0);
     animation->setEndValue(360);
    animation->start(QAbstractAnimation::KeepWhenStopped);
    return app.exec();
}
