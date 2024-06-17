#include "Worker.h"
#include <QDebug>
#include <QThread>

void Worker::doWork()
{
    // Start the nested worker in a new thread
    QThread* nestedThread = new QThread;
    NestedWorker* nestedWorker = new NestedWorker;

    nestedWorker->moveToThread(nestedThread);

    QObject::connect(nestedThread, &QThread::started, nestedWorker, &NestedWorker::doNestedWork);
    QObject::connect(nestedWorker, &NestedWorker::nestedWorkDone, nestedThread, &QThread::quit);
    QObject::connect(nestedWorker, &NestedWorker::nestedWorkDone, nestedWorker, &QObject::deleteLater);
    QObject::connect(nestedThread, &QThread::finished, nestedThread, &QObject::deleteLater);

    nestedThread->start();

    // Continue the original work
    for (int i = 0; i < 1; ++i) {
        qDebug() << "Working in thread:" << QThread::currentThread();
        QThread::sleep(1); // Simulate work by sleeping
    }

    emit workDone();
}
