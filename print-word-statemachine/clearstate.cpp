#include "clearstate.h"

#include <QDebug>

ClearState::ClearState()
{

}

void ClearState::onEntry(QEvent *)
{
    qDebug() << "ClearState::onEntry";
}
