#pragma once

#include <QState>

class AccumulateState : public QState
{
public:
    AccumulateState();

    virtual void onEntry(QEvent*);
};

