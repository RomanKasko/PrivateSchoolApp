#include "human.h"
Human::Human(){}

Human::Human(QString surname)
{
    this->surname = surname;
}

void Human::SetPassword(QString pass)
{
    password = pass;
};

QString Human::GetPassword()
{
    return password;
};

void Human::SetPersonalId(QString id)
{
    personalId = id;
}

QString Human::GetPersonalId()
{
    return personalId;
}

void Human::SetIdOfPersons(QVector<QString> IDs)
{
    idOfPersons.clear();
    for(int i = 0; i < IDs.size(); ++i)
    {
        idOfPersons.push_back(IDs[i]);
    }
}

QVector<QString> Human::GetIdOfPersons()
{
    return idOfPersons;
}

//Очищає вектор із записаними ID людей
void Human::ClearDataAboutIdOfPersons()
{
    idOfPersons.clear();
}

//Записує інформацію про ID людини у задану позицію
void Human::SetIdOfPersonsByIndex(QString id, int index)
{
    if(index - idOfPersons.size() == 0)
        idOfPersons.push_back(id);
    else if(index - idOfPersons.size() > 1)
        qDebug() << "Index is more than size()";
    else if(index == 0)
        idOfPersons.push_back(id);
    else
        idOfPersons.replace(index,id);
}

QString Human::GetIdOfPersonsByIndex(int index)
{
    if(index > idOfPersons.size())
    {
        qDebug() << "Index is more than size()";
        return "Error";
    }
    else return idOfPersons[index];
}

int Human::GetSizeOfIdOfPersons()
{
    return idOfPersons.size();
}
