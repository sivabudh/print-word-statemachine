#include "charstreamprocessor.h"
#include <iostream>
#include <QStateMachine>
#include "newchartransition.h"
#include "newcharevent.h"
#include "printstate.h"

CharStreamProcessor::CharStreamProcessor(QObject* parent_) :
    QObject(parent_)
  , statemachine(new QStateMachine())
{
      QChar const space = ' ';

      auto transition = new NewCharTransition(space);
      auto printState = new Print();

      transition->setTargetState(printState);
      printState->addTransition(transition);

      this->statemachine->addState(printState);
      this->statemachine->setInitialState(printState);
}

void CharStreamProcessor::start()
{
    this->statemachine->start();
}

void CharStreamProcessor::characterReceived(QChar const character_)
{
    this->statemachine->postEvent(new NewCharEvent(character_));
}

