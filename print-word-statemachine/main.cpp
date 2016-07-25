#include <QCoreApplication>
#include <QtDebug>
#include "filereader.h"
#include "charstreamstatemachine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FileReader reader("./sample_input.txt");
    CharStreamStateMachine statemachine;

    statemachine.start();
    reader.start();

    return a.exec();
}
