#ifndef STUDENT_H
#define STUDENT_H

#include <QFile>
#include <QFileDialog>
#include <QComboBox>
#include <QTableWidget>
#include <QDate>
#include <QCalendarWidget>
#include <QLocale>
#include <QString>
#include <QVector>

#include "Teacher.h"
#include "discipline.h"
//Клас Студент, який містить рік навчання, групу та предмети відповідно до курсу
class Student:public Human
{
 public:
    Student();
    ~Student(){};

    void SetYear(int year);
    void SetGroup(QString group);
    void SetLessons(QVector<QString> lessons);

    int GetYear();
    QString GetGroup();
    QVector<QString> GetLessons();

    void ChooseTeacher(QString myTeacherID);
    int  FindTheMostPopularTeacher(QList<Teacher> teachersList, QComboBox *subject, Teacher &resTeacher);
    void SortTeacherListBySurname(QList<Teacher> &teachersList);
    void SortTeacherListByPosition(QList<Teacher> &teachersList);
    void FindTeachersWhoHaveOneSubject(QList<Teacher> teachersList,QList<Teacher> &resList);
    void SetDisciplinesToStudent(Student &student,int year);

    bool operator<(Student &another)
    {
     return this->surname < another.surname;
    }

    bool operator>(Student &another)
    {
        return this->group > another.group;
    }
private:
    int year;
    QString group;
    QVector<QString> lessons;
};
//Глобальний список студентів
extern QList<Student> studentsList;
//Глобальна змінна студента-користувача
extern Student student;
#endif // STUDENT_H

