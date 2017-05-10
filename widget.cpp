#include "widget.h"
#include "ui_widget.h"
#include "bass.h"
//#pragma comment (lib, "bass.lib")

#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent)
//    ui(new Ui::Widget)
{
//    BASS_Init(-1,44100,BASS_DEVICE_3D,0,NULL);  // номер устройства (-1 - по умолчанию)

    QGridLayout* grid = new QGridLayout();
    QPushButton* play = new QPushButton("play");
    QPushButton* stop = new QPushButton("stop");
    QPushButton* pause = new QPushButton("pause");
    QPushButton* next = new QPushButton("next");
    QPushButton* prev = new QPushButton("prev");
    QPushButton* open = new QPushButton("open");
    grid->addWidget(play, 0, 0);
    grid->addWidget(stop, 1, 0);
    grid->addWidget(pause, 2, 0);
    grid->addWidget(next, 3, 0);
    grid->addWidget(prev, 4, 0);
    grid->addWidget(open, 5, 0);
    setLayout(grid);

    thread1 = new MyFirstThread();

    connect(play, SIGNAL(clicked()), this, SLOT(controlButtons()));
    connect(stop, SIGNAL(clicked()), this, SLOT(controlButtons()));
    connect(pause, SIGNAL(clicked()), this, SLOT(controlButtons()));
    connect(next, SIGNAL(clicked()), this, SLOT(controlButtons()));
    connect(prev, SIGNAL(clicked()), this, SLOT(controlButtons()));

    connect(open, SIGNAL(clicked()), this, SLOT(open()));



}

Widget::~Widget()
{
    delete ui;
}

//void Widget::play() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());
//    thread1.start(); // добавить про если нет песен

//    BASS_Free(); // освобождает текущее устройство.
//}

void Widget::controlButtons() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    QString text = button->text();

    if (!QString::compare(text, "play")) { // добавить про если нет песен

        thread1->start();
    } else if (!QString::compare(text, "stop")) {
        thread1->stop();
    } else if (!QString::compare(text, "pause")) {
        thread1->pause();
    } else if (!QString::compare(text, "next")) {
        thread1->next();
    }
}

void Widget::open() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());

    QStringList files = QFileDialog::getOpenFileNames(this, "Выберите файлы", "/home", "*.mp3 *.wav"); // что может быть вместо /home

    if (files.length() > 0) {
       thread1->initialize(files);
       thread1->start();
    }
}

