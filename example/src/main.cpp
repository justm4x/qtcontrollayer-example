#include <QGuiApplication>

#include "qtcontrollayer/Controller.h"
#include "qtcontrollayer/QIntProperty.h"

#include "Example.h"

int main(int argc, char * argv[])
{
    QGuiApplication application(argc, argv);

    Example example;

    return application.exec();
}