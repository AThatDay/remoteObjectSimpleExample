#include "NestedWorker.h"
#include <QDebug>
#include <QThread>

void NestedWorker::doNestedWork()
{
    for (int i = 0; i < 5; ++i) {
        qDebug() << "Nested working in thread:" << QThread::currentThread();
        QThread::sleep(1); // Simulate work by sleeping
    }
    emit nestedWorkDone();
}
