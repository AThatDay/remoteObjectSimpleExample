#include <QCoreApplication>
#include <QRemoteObjectNode>
#include "MyInterface_replica.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    if (argc < 2 || QString::compare(argv[1], "client_mode", Qt::CaseInsensitive) != 0) {
        qFatal("Incorrect mode specified. Use 'client' for client mode.");
    }

    QRemoteObjectNode repNode;
    repNode.connectToNode(QUrl(QStringLiteral("local:replica")));

    auto myInterface = repNode.acquire<MyInterfaceReplica>();

    QObject::connect(myInterface.data(), &MyInterfaceReplica::valueChanged, [](int newValue) {
        qDebug() << "Value changed to:" << newValue;
    });

    myInterface->resetValue();

    return app.exec();
}
