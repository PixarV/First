#ifndef MYFIRSTTHREAD_H
#define MYFIRSTTHREAD_H

#include <QThread>
//#include <QStringList>
#include "bass.h"

class MyFirstThread : public QThread
//class MyFirstThread : public QObject
{
//    Q_OBJECT

    int count;
    QStringList files;
    HSTREAM stream;

public:
    MyFirstThread();

    void initialize(QStringList);
    void run();
    void stop();
    void pause();
    void next();
    void prev();

    void setCount(int);
    int getCount();
    HSTREAM getStream();
    static void CALLBACK endPlay(HSYNC handle, DWORD channel, DWORD data, void* user);
    void probe();

public slots:



};

#endif // MYFIRSTTHREAD_H
