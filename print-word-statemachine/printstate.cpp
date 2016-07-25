#include "printstate.h"
#include <iostream>
#include "newcharevent.h"


void Print::onEntry(QEvent* event_)
{
    auto event = static_cast<NewCharEvent*>(event_);
    std::cout << event->value.toLatin1()
              << std::flush;
}
