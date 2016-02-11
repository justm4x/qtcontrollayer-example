#include "ExampleController.h"

#include <QDebug>

#include <qtcontrollayer/QIntProperty.h>

ExampleController::ExampleController(const QString & name, QObject * parent /*= 0*/)
    : Controller(name, parent)
{
    QStringList strings;
    strings << tr("Entry 0");
    strings << tr("Entry 1");
    strings << tr("Entry 2");
    strings << tr("Entry 3");
    strings << tr("Entry 4");
    strings << tr("Entry 5");
    strings << tr("Entry 6");
    _pCurrentIndex = createProperty<QIntProperty>("CurrentIndex", tr("Index"), 3, 0, 6, strings);
}

ExampleController::~ExampleController()
{

}

void ExampleController::onPropertyChanged()
{
    if (sender() == _pCurrentIndex)
    {
        qDebug() << "[ExampleController]: " << _pCurrentIndex->displayName() << " changed - " << _pCurrentIndex->value();
    }
}
