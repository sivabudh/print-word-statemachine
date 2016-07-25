#include <QCoreApplication>
#include <QtDebug>
#include "filereader.h"
#include "charstreamprocessor.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileReader reader("./sample_input.txt");
    CharStreamProcessor processor;

    QObject::connect(&reader, 	&FileReader::characterRead,
                     &processor, &CharStreamProcessor::characterReceived);

    processor.start();
    reader.start();

    return a.exec();
}
