#include "file.h"
#include "discipline.h"
#include "disciplinemanager.h"
#include "Teacher.h"
#include "student.h"
#include <QMessageBox>
#define COURSES 4
File::File(){}

// Функція, у якій зчитується інформація зі всіх необхідних файлів
// Та перевіряє правильність даних у файлах
void File::ReadAndCheckFilesInfo(QMainWindow *window)
{
    try
    {
        CheckDisciplineReadFileFormat("data\\Disciplines.txt");
    }  catch (exception &ex) {
        QMessageBox::critical(window,"Disciplines file read info error", ex.what());
        exit(0);
    }
    ReadFromFileDisciplines("data\\Disciplines.txt");

    try
    {
        CheckStudentReadFileFormat("data\\StudentsList.txt");
    }  catch (exception &ex) {
        QMessageBox::critical(window,"Students file read info error", ex.what());
        exit(0);
    }
    ReadFromFileStudents("data\\StudentsList.txt");

    try
    {
        CheckTeacherReadFileFormat("data\\TeachersList.txt");
    }  catch (exception &ex) {
        QMessageBox::critical(window,"Teachers file read info error", ex.what());
        exit(0);
    }
    ReadFromFileTeachers("data\\TeachersList.txt");
}

//Перевіряє на правильність файл із дисциплінами
void File::CheckDisciplineReadFileFormat(QString path)
{
    //Correct format: 1 Programming 01/09/2020 31/05/2021 Mon Wed Fri
    QFile file(path);
    QVector<QString> days = {"Mon","Tue","Wed","Thu","Fri"};
    QTextStream inDiscipline(&file);
    QString lineDicsipline;
    int counter = 0;
    QRegExp rx("(\\ |\\,|\\:|\\t|\\s+)"); //for ' ' or ',' or '.' or ':' or '\t' or spaces

    try
    {
       CheckIfOpenFile(file, path); // Перевірка чи успішко відкритий файл
       CheckIfEmptyFile(file,path); // Перевірка чи файл не порожній
       CheckReadFileLinesIfEmpty(file,path); // Перевірка чи не містить порожніх лінійок
    }  catch (exception &ex)
    {
        throw runtime_error(ex.what());
        return;
    }

    file.open(QFile::ReadOnly | QFile::Text);
    while(!inDiscipline.atEnd())
    {
        ++counter;
        lineDicsipline = inDiscipline.readLine();
        QStringList query = lineDicsipline.split(rx);
        Discipline lesson;

        QString course = query.at(0);
        if(course.toInt() > COURSES || course.toInt() < 1)
            throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " course num wrong");
        for(int i = 0; i < course.size(); ++i)
            if(!course.at(i).isDigit()) // Перевірка чи номер курсу є цифрою
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " course wrong");

        lesson.SetName(query.at(1));
        for(int i = 0; i < lesson.GetName().size(); ++i) // Перевірка чи назви предметів є літерами, а якщо ні, то допускаються символи '-' та '_'
            if(!lesson.GetName().at(i).isLetter() && lesson.GetName().at(i) != "_" && lesson.GetName().at(i) != "-")
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " subject name wrong");

        lesson.SetStartDate(query.at(2));
        for(int i = 0; i < lesson.GetStartDate().size(); ++i) // Перевірка чи початковий термін є у форматі дд/мм/рррр
            if(!lesson.GetStartDate().at(i).isDigit() && lesson.GetStartDate().at(i) != "/")
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " first date wrong. Correct format 'dd/MM/yyyy'");

        lesson.SetEndDate(query.at(3));
        for(int i = 0; i < lesson.GetEndDate().size(); ++i) // Перевірка чи кінцевий термін є у форматі дд/мм/рррр
            if(!lesson.GetEndDate().at(i).isDigit() && lesson.GetEndDate().at(i) != "/")
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " second date wrong. Correct format 'dd/MM/yyyy'");

        for(int i = DISCIPLINE_DAYS_START_INDEX, disciplineDayNum = 1; i < query.size(); ++i, ++disciplineDayNum)
        {
           QString day = query.at(i);
           if(day.isEmpty()) continue;

           for(int j = 0; j < day.size(); ++j)
               if(!day.at(j).isLetter()) // Перевірка чи назва дня є словом
                    throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() +\
                                         " day " + QString::number(disciplineDayNum).toStdString() + " wrong");
           bool check = false;
           for(int i = 0; i < days.size(); ++i) // Перевірка чи назви дня відповідають формату ('Mon','Tue','Wed','Thu','Fri')
                if(day == days.at(i))
                {
                    check = true;
                    break;
                }

           if(!check)
               throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() +\
                                    " day " + QString::number(disciplineDayNum).toStdString() + " format wrong. It should be ('Mon','Tue','Wed','Thu','Fri')");
        }
    }
    file.close();
}

