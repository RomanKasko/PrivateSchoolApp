#ifndef PRSCHOOL_H
#define PRSCHOOL_H
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class PrSchoolData;

class PrSchool
{
    Q_OBJECT
public:
    PrSchool();
    PrSchool(const PrSchool &);
    PrSchool &operator=(const PrSchool &);
    ~PrSchool();

private:
    QSharedDataPointer<PrSchoolData> data;
};



#endif // PRSCHOOL_H
