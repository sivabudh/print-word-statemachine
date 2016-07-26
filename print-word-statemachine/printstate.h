#pragma once

#include <QState>

class PrintState : public QState
{
public:
    PrintState() {}

protected:
    virtual void onEntry(QEvent *) Q_DECL_OVERRIDE;
};
