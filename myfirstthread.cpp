#include "myfirstthread.h"
#include <iostream>

using namespace std;

/* Поток предназначается для всего воспроизведения, а не для каждой отдельной песни
 * Должен быть список композиций для воспроизведения (путь к файлу)
 * Их количество
 * вопроизведение не замкнуто (исключение: повтор)
 * режимы воспроизведения вероятно реализуются здесь же.
 */

MyFirstThread::MyFirstThread()
{
    BASS_Init(-1,44100,BASS_DEVICE_3D,0,NULL);  // номер устройства (-1 - по умолчанию)

    // не забыть в конце про BASS_Free();

    isPaused = false;
    isNext = false;
//    filename = new QString("C:\\Qt_project\\diplom_first\\Old_Friends.mp3");
//    stream = BASS_StreamCreateFile(FALSE, filename->toStdString().c_str(), 0, 0, 0); // идентификатор потока
//    connect(this, SIGNAL(bla(int)), this, SLOT(slot1()));
}
void MyFirstThread::initialize(QStringList files) {
//    count = files.length();
    count = 0;
    this->files = files;
    BASS_StreamFree(stream);
//    this->start();
}

void MyFirstThread::run() {
/* BASS_ACTIVE_STOPPED = 0
 * BASS_ACTIVE_PLAYING = 1;
 * BASS_ACTIVE_PAUSED = 3; */


    cerr << "hey" << endl;
//    isPaused = false;
//    isNext = false;

    if (!BASS_ChannelPlay(stream, FALSE)) {

        QString* filename = new QString(files.at(count));
        stream = BASS_StreamCreateFile(FALSE, filename->toStdU16String().c_str(), 0, 0, BASS_UNICODE); // идентификатор потока
    }
        BASS_ChannelPlay(stream, FALSE);

        while(BASS_ChannelIsActive(stream) != BASS_ACTIVE_STOPPED) {

        }

//    emit MyFirstThread::bla();
    if (!isNext) {
          // здесь также isPaused isStopped
//        this->Suspend();
//        BASS_StreamFree(stream);
//        count++;

//        start();

      }
//

}

void MyFirstThread::stop() {
    BASS_StreamFree(stream); // освобождаем поток

}

void MyFirstThread::pause() {
//    cerr << "2";
//    isPaused = false;
    BASS_ChannelStop(stream); // пауза (lol)
}

void MyFirstThread::next() {
    BASS_StreamFree(stream); // освобождаем поток
    cerr << count;
    if (count != files.length() - 1) {
        count++;
    } else {
        count = 0;
    }
    cerr << count;
    isNext = false;
//    start(); // какого ебаного члена ты не работаешь

}

int MyFirstThread::getCount() {
    return count;
}

void MyFirstThread::setCount(int count) {
    this->count = count;
}

HSTREAM MyFirstThread::getStream() {
    return stream;
}

void MyFirstThread::slot1() {
//    BASS_ChannelStop(stream); // пауза (lol)
    cerr << "Hai0";
}




// для prev два нажатия - первое начинает сначала композицию, второе - переход на композицию раньше
