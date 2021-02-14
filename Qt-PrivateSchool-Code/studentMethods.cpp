#include "student.h"
#define MAX_NAME 32

Student::Student(){}

void Student::SetYear(int year)
{
    this->year = year;
}

void Student::SetGroup(QString group)
{
    this->group = group;
}

void Student::SetLessons(QVector<QString> lessons)
{
    this->lessons = lessons;
}

int Student::GetYear()
{
    return year;
}

QString Student::GetGroup()
{
    return group;
}

QVector<QString> Student::GetLessons()
{
    return lessons;
}

//Сортує всіх вчителів за посадою (від найважливішої до найменш важливої)
void Student::SortTeacherListByPosition(QList<Teacher> &teachersList)
{
    sort(teachersList.begin(),teachersList.end(),[](Teacher &firstTeacherPosition, Teacher &secondTeacherPosition){return firstTeacherPosition > secondTeacherPosition;});
}

//Сортує всіх вчителів за прізвищем (в алфавітному порядку)
void Student::SortTeacherListBySurname(QList<Teacher> &teachersList)
{
    sort(teachersList.begin(),teachersList.end(),[] (Teacher &firstTeacherSurname, Teacher &secondTeacherSurname){return firstTeacherSurname < secondTeacherSurname;});
}

//Знаходить серед всіх вчителів, тих хто має тільки одну дисципліну
void Student::FindTeachersWhoHaveOneSubject(QList<Teacher> teachersList,QList<Teacher> &resList)
{

    for(int i = 0; i < teachersList.size(); ++i)
        if(teachersList[i].GetDisciplines().size() == 1)
        {
            Teacher tmp;
            tmp.surname = teachersList[i].surname;
            tmp.SetPosition(teachersList[i].GetPosition());
            tmp.SetDiscipline(teachersList[i].GetDisciplines()[0]);
            resList.push_back(tmp);
        }
}

//Знаходить серед всіх вчителів вибраної дисципліни найпопулярнішого(найбільше записаних студентів)
int Student::FindTheMostPopularTeacher(QList<Teacher> teachersList, QComboBox *subject, Teacher &resTeacher)
{
    QVector<Teacher> thisDiscipTeachers;
    int counter = 0;

    if(subject->currentText() == "")
        return -1;

    for(int i = 0; i < teachersList.size(); ++i)
        for(int j = 0; j < teachersList[i].GetDisciplines().size(); ++j)
            if(teachersList[i].GetDisciplines()[j].GetName() == subject->currentText())
                thisDiscipTeachers.push_back(teachersList[i]);

    if(!thisDiscipTeachers.size()) return -1;

    int max = thisDiscipTeachers[0].GetSizeOfIdOfPersons();
    resTeacher.surname = thisDiscipTeachers[0].surname;
    resTeacher.SetPosition(thisDiscipTeachers[0].GetPosition());
    counter = thisDiscipTeachers[0].GetSizeOfIdOfPersons();

    for(int i = 0; i < thisDiscipTeachers[0].GetDisciplines().size(); ++i)
         resTeacher.SetDiscipline(thisDiscipTeachers[0].GetDisciplines()[i]);


    for(int i = 1; i < thisDiscipTeachers.size(); ++i)
    {
        if(max < thisDiscipTeachers[i].GetSizeOfIdOfPersons())
        {
            max = thisDiscipTeachers[i].GetSizeOfIdOfPersons();
            resTeacher.surname = thisDiscipTeachers[i].surname;
            resTeacher.SetPosition(thisDiscipTeachers[i].GetPosition());
            counter = thisDiscipTeachers[i].GetSizeOfIdOfPersons();
            for(int i = 0; i < thisDiscipTeachers[i].GetDisciplines().size(); ++i)
                resTeacher.SetDiscipline(thisDiscipTeachers[i].GetDisciplines()[i]);
        }
    }
    return counter;
}


//Записує дані студенту про обраного вчителя на задану дисципліну
void Student::ChooseTeacher(QString myTeacherID)
{
    student.SetIdOfPersonsByIndex(myTeacherID,student.GetSizeOfIdOfPersons());
}

//Записує дані про дисципліни студенту відповідно до його курсу
void Student::SetDisciplinesToStudent(Student &student,int year)
{
    for(int i = 0; i < listOfDisciplines.size(); ++i)
        if(listOfDisciplines[i].GetCourse() == year)
            student.lessons.push_back(listOfDisciplines[i].GetName());
}
