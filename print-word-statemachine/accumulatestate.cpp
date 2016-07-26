#include "accumulatestate.h"

#include <QDebug>

AccumulateState::AccumulateState(QString * textData_)
    : textData(textData_)
{}

void AccumulateState::onEntry(QEvent * event_)
{
    qDebug() << "AccumulateState::onEntry";
}
