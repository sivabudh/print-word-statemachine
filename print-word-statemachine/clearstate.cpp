#include "clearstate.h"

#include <QDebug>

ClearState::ClearState(QString * textData_)
    : textData(textData_)
{}

void ClearState::onEntry(QEvent *)
{
    textData->clear();
}
