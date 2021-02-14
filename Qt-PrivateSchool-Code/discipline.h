#ifndef DISCIPLINE_H
#define DISCIPLINE_H
#include <QMainWindow>
#include <QDate>
#define DISCIPLINE_DAYS_START_INDEX 4
// клас Предмет, у якого є ім'я, курс, початковий термін та кінцевий,
// і дні тижня, коли його викладають
class Discipline
{
public:
    Discipline(){};
    void SetCourse(int);
    void SetName(QString);
    void SetStartDate(QString date);
    void SetEndDate(QString date);
    void SetDaysInWeek(QVector<QString> days);
    void SetDayInWeek(QString day);

    int GetCourse();
    QString GetName();
    QString GetStartDate();
    QString GetEndDate();
    QVector<QString> GetDaysInWeek();
    QString GetDayByIndex(unsigned int index);
    int GetCountOfDays();

private:
    int course;
    QString name;
    QString startDate;
    QString endDate;
    QVector<QString> daysInWeek;
};
// глобальний список предметів
extern QList<Discipline> listOfDisciplines;

#endif // DISCIPLINE_H
