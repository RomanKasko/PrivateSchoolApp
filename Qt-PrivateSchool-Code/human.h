#ifndef HUMAN_H
#define HUMAN_H
#include <QMainWindow>
#include <string>
#include <QDebug>
using namespace std;
#define NUMS_OF_DISCIPLINES 5
#define DISCIPLINE_AREA 5
//Клас, який наслідується вчителем і учнем. Містить поля: прізвище особи,
// пароль, вектор ID осіб, та персональний ID.
class Human
{
    public:
        QString surname;

        Human(QString surname);
        Human();
        ~Human(){};

        void SetPassword(QString pass);
        void SetIdOfPersonsByIndex(QString id, int index);
        void SetIdOfPersons(QVector<QString> IDs);
        void SetPersonalId(QString id);

        QString GetPassword();
        QString GetIdOfPersonsByIndex(int index);
        QVector<QString> GetIdOfPersons();
        QString GetPersonalId();
        int GetSizeOfIdOfPersons();

        void ClearDataAboutIdOfPersons();

    private:
        QString password;
        QVector<QString> idOfPersons;
        QString personalId;

};
#endif // HUMAN_H
