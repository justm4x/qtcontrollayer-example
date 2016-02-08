#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char * argv[])
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QCoreApplication::applicationDirPath() + "/qml/main.qml");
    return application.exec();
}