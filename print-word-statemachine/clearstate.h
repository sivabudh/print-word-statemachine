#pragma once

#include <QState>

class QString;

class ClearState : public QState
{
    Q_OBJECT

public:
    ClearState(QString *);

    virtual void onEntry(QEvent*);

private:
    QString * textData;
};
