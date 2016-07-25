#pragma once

#include <QState>

class Print : public QState
{
public:
    Print() {}

protected:
    virtual void onEntry(QEvent *) Q_DECL_OVERRIDE;
};
