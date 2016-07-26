#include "nonspacetransition.h"
#include "charstreamprocessor.h"

#include <QStateMachine>

NonSpaceTransition::NonSpaceTransition(CharStreamProcessor * processor_)
    : QSignalTransition(processor_, &CharStreamProcessor::newCharacterReceived) {}

bool NonSpaceTransition::eventTest(QEvent *e)
{
    if( ! QSignalTransition::eventTest(e))
        return false;

    auto se = static_cast<QStateMachine::SignalEvent*>(e);
    return ! se->arguments().at(0).toChar().isSpace();
}
