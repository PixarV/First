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

    connect(play, SIGNAL(clicked()), this, SLOT(play()));
    connect(stop, SIGNAL(clicked()), this, SLOT(stop()));
    connect(pause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(next, SIGNAL(clicked()), this, SLOT(next()));
    connect(prev, SIGNAL(clicked()), this, SLOT(prev()));

    connect(open, SIGNAL(clicked()), this, SLOT(open()));



}

Widget::~Widget()
{
    delete ui;
}

void Widget::play() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());
//    thread1.start(); // добавить про если нет песен

//    BASS_Free(); // освобождает текущее устройство.
}

void Widget::probe() {

}

void Widget::stop() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());
//    thread1.stop();
}

void Widget::pause() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());
//     HSTREAM stream = thread1.getStream();
//     BASS_ChannelStop(stream);
//    thread1.isPaused = true;
//    thread1.pause();
}

void Widget::open() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());

    QStringList files = QFileDialog::getOpenFileNames(this, "Выберите файлы", "/home", "*.mp3 *.wav"); // что может быть вместо /home

//    thread1.setCount(0);
    if (files.length() > 0) {
       thread1.initialize(files);
    }
}

void Widget::next() {
//    QPushButton* button = qobject_cast<QPushButton*>(sender());
//    thread1.isNext = true;
//    thread1.next();
//    int count = thread1.getCount();
//    HSTREAM stream = thread1.getStream();
//    BASS_StreamFree(stream);
//    thread1.setCount(++count); // добавить для 0
//    thread1.start();
}

