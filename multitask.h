#ifndef MULTITASK_H
#define MULTITASK_H

#include <QWidget>
#include <QString>
#include <QDebug>

#include "ui_multitask.h"
#include "progthread.h"

namespace Ui {
class MultiTask;
}

class MultiTask : public QWidget,private Ui::MultiTask
{
    Q_OBJECT

public:
    explicit MultiTask(QWidget *parent = 0);
    ~MultiTask();

private:
    Ui::MultiTask *ui;
    progThread *thread;

    int crtValue = 0;
    int maxValue = 0;

signals:

private slots:
    void on_dloadBtn_clicked();

    void updateProgValue(int crtValue);
};

#endif // MULTITASK_H
