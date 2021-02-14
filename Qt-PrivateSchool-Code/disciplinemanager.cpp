#include "disciplinemanager.h"
#include "Teacher.h"
DisciplineManager::DisciplineManager(){}

//Знаходить відповідну дисципліну зі списку за ім'ям і повертає її курс
int DisciplineManager::FindCourseOfSubject(QString subject)
{
    for(int i = 0; i < listOfDisciplines.size(); ++i)
        if(subject == listOfDisciplines[i].GetName())
            return listOfDisciplines[i].GetCourse();
}

//Знаходить відповідну дисципліну зі списку за ім'ям і повертає дні її викладання
QVector<QString> DisciplineManager::GetDaysOfDiscipline(QString disciplineName)
{
    for(int i = 0; i < listOfDisciplines.size(); ++i)
        if(listOfDisciplines[i].GetName() == disciplineName)
            return listOfDisciplines[i].GetDaysInWeek();
}

//Знаходить відповідну дисципліну зі списку за ім'ям і повертає початковий термін викладання
QString DisciplineManager::GetStartDate(QString disciplineName)
{
    for(int i = 0; i < listOfDisciplines.size(); ++i)
        if(listOfDisciplines[i].GetName() == disciplineName)
            return listOfDisciplines[i].GetStartDate();
}

//Знаходить відповідну дисципліну зі списку за ім'ям і повертає кінцевий термін викладання
QString DisciplineManager::GetEndDate(QString disciplineName)
{
    for(int i = 0; i < listOfDisciplines.size(); ++i)
        if(listOfDisciplines[i].GetName() == disciplineName)
            return listOfDisciplines[i].GetEndDate();
}

//Видаляє застарілі дисципліни зі списку предметів та з вчителів, що їх викладали
void DisciplineManager::DeleteAllInfoAboutOutdatedSubjects()
{
    if(listOfDisciplines.isEmpty()) return;
    DeleteOutdatedDisciplinesInfoInTeachers();
    DeleteOutdatedDisciplinesFromList();
}

//Видаляє застарілі дисципліни із даних вчителів що їх викладали
void DisciplineManager::DeleteOutdatedDisciplinesInfoInTeachers()
{
    bool deleteMode;
    int teacherIndex;

    for(auto it = listOfDisciplines.begin(); it < listOfDisciplines.end(); ++it)
        for(int i = 0; i < teachersList.size(); ++i)
        {
            deleteMode = IsOutdatedDiscipline(it);
            if(deleteMode)
                teacherIndex = DeleteDisciplineInfoInTeacher(it);
            if(teachersList[teacherIndex].GetDisciplines().size() == 0)
                teachersList.removeAt(teacherIndex);
        }
}

//Видаляє застарілі дисципліни зі списку дисциплін
void DisciplineManager::DeleteOutdatedDisciplinesFromList()
{
    QString preLastName = listOfDisciplines[listOfDisciplines.size()-2].GetName();
    bool deleteMode;

    for(auto it = listOfDisciplines.begin(); it < listOfDisciplines.end(); ++it)
    {
        QString name = it->GetName();
        deleteMode = IsOutdatedDiscipline(it);
        if(deleteMode && name == preLastName)
        {
            bool checkLastEl = IsOutdatedDiscipline(listOfDisciplines.last());
            if(checkLastEl)
                listOfDisciplines.pop_back();
        }
        else if(deleteMode)
             it = listOfDisciplines.erase(it);
    }
}

//Перевіряє чи передана дисципліна є застарілою, повертає true - якщо застаріла
bool DisciplineManager::IsOutdatedDiscipline(QList<Discipline>::iterator it)
{
   QDate currentDate = QDate::currentDate();
   QDate cmpEndDate = QDate::fromString(it->GetEndDate(),"dd/MM/yyyy");
   if(currentDate > cmpEndDate)
        return true;
}

//Перевіряє чи передана дисципліна є застарілою, повертає true - якщо застаріла
bool DisciplineManager::IsOutdatedDiscipline(Discipline lastElem)
{
    QDate currentDate = QDate::currentDate();
    QDate cmpEndDate = QDate::fromString(lastElem.GetEndDate(),"dd/MM/yyyy");
    if(currentDate > cmpEndDate)
         return true;
}

//Видаляє передану дисципліну у вчителів, повертає індекс вчителя у котрого видалили дисципліну
int DisciplineManager::DeleteDisciplineInfoInTeacher(QList<Discipline>::iterator it)
{
    for(int i = 0; i < teachersList.size(); ++i)
    {
        for(int j = 0; j < teachersList[i].GetDisciplines().size(); ++j)
        {
            if(teachersList[i].GetDisciplines()[j].GetName() == it->GetName())
            {
                if( j == teachersList[i].GetDisciplines().size()-1)
                {
                    teachersList[i].GetOrigDisciplines().pop_back(); //
                    return i;
                }
                else if( j == 0 )
                {
                    teachersList[i].GetOrigDisciplines().pop_front();
                    return i;
                }
                else
                {
                    teachersList[i].GetOrigDisciplines().removeAt(j);
                    return i;
                }
            }
        }
    }
}
