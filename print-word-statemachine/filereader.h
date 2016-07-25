#pragma once

#include <QObject>
#include <QFile>
#include <QTextStream>

class FileReader : public QObject
{
    Q_OBJECT
public:
    explicit FileReader(QString const fileName_,
                        QObject* parent = nullptr);

    void start();

signals:
    void characterRead(QChar const);

protected:
    void timerEvent(QTimerEvent *event);

private:
    QFile			file;
    QTextStream		textstream;
};

