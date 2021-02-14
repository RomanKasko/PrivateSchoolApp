#ifndef TEACHER_H
#define TEACHER_H

#include "human.h"
#include <QTableWidget>
#include "discipline.h"
//Клас Вчитель, який містить посаду, стаж та предмети, які викладає, а також дані про записаних студентів
class Teacher:public Human
{
  public:

     Teacher();
     ~Teacher(){};

     void SetPosition(QPair<int,QString> pos);
     void SetExperience(int);
     void SetDiscipline(Discipline discp);
     void SetDisciplineNameByIndex(unsigned int index,QString discpName);
     void SetEnrolledStudentsInfo(QPair<QString, QString> studInfo);

     QPair<int,QString> GetPosition();
     int GetExperience();
     QVector<Discipline> GetDisciplines();
     QVector<Discipline> & GetOrigDisciplines();
     QVector<QPair<QString,QString>> GetEnrolledStudentsInfo();

     void FindMyStudentsInDiscipline(QString subject);
     void FindAllMyStudents();
     void PrintInfoAboutStudents(QTableWidget *table);
     void SetPriorityToTeacherPosition();
     bool CheckExistOfDiscipline(QString discipline);
     void DeleteWrongDisciplines();
     void DeleteDisciplines();

     void SortMyStudentsBySurname();
     void SortMyStudentsByGroup();

     bool operator<(Teacher &t2)
    {
        return this->surname < t2.surname;
    }

     bool operator>(Teacher &another)
     {
         return this->position.first > another.position.first;
     }
private:
     QPair<int,QString> position;
     int experience;
     QVector<Discipline> disciplines;
     QVector<QPair<QString,QString>> enrolledStudentsInfo; //first - surname, second - group
};
extern QList<Teacher> teachersList;
extern Teacher teacher;
#endif // TEACHER_H
