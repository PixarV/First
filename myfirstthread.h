#ifndef MYFIRSTTHREAD_H
#define MYFIRSTTHREAD_H

#include <QThread>
//#include <QStringList>
#include "bass.h"

//class MyFirstThread : public QThread
class MyFirstThread : public QObject
{
    Q_OBJECT

    int count;
    QStringList files;
    HSTREAM stream;

public:

    bool isPaused;
    bool isNext;
    MyFirstThread();
    void initialize(QStringList);
    void run();
    void stop();
    void pause();
    void next();
    void setCount(int);
    int getCount();
    HSTREAM getStream();

signals:
    void bla();
public slots:
    void slot1();


};

#endif // MYFIRSTTHREAD_H
