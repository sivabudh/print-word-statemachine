#include "newchartransition.h"
#include "newcharevent.h"
#include <QDebug>

bool NewCharTransition::eventTest(QEvent* event_)
{
    if (event_->type() == QEvent::User+3) {
        return true;
    }
    else {
        return false;
    }
}
