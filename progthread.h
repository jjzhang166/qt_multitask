#ifndef PROGTHREAD_H
#define PROGTHREAD_H

#include <QThread>
#include <QDebug>

class progThread : public QThread
{
    Q_OBJECT
public:
    explicit progThread(QObject *parent = 0);
    void startThread(int getMaxValue);

private:
    int crtValue = 0;
    int progMaxValue = 0;

protected:
    void run() override;

signals:
    void crtProg(int crtValue);

};

#endif // PROGTHREAD_H
