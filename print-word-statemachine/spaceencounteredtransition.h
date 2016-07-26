#pragma once

#include <QSignalTransition>

class CharStreamProcessor;

class SpaceEncounteredTransition : public QSignalTransition
{
    Q_OBJECT
public:
    explicit SpaceEncounteredTransition(CharStreamProcessor *);

protected:
    bool eventTest(QEvent* e);
};

