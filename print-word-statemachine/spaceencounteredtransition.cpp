#include "spaceencounteredtransition.h"
#include "charstreamprocessor.h"

#include <QStateMachine>

SpaceEncounteredTransition::SpaceEncounteredTransition(CharStreamProcessor * processor_)
    : QSignalTransition(processor_, &CharStreamProcessor::newCharacterReceived) {}

bool SpaceEncounteredTransition::eventTest(QEvent *e)
{
    if( ! QSignalTransition::eventTest(e))
        return false;

    auto se = static_cast<QStateMachine::SignalEvent*>(e);
    return se->arguments().at(0).toChar().isSpace();
}
