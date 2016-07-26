#include "printstate.h"
#include <iostream>
#include "newcharevent.h"
#include <QString>
#include <QDebug>


PrintState::PrintState(QString * textData_)
    : textData(textData_)
{}

void PrintState::onEntry(QEvent* event_)
{
    qDebug() << "PrintState::onEntry";
}
