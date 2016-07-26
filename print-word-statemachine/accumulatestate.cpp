#include "accumulatestate.h"

#include <QDebug>
#include <QStateMachine>
#include <QEvent>

AccumulateState::AccumulateState(QString * textData_)
    : textData(textData_)
{}

void AccumulateState::onEntry(QEvent * event_)
{
    auto se = static_cast<QStateMachine::SignalEvent*>(event_);
    this->textData->append(se->arguments().at(0).toChar());
}
