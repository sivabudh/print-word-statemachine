#pragma once

#include <QObject>

class QStateMachine;

class CharStreamProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CharStreamProcessor(QObject* parent_ = nullptr);

    void start();

signals:
    void newCharacterReceived(QChar const);

private:
    QStateMachine* statemachine;

    // Text data manipulated by the state machine
    QString	textData;
};
