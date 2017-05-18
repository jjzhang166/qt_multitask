#ifndef PROGDLG_H
#define PROGDLG_H

#include <QDialog>
#include "progthread.h"

namespace Ui {
class progDlg;
}

class progDlg : public QDialog
{
    Q_OBJECT

public:
    explicit progDlg(QWidget *parent = 0);
    ~progDlg();

private slots:
    void on_nextBtn_clicked();
    void getSetValue(int sendSetValue);

private:
    Ui::progDlg *ui;
    progThread dProgThread;

    int maxValue;

    void startProgThread(int maxValue);

};

#endif // PROGDLG_H
