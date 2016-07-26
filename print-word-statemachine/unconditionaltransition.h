#pragma once

#include <QAbstractTransition>


class UnconditionalTransition : public QAbstractTransition
{
    Q_OBJECT

protected:
    bool eventTest(QEvent*);
    void onTransition(QEvent *);
};
