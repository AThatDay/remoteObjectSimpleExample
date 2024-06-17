#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>
#include <QDebug>
#include "rep_MyInterface_source.h"

class TestClass : public QObject
{
    Q_OBJECT
public:
    explicit TestClass(QObject *parent = nullptr);
    TestClass(MyInterfaceSimpleSource object, QString name) {
        qDebug() << "that le " <<name << object.lifeUniverseEverything();
    }

    void test() {
        qDebug() << "that le";
    }

signals:

};

#endif // TESTCLASS_H
