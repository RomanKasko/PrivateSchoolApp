#include "Teacher.h"
#include "student.h"
#include "discipline.h"
#include "disciplinemanager.h"

Teacher::Teacher(){}

void Teacher::SetPosition(QPair<int,QString> pos)
{
    this->position = pos;
}

void Teacher::SetExperience(int exp)
{
    this->experience = exp;
}

void Teacher::SetDiscipline(Discipline discp)
{
    this->disciplines.push_back(discp);
}

void Teacher::SetDisciplineNameByIndex(unsigned int index,QString discpName)
{
    if(index > this->disciplines.size())
        return;
    this->disciplines[index].SetName(discpName);
}

void Teacher::SetEnrolledStudentsInfo(QPair<QString, QString> studInfo)
{
    this->enrolledStudentsInfo.push_back(studInfo);
}

QPair<int,QString> Teacher::GetPosition()
{
    return  position;
}

int Teacher::GetExperience()
{
    return  experience;
}

QVector<Discipline> Teacher::GetDisciplines()
{
    return  disciplines;
}

QVector<Discipline> & Teacher::GetOrigDisciplines()
{
    return disciplines;
}

QVector<QPair<QString,QString>> Teacher::GetEnrolledStudentsInfo()
{
    return this->enrolledStudentsInfo;
}

//Знаходить студентів викладача за переданою дисципліною
void Teacher::FindMyStudentsInDiscipline(QString subject)
{        
    QVector<QString> tmpVect;
    QPair<QString, QString> tmpPairStudInfo;
    this->enrolledStudentsInfo.clear();

    int check = 0;
    for(int i = 0; i < this->disciplines.size(); ++i)
        if(subject == this->disciplines[i].GetName().replace("_"," "))
           check = 1;

    if(!check) return;

    DisciplineManager *tmpDiscManager = new DisciplineManager;
    int course = tmpDiscManager->FindCourseOfSubject(subject);

    for(int i = 0; i < studentsList.size(); ++i)
        for(int j = 0; j < studentsList[i].GetSizeOfIdOfPersons(); ++j)
            if(studentsList[i].GetIdOfPersonsByIndex(j) == this->GetPersonalId() && course == studentsList[i].GetYear())
            {
                tmpVect.push_back(studentsList[i].GetPersonalId());
                tmpPairStudInfo.first = studentsList[i].surname;
                tmpPairStudInfo.second = studentsList[i].GetGroup();
                this->enrolledStudentsInfo.push_back(tmpPairStudInfo);
            }
    this->SetIdOfPersons(tmpVect);
}

//Знаходитить всіх студентів викладача
void Teacher::FindAllMyStudents()
{
   QPair<QString,QString> tmpInfoAboutStudent;

   this->ClearDataAboutIdOfPersons();
   for(int k = 0; k < this->disciplines.size(); ++k)
   {
       int course = this->disciplines[k].GetCourse();
       for(int i = 0; i < studentsList.size(); ++i)
           for(int j = 0; j < studentsList[i].GetSizeOfIdOfPersons(); ++j)
               if(studentsList[i].GetIdOfPersonsByIndex(j) == this->GetPersonalId() && course == studentsList[i].GetYear())
                {
                   this->SetIdOfPersonsByIndex(studentsList[i].GetPersonalId(),this->GetSizeOfIdOfPersons());
                   tmpInfoAboutStudent.first = studentsList[i].surname;
                   tmpInfoAboutStudent.second = studentsList[i].GetGroup();
                   this->enrolledStudentsInfo.push_back(tmpInfoAboutStudent);
                }
   }
}

//Виводить інформацію про студентів викладача
void Teacher::PrintInfoAboutStudents(QTableWidget *table)
{
    table->clear();

    table->setColumnCount(2);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("GROUP"));

    for(int i = 0; i < this->GetSizeOfIdOfPersons(); ++i)
    {
        table->setItem(i,0,new QTableWidgetItem(this->enrolledStudentsInfo[i].first));
        table->setItem(i,1,new QTableWidgetItem(this->enrolledStudentsInfo[i].second));
    }
}

//Встановлює пріоритет відповідно до посади викладача
void Teacher::SetPriorityToTeacherPosition()
{
    if(this->position.second == "Professor")
    {
        this->position.first = 4;
    }
    else if(this->position.second == "Docent")
    {
        this->position.first = 3;
    }
    else if(this->position.second == "Lecturer")
    {
       this->position.first = 2;
    }
    else if(this->position.second == "Assistant")
    {
        this->position.first = 1;
    }
    else if(this->position.second == "Laborant")
    {
        this->position.first = 0;
    }
    else
        this->position.first = -1;
}

//Видаляє некоректні дисципліни
void Teacher::DeleteWrongDisciplines()
{
     for(int i = 0; i < this->disciplines.size(); ++i)
     {
         if(!CheckExistOfDiscipline(this->disciplines[i].GetName()))
         {
             if( i == this->disciplines.size()-1)
                 this->disciplines.pop_back();
             else if( i == 0 )
                 this->disciplines.pop_front();
             else
                 this->disciplines.removeAt(i);
         }
     }
}

//Перевіряє чи дана дисципліна існує у списку
bool Teacher::CheckExistOfDiscipline(QString discipline)
{
    bool check = false;
    for(int j = 0; j < listOfDisciplines.size(); ++j)
        if(discipline == listOfDisciplines[j].GetName())
            check = true;
    return check;
}

//Сортує студентів за прізвищем(в алфавітному порядку)
void Teacher::SortMyStudentsBySurname()
{
    sort(this->enrolledStudentsInfo.begin(),this->enrolledStudentsInfo.end(),
         [](QPair<QString,QString> &firStudSurname, QPair<QString,QString> &secStudSurname)
         {return firStudSurname.first < secStudSurname.first;});
}

//Сортує студентів за групою(в алфавітному порядку)
void Teacher::SortMyStudentsByGroup()
{
    sort(this->enrolledStudentsInfo.begin(),this->enrolledStudentsInfo.end(),
         [](QPair<QString,QString> &firStudGroup, QPair<QString,QString> &secStudGroup)
         {return firStudGroup.second < secStudGroup.second;});
}

//Видаляє всю інформацію про дисципліни
void Teacher::DeleteDisciplines()
{
    this->disciplines.clear();
}
