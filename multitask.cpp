#include "multitask.h"
#include "ui_multitask.h"

MultiTask::MultiTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiTask)
{
    thread = new progThread;
    ui->setupUi(this);
    connect(thread,SIGNAL(crtProg(int)),this,SLOT(updateProgValue(int)));
    //接受thread发出的信号crtProg()，执行updateProgValue(),
    //并把crtProg()的crtValue传给updateProgValue()的crtValue
}

MultiTask::~MultiTask()
{
    delete ui;
}

void MultiTask::on_dloadBtn_clicked()
{
    maxValue = ui->lineEdit->text().toInt(nullptr,10); //获取用户设置的最大值
    thread->startThread(maxValue); //启动线程内的方法
    qDebug("maxValue = %d",maxValue);
}

void MultiTask::updateProgValue(int crtValue){
    qDebug("update progress value = %d",crtValue);
    ui->prgBar->setValue(crtValue);
}
