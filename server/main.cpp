#include <QCoreApplication>
#include <QRemoteObjectHost>

#include "MyRemoteObjectSource.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QRemoteObjectHost hostNode(QUrl(QStringLiteral("local:replica")));
    MyInterfaceSimpleSource myInterface;
    hostNode.enableRemoting(&myInterface);

    qDebug() << "that le " << myInterface.lifeUniverseEverything();
    return a.exec();
}
