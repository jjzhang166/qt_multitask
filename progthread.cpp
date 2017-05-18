#include "progthread.h"

progThread::progThread(QObject *parent)
    :QThread(parent)
{

}

void progThread::run(){

    while(crtValue < 100){
        crtValue += progMaxValue/100; //步进为 progMaxValue/100
        emit crtProg(crtValue);
        msleep(50);
        qDebug()<<"thread really run";
    }
}

//run()函数是无法直接传递参数的，需要借助其他方法调用
void progThread::startThread(int getMaxValue){
    progMaxValue = getMaxValue;
    if(progMaxValue < 100){
        qDebug("Please input number greater than 100");
        return;
    }
    start();
}
