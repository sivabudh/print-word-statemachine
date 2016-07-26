#include "charstreamprocessor.h"

#include <QStateMachine>

// States
#include "clearstate.h"
#include "printstate.h"
#include "accumulatestate.h"

// Transitions
#include "nonspacetransition.h"


CharStreamProcessor::CharStreamProcessor(QObject* parent_) :
    QObject(parent_)
  , statemachine(new QStateMachine())
{
      // Create states
      auto accumulateState = new AccumulateState();
      auto printState = new PrintState();
      auto clearState = new ClearState();

      // Transitions in the state diagram
      auto nonSpaceTransition = new NonSpaceTransition(this);

      // Add the states to statemachine
      this->statemachine->addState(printState);
      this->statemachine->addState(accumulateState);
      this->statemachine->addState(clearState);

      // Initial state is ClearState
      this->statemachine->setInitialState(clearState);

      // When a non-space character is encountered, Clear -> Accumulate
      clearState->addTransition(nonSpaceTransition);
      nonSpaceTransition->setTargetState(accumulateState);
}

void CharStreamProcessor::start()
{
    this->statemachine->start();
}
