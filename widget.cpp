#include "widget.h"
#include "ui_widget.h"
#include "bass.h"
//#pragma comment (lib, "bass.lib")

#include <iostream>

using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

    BASS_Init(-1,44100,BASS_DEVICE_3D,0,NULL);  // номер устройства (-1 - по умолчанию)

//    char filename[] = "Old_Friends.mp3";

    char filename[] = "C:\\Qt_project\\diplom_first\\Old_Friends.mp3";
//    char *a=filename.c_str();
    HSTREAM chan = BASS_StreamCreateFile(FALSE, filename, 0, 0, 0);


//    HSAMPLE sample = BASS_SampleLoad(FALSE, filename, 0, 0, 1, BASS_SAMPLE_3D);
//    HCHANNEL channel = BASS_SampleGetChannel(sample, FALSE);
//    cout << "heu" << endl;
    BASS_ChannelPlay(chan, FALSE);
    while (BASS_ChannelIsActive(chan) != BASS_ACTIVE_STOPPED) {
      Sleep(2000);
    }

//    if (!) {
//        cout << "hui";
//    } else {
//        cout << "heu";
//    }
    ui->setupUi(this);
    ui->probe->setText("hey");


    BASS_Free(); // освобождает текущее устройство.
}

Widget::~Widget()
{
    delete ui;
}
