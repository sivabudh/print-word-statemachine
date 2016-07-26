#include "charstreamprocessor.h"

#include <QStateMachine>

// States
#include "clearstate.h"
#include "printstate.h"
#include "accumulatestate.h"

// Transitions
#include "nonspacetransition.h"
#include "spaceencounteredtransition.h"
#include "unconditionaltransition.h"


CharStreamProcessor::CharStreamProcessor(QObject* parent_) :
    QObject(parent_)
  , statemachine(new QStateMachine())
{
      // Create states
      auto clearState = new ClearState(&this->textData);
      auto accumulateState = new AccumulateState(&this->textData);
      auto printState = new PrintState(&this->textData);


      // Add the states to statemachine
      this->statemachine->addState(clearState);
      this->statemachine->addState(accumulateState);
      this->statemachine->addState(printState);

      // Initial state is ClearState
      this->statemachine->setInitialState(clearState);

      //
      // State Transitions
      //

      // In Clear, when a non-space character is encountered, -> Accumulate
      clearState->addTransition([&] {
            auto nonSpaceTransition = new NonSpaceTransition(this);
            nonSpaceTransition->setTargetState(accumulateState);
            return nonSpaceTransition;
        }()
      );

      // In Clear, when a space is encountered, -> Clear
      clearState->addTransition([&] {
             auto const spaceEncounteredTransition = new SpaceEncounteredTransition(this);
             spaceEncounteredTransition->setTargetState(clearState);
             return spaceEncounteredTransition;
         }()
      );

      // In Accumulate, when a non-space character is encountered, -> Accumulate
      accumulateState->addTransition([&] {
            auto nonSpaceTransition = new NonSpaceTransition(this);
            nonSpaceTransition->setTargetState(accumulateState);
            return nonSpaceTransition;
         }()
      );

      // In Accumulate, when a space character is encountered, -> Print
      accumulateState->addTransition([&] {
            auto const spaceEncounteredTransition = new SpaceEncounteredTransition(this);
            spaceEncounteredTransition->setTargetState(printState);
            return spaceEncounteredTransition;
        }()
      );

      // In Print, unconditionally -> Clear
      printState->addTransition([&] {
            auto const unconditionalTransition = new UnconditionalTransition();
            unconditionalTransition->setTargetState(clearState);
            return unconditionalTransition;
        }()
      );
}

void CharStreamProcessor::start()
{
    this->statemachine->start();
}