//Зчитує дані із файлу з дисциплінами
void File::ReadFromFileDisciplines(QString path)
{
    QFile disciplinesFile(path);
    disciplinesFile.open(QFile::ReadOnly | QFile::Text);
    QString courseDisciplinesLine;
    QRegExp rx("(\\ |\\,|\\:|\\t|\\s+)"); //RegEx for ' ' or ',' or '.' or ':' or '\t' or spaces(\s+)

    QTextStream inputDisciplines(&disciplinesFile);
    inputDisciplines.skipWhiteSpace();
    QStringList disciplineInfoList;

    while(!inputDisciplines.atEnd())
    {
        Discipline tmpDiscipline;
        disciplineInfoList.clear();
        courseDisciplinesLine = inputDisciplines.readLine(); //Зчитує з файлу по реченню
        disciplineInfoList = courseDisciplinesLine.split(rx);// Розділяє речення на слова

        tmpDiscipline.SetCourse(disciplineInfoList.at(0).toInt());
        tmpDiscipline.SetName(disciplineInfoList.at(1));
        tmpDiscipline.SetStartDate(disciplineInfoList.at(2));
        tmpDiscipline.SetEndDate(disciplineInfoList.at(3));

        for(int j = 4; j < disciplineInfoList.size(); ++j)
            if(!disciplineInfoList[j].isEmpty())
                 tmpDiscipline.SetDayInWeek(disciplineInfoList.at(j));

        tmpDiscipline.SetName(tmpDiscipline.GetName().replace("_"," "));
        listOfDisciplines.push_back(tmpDiscipline);// Добавляю дисципліну у список
    }
    disciplinesFile.close();
}

