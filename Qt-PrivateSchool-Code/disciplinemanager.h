#ifndef DISCIPLINEMANAGER_H
#define DISCIPLINEMANAGER_H
#include "discipline.h"
//Клас, що працює із списком дисциплін
class DisciplineManager
{
public:
    DisciplineManager();

    int FindCourseOfSubject(QString subject);
    QVector<QString> GetDaysOfDiscipline(QString disciplineName);
    QString GetStartDate(QString disciplineName);
    QString GetEndDate(QString disciplineName);

    bool IsOutdatedDiscipline(QList<Discipline>::iterator it);
    bool IsOutdatedDiscipline(Discipline lastElem);

    void DeleteAllInfoAboutOutdatedSubjects();
    void DeleteOutdatedDisciplinesFromList();
    void DeleteOutdatedDisciplinesInfoInTeachers();
    int  DeleteDisciplineInfoInTeacher(QList<Discipline>::iterator it);
};

#endif // DISCIPLINEMANAGER_H
