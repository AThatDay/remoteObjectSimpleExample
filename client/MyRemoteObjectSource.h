#ifndef MYREMOTEOBJECTSOURCE_H
#define MYREMOTEOBJECTSOURCE_H

#include "rep_MyInterface_source.h"

class MyInterfaceImpl : public MyInterfaceSimpleSource
{
    Q_OBJECT
public:
    MyInterfaceImpl(QObject *parent = nullptr) : MyInterfaceSimpleSource(parent) {
        m_value = lifeUniverseEverything();
    }

    int getValue() {
        return m_value;
    }


public slots:


private:
    int m_value;
};
#endif // MYREMOTEOBJECTSOURCE_H
