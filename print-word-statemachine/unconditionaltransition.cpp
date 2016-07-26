#include "unconditionaltransition.h"
#include <QDebug>


bool UnconditionalTransition::eventTest(QEvent *)
{
    return true;
}


void UnconditionalTransition::onTransition(QEvent *)
{}
