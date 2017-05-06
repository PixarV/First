#ifndef MYSECONDTHREAD_H
#define MYSECONDTHREAD_H

#include <QObject>

class MySecondThread : public QObject
{
    Q_OBJECT
public:
    explicit MySecondThread(QObject *parent = 0);

signals:

public slots:
};

#endif // MYSECONDTHREAD_H