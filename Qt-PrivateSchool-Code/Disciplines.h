#ifndef DISCIPLINES_H
#define DISCIPLINES_H
#include <QMainWindow>
#define DISCIPLINE_NUM 5

class Disciplines
{
public:
    Disciplines()
    {
        for(int i = 0; i < DISCIPLINE_NUM; ++i)
            for(int j = 0; j < DISCIPLINE_NUM; ++j)
                disciplines.push_back("");
    }
private:
    QVector<QVector<QString>> disciplines;
    QVector<QString> firstCourseDisciplines {"Programming", "Geometry", "Physics", "History", "English"};
    QVector<QString> secondCourseDisciplines {"Algorithms", "Electronics", "Teamwork", "Operating Systems", "Web Programming"};
    QVector<QString> thirdCourseDisciplines {"Startups", "Geometry", "Physics", "History", "English"};
    QVector<QString> fourthCourseDisciplines {"Programming", "Geometry", "Physics", "History", "English"};
};

#endif // DISCIPLINES_H
