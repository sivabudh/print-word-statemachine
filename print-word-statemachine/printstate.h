#pragma once

#include <QState>

class QString;

class PrintState : public QState
{
    Q_OBJECT

public:
    PrintState(QString *);

protected:
    virtual void onEntry(QEvent *) Q_DECL_OVERRIDE;

private:
    QString * textData;
};
