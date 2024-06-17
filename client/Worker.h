#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "NestedWorker.h"

class Worker : public QObject
{
    Q_OBJECT

public slots:
    void doWork();

signals:
    void workDone();
};

#endif // WORKER_H