//Перевіряє на правильність файл із студентами
void File::CheckStudentReadFileFormat(QString path)
{
    QFile file(path);
    QTextStream inStudent(&file);
    QString lineStudent;
    int counter = 0;
    QRegExp rx("(\\ |\\,|\\:|\\t|\\s+)"); //for ' ' or ',' or '.' or ':' or '\t' or spaces

    try
    {
       CheckIfOpenFile(file, path);
       CheckIfEmptyFile(file,path);
       CheckReadFileLinesIfEmpty(file,path);
    }  catch (exception &ex)
    {
        throw runtime_error(ex.what());
        return;
    }

    file.open(QFile::ReadOnly | QFile::Text);
    while(!inStudent.atEnd())
    {
        ++counter;
        lineStudent = inStudent.readLine(); //Зчитує з файлу по реченню
        QStringList query = lineStudent.split(rx); // Розділяє речення на слова
        Student person;

        person.surname = query.at(0);
        for(int i = 0; i < person.surname.size(); ++i)
            if(!person.surname[i].isLetter()) // Перевіряє чи прізвище є словом
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " surname wrong");

        QString year = query.at(1);
        if(year.toInt() > COURSES || year.toInt() < 1)
            throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " year wrong");

        for(int i = 0; i < year.size(); ++i)
            if (!year[i].isDigit()) // Перевіряє чи курс студента є цифрою
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " year wrong");

        person.SetGroup(query.at(2));
        bool checkNum=false,checkName=false;
        for(int i = 0; i < person.GetGroup().size(); ++i) // Перевіряє чи група студента містить букви та цифри а також символ '-'
        {
            if(person.GetGroup()[i].isDigit()) checkNum = true;
            if(person.GetGroup()[i].isLetter()) checkName = true;
            if(person.GetGroup()[i].isPunct() && person.GetGroup()[i] != "-")
                throw  runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " group wrong");
        }
        if(!checkName || !checkNum)
            throw  runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " group wrong");

        person.SetPersonalId(query.at(3));
        for(int i = 0; i < person.GetPersonalId().size(); ++i)
            if (!person.GetPersonalId()[i].isDigit()) // Перевіряє чи ID студента є числом
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " ID wrong");

        for(int j = DISCIPLINE_AREA, i = 1; j < query.size(); ++j, ++i)
        {
            if (query[j] == "")
                break;
            QString teacherId = query.at(j);
            for(int k = 0; k < teacherId.size(); ++k)
                if (!teacherId[k].isDigit()) // Перевіряє чи ID вчителів студента є числами
                    throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() +\
                                        " Teacher`s " + QString::number(i).toStdString() + " ID wrong");
        }
    }
    file.close();
}

//Зчитує дані із файлу з студентами
void File::ReadFromFileStudents(QString path)
{
    QFile studentFile(path);
    QString lineStudent;
    QRegExp rx("(\\ |\\,|\\:|\\t|\\s+)"); //RegEx for ' ' or ',' or '.' or ':' or '\t' or spaces
    studentFile.open(QFile::ReadOnly | QFile::Text);

    QTextStream in(&studentFile);
    in.skipWhiteSpace();
    int counter = 0;
    while(!in.atEnd())
    {
        lineStudent = in.readLine();
        ++counter;
    }
    studentFile.close();
    studentFile.open(QFile::ReadOnly | QFile::Text);

    int j = 0;
    for (int i = 0; i < counter; ++i)
    {
       lineStudent = in.readLine();
       QStringList query = lineStudent.split(rx);
       QVector<QString> tmpVect;

       Student person;
       person.surname = query.at(0);
       person.SetYear(query.at(1).toInt());
       person.SetDisciplinesToStudent(person,person.GetYear());

       person.SetGroup(query.at(2));
       person.SetPersonalId(query.at(3));
       person.SetPassword(query.at(4));

       for(int j = DISCIPLINE_AREA; j < query.size(); ++j)
       {
           if(query.at(j) == "")
               continue;
           tmpVect.push_back(query.at(j));
       }
       person.SetIdOfPersons(tmpVect);
       studentsList.push_back(person); // Добавляю студента до списку

       ++j;
    }
    studentFile.close();
}

