#ifndef NESTEDWORKER_H
#define NESTEDWORKER_H

#include <QObject>

class NestedWorker : public QObject
{
    Q_OBJECT

public slots:
    void doNestedWork();

signals:
    void nestedWorkDone();
};

#endif // NESTEDWORKER_H
