#include "filereader.h"
#include <QtDebug>
#include <iostream>

FileReader::FileReader(const QString fileName_,
                       QObject* parent_) :
    QObject(parent_),
    file(fileName_),
    textstream(&file)
{
    if(!this->file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Unable to open the file.");
}


void FileReader::start() {
    this->startTimer(250);
}

void FileReader::timerEvent(QTimerEvent* event_) {
    QChar character;
    this->textstream >> character;

    emit characterRead(character);
    std::cout << character.toLatin1()
              << std::flush;
}
