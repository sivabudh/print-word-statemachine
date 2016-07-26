#pragma once

#include <QState>

class ClearState : public QState
{
    Q_OBJECT

public:
    ClearState();

    virtual void onEntry(QEvent*);
};
