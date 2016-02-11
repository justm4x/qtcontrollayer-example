#include "Example.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <qtcontrollayer/qtcontrollayer.h>

#include "Controllers/ExampleController.h"

Example::Example(QObject * parent /*= 0*/)
    : QObject(parent)
{
    qtcontrollayer::registerTypes();

    Controller * controlLayer = new Controller("/", this);
    controlLayer->registerController(new ExampleController("Example"));

    _engine = new QQmlApplicationEngine(this);
    _engine->rootContext()->setContextProperty("ControlLayer", controlLayer);
    _engine->load(QGuiApplication::applicationDirPath() + "/qml/main.qml");
}

Example::~Example()
{
}

