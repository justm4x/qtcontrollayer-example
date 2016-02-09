#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "qtcontrollayer/Controller.h"
#include "qtcontrollayer/QIntProperty.h"

int main(int argc, char * argv[])
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QCoreApplication::applicationDirPath() + "/qml/main.qml");

    Controller * controller = new Controller("Example");
    QIntProperty * p = controller->registerProperty<QIntProperty>("CurrentIndex", QObject::tr("Current Index"), 3, 0, 10);
    qDebug() << p->displayName() << ": " << p->displayValue();
    p->setValue(5);
    qDebug() << p->displayName() << ": " << p->displayValue();

    return application.exec();
}