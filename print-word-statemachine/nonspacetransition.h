#pragma once

#include <QSignalTransition>

class QEvent;
class CharStreamProcessor;

class NonSpaceTransition : public QSignalTransition
{
    Q_OBJECT
public:
    explicit NonSpaceTransition(CharStreamProcessor *);

protected:
    bool eventTest(QEvent* e);
};
