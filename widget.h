#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "bass.h"
#include <QString>
#include <QStringList>
//#include "conio.h"
#include "myfirstthread.h"
#include <QFileDialog>
//#include <QGridLayout>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    QString* filename;
    HSTREAM chan;
    MyFirstThread* thread1;
    MyFirstThread thread2;

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
//    void probe();

private slots:
    void open();
    void controlButtons();
};

#endif // WIDGET_H
