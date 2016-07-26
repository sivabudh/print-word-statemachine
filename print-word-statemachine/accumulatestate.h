#pragma once

#include <QState>

class QString;

class AccumulateState : public QState
{
    Q_OBJECT
public:
    AccumulateState(QString *);

    virtual void onEntry(QEvent*);

private:
    QString * textData;
};

