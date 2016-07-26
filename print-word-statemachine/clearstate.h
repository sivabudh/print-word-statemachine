#pragma once

#include <QState>

class ClearState : public QState
{
public:
    ClearState();

    virtual void onEntry(QEvent*);
};
