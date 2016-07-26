#include "accumulatestate.h"

#include <QDebug>

AccumulateState::AccumulateState()
{

}

void AccumulateState::onEntry(QEvent * event_)
{
    qDebug() << "AccumulateState::onEntry";
}
