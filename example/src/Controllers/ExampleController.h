#ifndef ExampleController_h__
#define ExampleController_h__

#include <qtcontrollayer/Controller.h>

class QIntProperty;
class TwoStateProperty;
class QRealProperty;
class ExampleController : public Controller
{
    Q_OBJECT
public:
    explicit ExampleController(const QString & name, QObject * parent = 0);
    virtual ~ExampleController();

private:
    virtual void onPropertyChanged();

private:
    QIntProperty * _pIntegerValue;
    TwoStateProperty * _pBooleanValue;
    QRealProperty * _pFloatValue;
};
#endif // ExampleController_h__