#include "ExampleController.h"

#include <QDebug>

#include <qtcontrollayer/QIntProperty.h>
#include <qtcontrollayer/TwoStateProperty.h>
#include <qtcontrollayer/QRealProperty.h>

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
    _pIntegerValue = createProperty<QIntProperty>("IntegerValue", tr("IntegerValue"), 3, 0, 6, strings);
    _pBooleanValue = createProperty<TwoStateProperty>("BooleanValue", tr("BooleanValue"), false, QStringList() << tr("ON") << tr("OFF"));
    _pFloatValue = createProperty<QRealProperty>("FloatValue", tr("FloatValue"), 0.0, 0.0, 100.0, "%.0f %%");
}

ExampleController::~ExampleController()
{

}

void ExampleController::onPropertyChanged()
{
    if (sender() == _pIntegerValue)
    {
        qDebug() << _pIntegerValue->displayName() << ": " << _pIntegerValue->value();
    }
    else if (sender() == _pBooleanValue)
    {
        qDebug() << _pBooleanValue->displayName() << ": " << _pBooleanValue->state();
    }
    else if (sender() == _pFloatValue)
    {
        qDebug() << _pFloatValue->displayName() << ": " << _pFloatValue->value();
    }
}
