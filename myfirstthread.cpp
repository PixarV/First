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

//    filename = new QString("C:\\Qt_project\\diplom_first\\Old_Friends.mp3");
//    stream = BASS_StreamCreateFile(FALSE, filename->toStdString().c_str(), 0, 0, 0); // идентификатор потока

}
void MyFirstThread::initialize(QStringList files) {
    count = 0;
    this->files = files;
    BASS_StreamFree(stream);
}

void MyFirstThread::run() {
/* BASS_ACTIVE_STOPPED = 0
 * BASS_ACTIVE_PLAYING = 1;
 * BASS_ACTIVE_PAUSED = 3; */

    if (!BASS_ChannelPlay(stream, FALSE)) {

        QString* filename = new QString(files.at(count));
        stream = BASS_StreamCreateFile(FALSE, filename->toStdU16String().c_str(), 0, 0, BASS_UNICODE); // идентификатор потока
    }
    BASS_ChannelPlay(stream, FALSE);

    BASS_ChannelSetSync(stream, BASS_SYNC_END, 0,  MyFirstThread::endPlay, this);
}

void MyFirstThread::stop() {
    BASS_StreamFree(stream); // освобождаем поток

}

void MyFirstThread::pause() {
    BASS_ChannelStop(stream); // пауза (lol)
}

void MyFirstThread::next() {
    BASS_StreamFree(stream); // освобождаем поток

    if (count != files.length() - 1) {
        count++;
    } else {
        count = 0;
    }
    start();
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

void MyFirstThread::probe() {

}

void CALLBACK MyFirstThread::endPlay(HSYNC handle, DWORD channel, DWORD data, void* user) {
    ((MyFirstThread*)user)->next();
}

// CALLBACK - передача исполняемого кода в качестве одного из параметров другого кода.
// Обратный вызов позволяет в функции исполнять код, который задаётся в аргументах при её вызове.




// для prev два нажатия - первое начинает сначала композицию, второе - переход на композицию раньше
