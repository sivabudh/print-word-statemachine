#pragma once

#include <QObject>

class QStateMachine;

class CharStreamProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CharStreamProcessor(QObject* parent_ = nullptr);

    void start();

public slots:
    void characterReceived(QChar const);

private:
    QStateMachine* statemachine;
};
