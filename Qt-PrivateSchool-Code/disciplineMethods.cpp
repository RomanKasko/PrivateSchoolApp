#include "discipline.h"

void Discipline::SetCourse(int course)
{
    this->course = course;
}

void Discipline::SetName(QString name)
{
    this->name = name;
}

void Discipline::SetStartDate(QString date)
{
    this->startDate = date;
}

void Discipline::SetEndDate(QString date)
{
    this->endDate = date;
}

void Discipline::SetDaysInWeek(QVector<QString> days)
{
    this->daysInWeek = days;
}

void Discipline::SetDayInWeek(QString day)
{
    this->daysInWeek.push_back(day);
}

int Discipline::GetCourse()
{
    return course;
}

QString Discipline::GetName()
{
    return name;
}

QString Discipline::GetStartDate()
{
    return startDate;
}

QString Discipline::GetEndDate()
{
    return endDate;
}

QVector<QString> Discipline::GetDaysInWeek()
{
    return daysInWeek;
}

QString Discipline::GetDayByIndex(unsigned int index)
{
    if(index > daysInWeek.size())
        return "Error";
    return daysInWeek[index];
}

int Discipline::GetCountOfDays()
{
    return daysInWeek.size();
}
