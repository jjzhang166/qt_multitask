#include "progdlg.h"
#include "ui_progdlg.h"

progDlg::progDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::progDlg)
{
    ui->setupUi(this);
    dProgThread = new progThread();
    connect(dProgThread,SIGNAL(progThread::sendCrtValue(int)),ui->progressBar,SLOT(setValue(int)));
}

progDlg::~progDlg()
{
    delete ui;
}



void progDlg::on_nextBtn_clicked()
{
    this->close();
}

void progDlg::getSetValue(int sendSetValue){
    maxValue = sendSetValue;
}

void progDlg::startProgThread(int maxValue){
    ui->nextBtn->setEnabled(false);
    dProgThread->startThread(maxValue);
}
