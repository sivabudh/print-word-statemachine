#pragma once

#include <QEvent>
#include <QChar>

struct NewCharEvent : public QEvent
{
    NewCharEvent(QChar const value_)
    : QEvent(QEvent::Type(QEvent::User+3)),
      value(value_) {}

    QChar const value;
};
