#include "filereader.h"
#include <QtDebug>

FileReader::FileReader(const QString fileName_,
                       QObject* parent_) :
    QObject(parent_),
    file(fileName_),
    textstream(&file),
    timerId(0)
{
    if(!this->file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Unable to open the file.");
}


void FileReader::start() {
    this->timerId = this->startTimer(250);
}

void FileReader::timerEvent(QTimerEvent*) {
    if( ! this->textstream.atEnd()) {
        QChar character;
        this->textstream >> character;

        emit characterRead(character);
    }
    else {
        this->killTimer(this->timerId);
        this->timerId = 0;
        qDebug() << "";
        qDebug() << "READER: Nothing else to read. We are done!";
    }
}