//Перевіряє на правильність файл із вчителями
void File::CheckTeacherReadFileFormat(QString path)
{
    QFile file(path);
    QTextStream inTeacher(&file);
    QString lineTeacher;
    int counter = 0;
    QRegExp rx("(\\ |\\,|\\:|\\t|\\s+)"); //for ' ' or ',' or '.' or ':' or '\t' or spaces
    QRegExp surnameCheck("(\\d*|\\W*)");// a digit (\d), zero or more times (*), (\w*) word character more than 1
    QRegExp idAndExperienceCheck("\\D*");

    try
    {
        CheckIfOpenFile(file, path);
        CheckReadFileLinesIfEmpty(file,path);
        CheckIfEmptyFile(file,path);
    }  catch (exception &ex)
    {
        throw runtime_error(ex.what());
        return;
    }

    file.open(QFile::ReadOnly | QFile::Text);
    while(!inTeacher.atEnd())
    {
        ++counter;
        Teacher person;
        lineTeacher = inTeacher.readLine();
        QStringList query = lineTeacher.split(rx);

        person.surname = query.at(0);
        for(int i = 0; i < person.surname.size(); ++i)
            if(!person.surname[i].isLetter())
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " surname wrong");

        QString experience = query.at(1);
        if(experience < 1)
            throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " experience wrong");
        if (idAndExperienceCheck.exactMatch(experience))
            throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " experience wrong");

        QPair<int,QString> tmpPos;
        tmpPos.second = query.at(2);
        person.SetPosition(tmpPos);
        person.SetPriorityToTeacherPosition();
        if(person.GetPosition().first < 0)
            throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " position wrong");

        QString teacherID = query.at(3);
        for(int i = 0; i < teacherID.size(); ++i)
            if(!teacherID[i].isDigit())
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " ID wrong");

        for(int j = DISCIPLINE_AREA, disciplineNum = 1; j < query.size(); ++j, ++disciplineNum)
        {
            if (query.at(j).isEmpty())
                break;

            QString checkString = query.at(j);
            for(int z = 0; z < checkString.size(); ++z)
            {
                if(!checkString[z].isLetter() && checkString[z] != '_' && checkString[z] != '-')
                    throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " discipline " +\
                                        QString::number(disciplineNum).toStdString()+ ": name format wrong");
            }

            bool check = false;
            for(int k = 0; k < listOfDisciplines.size(); ++k)
            {
                QString name = listOfDisciplines[k].GetName();
                QString formatName = name.replace(" ","_");
                if(formatName == query.at(j))
                    check = true;
            }
            if(!check)
                throw runtime_error("In file: " + path.toStdString() + " line " + QString::number(counter).toStdString() + " discipline " +\
                                    QString::number(disciplineNum).toStdString()+ ": name wrong");
        }
    }
    file.close();
}

//Зчитує інформацію про вчителів із файлу
void File::ReadFromFileTeachers(QString path)
{
    QFile teacherFile(path);
    QString lineTeacher;
    QRegExp rx("(\\ |\\,|\\:|\\t|\\s+)"); //RegEx for ' ' or ',' or '.' or ':' or '\t' or spaces

    teacherFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inTeacher(&teacherFile);
    int counter2 = 0;
    while(!inTeacher.atEnd())
    {
        lineTeacher = inTeacher.readLine();
        ++counter2;
    }
    teacherFile.close();
    teacherFile.open(QFile::ReadOnly | QFile::Text);

    int k = 0;
    for (int i = 0; i < counter2; ++i)
    {
       int indexCounter = 0;
       lineTeacher = inTeacher.readLine();
       QStringList query = lineTeacher.split(rx);

       Teacher person;

       QString position;
       QVector<QString> discipline;
       person.surname = query.at(0);
       person.SetExperience(query.at(1).toInt());

       QPair<int,QString> tmpPos;
       tmpPos.second = query.at(2);
       person.SetPosition(tmpPos);
       person.SetPriorityToTeacherPosition();

       person.SetPersonalId(query.at(3));
       person.SetPassword(query.at(4));

       Discipline tmp;
       QVector<QString> tmpDays;
       DisciplineManager tmpManager;
       for(int l = DISCIPLINE_AREA, b = 0; l < query.size(); ++l, ++b)
       {
           tmp.SetName(query.at(l));
           tmp.SetName(tmp.GetName().replace("_"," "));

           tmp.SetCourse(tmpManager.FindCourseOfSubject(tmp.GetName()));
           tmp.SetStartDate(tmpManager.GetStartDate(tmp.GetName()));
           tmp.SetEndDate(tmpManager.GetEndDate(tmp.GetName()));
           tmp.SetDaysInWeek(tmpManager.GetDaysOfDiscipline(tmp.GetName()));

           person.SetDiscipline(tmp);
       }

       for(int m = 0; m < studentsList.size(); ++m)
           for(int l = 0; l < studentsList[k].GetSizeOfIdOfPersons(); ++l)
           {
               if(l > studentsList[m].GetSizeOfIdOfPersons()-1)
                   continue;
               if(person.GetPersonalId() == studentsList[m].GetIdOfPersonsByIndex(l))
               {
                   person.SetIdOfPersonsByIndex(studentsList[m].GetPersonalId(),indexCounter);
                   ++indexCounter;
               } 
           }
       teachersList.push_back(person); // вношу вчителя у список
       ++k;
    }

    teacherFile.close();
}

