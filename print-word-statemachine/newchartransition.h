#pragma once

#include <QAbstractTransition>
#include <QEvent>
#include <QChar>

class NewCharTransition : public QAbstractTransition
{
    Q_OBJECT

public:
    NewCharTransition(QChar const value_)
        : value(value_) {}

protected:
    virtual bool eventTest(QEvent *);
    virtual void onTransition(QEvent *) {}

private:
    QChar const value;
};
