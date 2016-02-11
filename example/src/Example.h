#ifndef Example_h__
#define Example_h__

#include <QObject>

class QQmlApplicationEngine;
class ExampleController;
class Example : public QObject
{
    Q_OBJECT
public:
    explicit Example(QObject * parent = 0);
    virtual ~Example();

private:
    QQmlApplicationEngine * _engine;
};
#endif // Example_h__