//Перевіряє чи файл успішно відкрився
void File::CheckIfOpenFile(QFile &file, QString name)
{
    if(!file.open(QFile::ReadOnly | QFile::Text))
        throw runtime_error(" Could not open " + name.toStdString() + " file ");
}

//Перевіряє чи файл не є порожнім
void File::CheckIfEmptyFile(QFile &file, QString name)
{
    if(!file.size())
        throw runtime_error(" File " + name.toStdString() + " is empty ");
}

//Перевіряє чи у файлі відсутні порожні рядки
void File::CheckReadFileLinesIfEmpty(QFile &file, QString name)
{
    QTextStream inTeacher(&file);
    while(!inTeacher.atEnd())
    {
        if(inTeacher.readLine().isEmpty())
            throw runtime_error("File: " + name.toStdString() + " has empty lines");
    }
    file.close();
}

//Записує список вчителів у файл
void File::WriteToFileTeachers(QString path, QMainWindow *window)
{
    QFile teacherFile(path);

    if(!teacherFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(window,"File","File not open");
        return;
    }
    QTextStream out(&teacherFile);
    int lenght = teachersList.length();

    for(int i = 0; i < teachersList.size(); ++i)
        for(int j = 0; j < teachersList[i].GetDisciplines().size(); ++j)
           teachersList[i].SetDisciplineNameByIndex(j,teachersList[i].GetDisciplines()[j].GetName().replace(" ","_"));


    for (int i = 0; i < lenght; ++i)
    {
        //Correct format: Nickerman 4 Teacher 198765 nickerman123 Algebra Geometry
        QString disciplines = "";
        for(int j = 0; j < teachersList[i].GetDisciplines().size(); ++j)
        {
            if(j == teachersList[i].GetDisciplines().size()-1)
                 disciplines += teachersList[i].GetDisciplines()[j].GetName();
             else
                disciplines += teachersList[i].GetDisciplines()[j].GetName() + " ";
        }

        QString text = teachersList[i].surname + "\t" + QString::number(teachersList[i].GetExperience()) + "\t" +\
                       teachersList[i].GetPosition().second + "\t" + teachersList[i].GetPersonalId() + "\t" +\
                       teachersList[i].GetPassword() + "\t" + disciplines + "\n";
        out << text;
    }
    teacherFile.flush();
    teacherFile.close();
}

//Записує у файл нову дисципліну
void File::WriteToFileNewDiscipline(QString path, QMainWindow *window)
{
    QFile disciplinesFile(path);
    QString courseDisciplinesLine;

    try
    {
       CheckIfOpenFile(disciplinesFile, path);
    }  catch (exception &ex)
    {
        QMessageBox::critical(window,"IT Private school: File error",ex.what());
        return;
    }

    disciplinesFile.close();
    disciplinesFile.open(QIODevice::WriteOnly | QIODevice::Append);

    QTextStream out(&disciplinesFile);
    QString days="";
    for(int i = 0; i < listOfDisciplines.last().GetDaysInWeek().size(); ++i)
        days += listOfDisciplines.last().GetDaysInWeek()[i] + " ";

    //Correct format: 2 Algorithms 01/09/2020 31/05/2021 Mon Thu Fri
    listOfDisciplines.last().SetName(listOfDisciplines.last().GetName().replace(" ","_"));
    QString text = "\n" + QString::number(listOfDisciplines.last().GetCourse()) + "\t" + listOfDisciplines.last().GetName() + "\t" +\
                   listOfDisciplines.last().GetStartDate()  + "\t" + listOfDisciplines.last().GetEndDate() + "\t" + days;
    out << text;

    disciplinesFile.flush();
    disciplinesFile.close();
    listOfDisciplines.last().SetName(listOfDisciplines.last().GetName().replace("_"," "));
}

