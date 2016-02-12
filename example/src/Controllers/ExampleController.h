#ifndef ExampleController_h__
#define ExampleController_h__

#include <qtcontrollayer/Controller.h>

class QIntProperty;
class TwoStateProperty;
class ExampleController : public Controller
{
    Q_OBJECT
public:
    explicit ExampleController(const QString & name, QObject * parent = 0);
    virtual ~ExampleController();

private:
    virtual void onPropertyChanged();

private:
    QIntProperty * _pCurrentIndex;
    TwoStateProperty * _pTrigger;
};
#endif // ExampleController_h__