//Записує список дисциплін у файл
void File::WriteToFileDisciplines(QString path, QMainWindow *window)
{
    QFile disciplinesFile(path);

    try
    {
       CheckIfOpenFile(disciplinesFile, path);
    }  catch (exception &ex)
    {
        QMessageBox::critical(window,"IT Private school: File error",ex.what());
        exit(0);
    }

    disciplinesFile.close();
    disciplinesFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&disciplinesFile);

    for(int i = 0; i < listOfDisciplines.size(); ++i)
    {
        QString days="";
        for(int j = 0; j < listOfDisciplines[i].GetCountOfDays(); ++j)
            days += listOfDisciplines[i].GetDayByIndex(j) + " ";

        QString text;
        if(i == 0)
        {
            listOfDisciplines[i].SetName(listOfDisciplines[i].GetName().replace(" ","_"));
            text = QString::number(listOfDisciplines[i].GetCourse()) + " " + listOfDisciplines[i].GetName() + "\t" +\
                           listOfDisciplines[i].GetStartDate()  + "\t" + listOfDisciplines[i].GetEndDate() + "\t" + days;
        }
        else
        {
            listOfDisciplines[i].SetName(listOfDisciplines[i].GetName().replace(" ","_"));
            text = "\n" + QString::number(listOfDisciplines[i].GetCourse()) + " " + listOfDisciplines[i].GetName() + "\t" +\
                           listOfDisciplines[i].GetStartDate()  + "\t" + listOfDisciplines[i].GetEndDate() + "\t" + days;
        }
        //Correct format: 2 Algorithms 01/09/2020 31/05/2021 Mon Thu Fri
        out << text;
        listOfDisciplines[i].SetName(listOfDisciplines[i].GetName().replace("_"," "));
    }
    disciplinesFile.close();
}

//Записує список студентів у файл
void File::WriteToFileStudents(QString path, QMainWindow *window)
{
    QFile studentsFile(path);

    try
    {
       CheckIfOpenFile(studentsFile, path);
    }  catch (exception &ex)
    {
        QMessageBox::critical(window,"IT Private school: File error",ex.what());
        exit(0);
    }

    studentsFile.close();
    studentsFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&studentsFile);

    for(int i = 0; i < studentsList.size(); ++i)
    {
        QString teachersIDs="";
        for(int j = 0; j < studentsList[i].GetSizeOfIdOfPersons(); ++j)
            teachersIDs += studentsList[i].GetIdOfPersonsByIndex(j) + " ";

        QString text;
        if(i == 0)
        {
             text = studentsList[i].surname + " " + QString::number(studentsList[i].GetYear()) + "\t" +\
                    studentsList[i].GetGroup()   + "\t"+ studentsList[i].GetPersonalId()       + "\t" +\
                    studentsList[i].GetPassword() + "\t" + teachersIDs;
        }
        else
        {
            text = "\n" + studentsList[i].surname + " " + QString::number(studentsList[i].GetYear()) + "\t" +\
                          studentsList[i].GetGroup()   + "\t"+ studentsList[i].GetPersonalId()       + "\t" +\
                          studentsList[i].GetPassword() + "\t" + teachersIDs;
        }
        //Correct format: Savkiv 4 PZ-46 400045 31.12.2000 460046 346000 200100 100100 999999
        out << text;
    }
    studentsFile.flush();
    studentsFile.close();
}

//Відкриває вікно для вибору '.txt' файла
void File::OpenFileWithChoise(QMainWindow *window)
{
    this->path = QFileDialog::getOpenFileName(window,"Open the file", " " , "*.txt");
}
