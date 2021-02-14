#include "studentpage.h"
#include "ui_studentpage.h"

#include "mainwindow.h"
#include "loginpage.h"
#include "student.h"
#include "discipline.h"
#include "disciplinemanager.h"

#define PRINT_DISCIPLINE_MODE 2
#define PRINT_COURSE 1

StudentPage::StudentPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentPage)
{
    ui->setupUi(this);

    QStringList parts = student.surname.toLower().split(' ', QString::SkipEmptyParts);
        for (int i = 0; i < parts.size(); ++i)
            parts[i].replace(0, 1, parts[i][0].toUpper());

    ui->label_Surname->setText("Welcome " + parts.join(" "));
    ui->tableWidget_Disciplines->setColumnCount(2);
    ui->tableWidget_Disciplines->setRowCount(student.GetLessons().size());
    ui->calendarWidget->showToday();

    for(int i = 0; i < listOfDisciplines.size(); ++i)
        ui->comboBox_Disciplines->addItem(listOfDisciplines[i].GetName());

    if(student.GetSizeOfIdOfPersons() >= NUMS_OF_DISCIPLINES)
    {
        ShowMyTeachersWithDisciplines();
    }
    else if(student.GetSizeOfIdOfPersons())
    {
        connect(ui->tableWidget_Info, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
        ShowMyDisciplines();
        ShowMyTeachers();
    }
    else
    {
        connect(ui->tableWidget_Info, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));
        ShowMyDisciplines();
    }
}

StudentPage::~StudentPage()
{
    delete ui;
}

//Виводить інформацію про дисципліни студента та відповідними його вчителями
void StudentPage::ShowMyTeachersWithDisciplines()
{
   QList<Teacher> myTeachers;
   ui->pushButton_ChooseTeacher->hide();

   for(int i = 0; i < teachersList.size(); ++i)
       for(int j = 0; j < student.GetSizeOfIdOfPersons(); ++j)
           if(teachersList[i].GetPersonalId() == student.GetIdOfPersonsByIndex(j))
               myTeachers.push_back(teachersList[i]);

   ui->tableWidget_Disciplines->setHorizontalHeaderItem(0, new QTableWidgetItem("MY DISCIPLINES"));
   ui->tableWidget_Disciplines->setHorizontalHeaderItem(1, new QTableWidgetItem("SURNAMES"));
   for(int k = 0; k < student.GetLessons().size(); ++k)
       for(int i = 0; i < myTeachers.size(); ++i)
           for(int j = 0; j < myTeachers[i].GetDisciplines().size(); ++j)
           {
               if(student.GetLessons()[k] == myTeachers[i].GetDisciplines()[j].GetName().replace("_"," "))
               {
                   ui->comboBox_MyDisciplines->addItem(student.GetLessons()[k]);
                   ui->tableWidget_Disciplines->setItem(k,0,new QTableWidgetItem(student.GetLessons()[k]));
                   ui->tableWidget_Disciplines->setItem(k,1,new QTableWidgetItem(myTeachers[i].surname));
               }
           }
}

//Виводить інформацію про дисципліни студента
void StudentPage::ShowMyDisciplines()
{
    ui->tableWidget_Disciplines->setHorizontalHeaderItem(0, new QTableWidgetItem("MY DISCIPLINES"));
    ui->tableWidget_Disciplines->setHorizontalHeaderItem(1, new QTableWidgetItem("SURNAMES"));
    for(int k = 0; k < student.GetLessons().size(); ++k)
    {
        ui->comboBox_MyDisciplines->addItem(student.GetLessons()[k]);
        ui->tableWidget_Disciplines->setItem(k,0,new QTableWidgetItem(student.GetLessons()[k]));
    }
}

//Виводить інформацію про викладачів студента
void StudentPage::ShowMyTeachers()
{
    ui->pushButton_ChooseTeacher->show();
    QList<Teacher> myTeachers;
    for(int i = 0; i < teachersList.size(); ++i)
        for(int j = 0; j < student.GetSizeOfIdOfPersons(); ++j)
            if(teachersList[i].GetPersonalId() == student.GetIdOfPersonsByIndex(j))
                myTeachers.push_back(teachersList[i]);

    for(int i = 0; i < myTeachers.size(); ++i)
        ui->tableWidget_Disciplines->setItem(i,1,new QTableWidgetItem(myTeachers[i].surname));
}

//Зчитує комірку із прізвищем викладача і вставляє у поле з дисциплінами студента
void StudentPage::tableItemClicked(int row, int column)
{
  if(!column)
  {
     QTableWidgetItem *item = new QTableWidgetItem();
     item->setFlags(item->flags() ^ Qt::ItemIsEditable);

     QString subject = ui->comboBox_MyDisciplines->currentText();
     QString surname = ui->tableWidget_Info->item(row,column)->text();

     for(int i = 0; i < ui->tableWidget_Disciplines->rowCount(); ++i)
         if(ui->tableWidget_Disciplines->item(i,0)->text() == subject)
         {
            ui->tableWidget_Disciplines->setItem(i,column + 1, new QTableWidgetItem(surname));
         }

     ui->tableWidget_Info->clearSelection();
  }
}

//Виводить інформацію обраних вчителів
void StudentPage::PrintInfo(QTableWidget *tableTeacherInfo, QList<Teacher> list, int mode)
{
    tableTeacherInfo->setRowCount(list.size());
    for(int i = 0; i < list.size(); ++i)
    {
        tableTeacherInfo->setItem(i,0,new QTableWidgetItem(list[i].surname));
        tableTeacherInfo->setItem(i,1,new QTableWidgetItem(list[i].GetPosition().second));

        if(mode == PRINT_COURSE)
        {
            tableTeacherInfo->setItem(i,2,new QTableWidgetItem(list[i].GetDisciplines()[0].GetName().replace("_"," ")));
            tableTeacherInfo->setItem(i,3,new QTableWidgetItem(list[i].GetDisciplines()[0].GetCourse()));
        }
        else if(mode == PRINT_DISCIPLINE_MODE)
        {
            for(int j = 0; j < list[i].GetDisciplines().size(); ++j)
                tableTeacherInfo->setItem(i,2+j,new QTableWidgetItem(list[i].GetDisciplines()[j].GetName().replace("_"," ")));
        }
    }
}

//Викликає метод студента для сортування викладачів за прізвищем і виводить дані
void StudentPage::on_pushButton_SortSurname_clicked()
{
   ui->tableWidget_Info->setColumnCount(2);
   ui->tableWidget_Info->setRowCount(teachersList.size());
   ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
   ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("POSITION"));
   student.SortTeacherListBySurname(teachersList);
   PrintInfo(ui->tableWidget_Info,teachersList,0);
}

//Викликає метод студента для сортування викладачів за посадою і виводить дані
void StudentPage::on_pushButton_SortPosition_clicked()
{
    ui->tableWidget_Info->setColumnCount(2);
    ui->tableWidget_Info->setRowCount(teachersList.size());
    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("POSITION"));
    student.SortTeacherListByPosition(teachersList);
    PrintInfo(ui->tableWidget_Info,teachersList,0);
}

//Викликає метод студента для пошуку викладачів з одною дисципліною і виводить дані
void StudentPage::on_pushButton_Teacher1Disc_clicked()
{
    QList<Teacher> resList;
    student.FindTeachersWhoHaveOneSubject(teachersList,resList);
    ui->tableWidget_Info->setColumnCount(3);
    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("POSITION"));
    ui->tableWidget_Info->setHorizontalHeaderItem(2, new QTableWidgetItem("DISCIPLINE"));

    PrintInfo(ui->tableWidget_Info,resList,PRINT_COURSE);
}

//Викликає метод студента для пошуку найпопулярнішого викладача і виводить дані
void StudentPage::on_pushButton_FindTheMostPopularTeacher_clicked()
{
    Teacher mostPopularTeacher;
    int studentCounter;
    studentCounter = student.FindTheMostPopularTeacher(teachersList,ui->comboBox_Disciplines,mostPopularTeacher);
    if(studentCounter < 1) return;
    ui->tableWidget_Info->setColumnCount(4);
    ui->tableWidget_Info->setRowCount(1);

    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("POSITION"));
    ui->tableWidget_Info->setHorizontalHeaderItem(2, new QTableWidgetItem("DISCIPLINE"));
    ui->tableWidget_Info->setHorizontalHeaderItem(3, new QTableWidgetItem("STUDENTS"));

    ui->tableWidget_Info->setItem(0,0,new QTableWidgetItem(mostPopularTeacher.surname));
    ui->tableWidget_Info->setItem(0,1,new QTableWidgetItem(mostPopularTeacher.GetPosition().second));
    ui->tableWidget_Info->setItem(0,2,new QTableWidgetItem(ui->comboBox_Disciplines->currentText()));
    ui->tableWidget_Info->setItem(0,3,new QTableWidgetItem(QString::number(studentCounter)));
}

//Виводить дані всіх вчителів котрі мають передану дисципліну
void StudentPage::ShowTeachersListInfo(QString subject, QTableWidget *table)
{
    QList<Teacher> thisDiscipTeachers;
    int max = teachersList[0].GetDisciplines().size();

    for(int i = 0; i < teachersList.size(); ++i)
        for(int j = 0; j < teachersList[i].GetDisciplines().size(); ++j)
            if(teachersList[i].GetDisciplines()[j].GetName().replace("_"," ") == subject)
                thisDiscipTeachers.push_back(teachersList[i]);

    for(int i = 1; i < thisDiscipTeachers.size(); ++i)
        if(max < thisDiscipTeachers[i].GetDisciplines().size())
            max = thisDiscipTeachers[i].GetDisciplines().size();

    table->setColumnCount(2+max);
    table->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    table->setHorizontalHeaderItem(1, new QTableWidgetItem("POSITION"));
    for(int i = 2; i < table->columnCount(); ++i)
        table->setHorizontalHeaderItem(i, new QTableWidgetItem("DISCIPLINE"));

    PrintInfo(table,thisDiscipTeachers,PRINT_DISCIPLINE_MODE);
}

void StudentPage::on_pushButton_ShowTeachers_clicked()
{
    ShowTeachersListInfo(ui->comboBox_Disciplines->currentText(),ui->tableWidget_Info);
}

void StudentPage::on_pushButton_ShowMyDisTeachers_clicked()
{
     ShowTeachersListInfo(ui->comboBox_MyDisciplines->currentText(),ui->tableWidget_Info);
}

//Записує студенту його вибраного викладача на певну дисципліну
void StudentPage::on_pushButton_ChooseTeacher_clicked()
{
    int row;
    QString id;
    QString subject = ui->comboBox_MyDisciplines->currentText();

    if(subject == "")
        return;

    for(int i = 0; i < ui->tableWidget_Disciplines->rowCount(); ++i)
        if(subject == ui->tableWidget_Disciplines->item(i,0)->text())
        {
            row = i;
            break;
        }

    for(int i = 0; i < teachersList.size(); ++i)
        if(teachersList[i].surname == ui->tableWidget_Disciplines->item(row,1)->text())
        {
            id = teachersList[i].GetPersonalId();
            teachersList[i].SetIdOfPersonsByIndex(student.GetPersonalId(),teachersList[i].GetSizeOfIdOfPersons());
            break;
        }

    student.ChooseTeacher(id);
    if(student.GetSizeOfIdOfPersons() == ui->comboBox_MyDisciplines->count())
    {
        for(int i = 0; i < studentsList.size(); ++i)
        {
            if(studentsList[i].surname.toLower() == student.surname.toLower() && studentsList[i].GetGroup().toUpper() == student.GetGroup().toUpper())
            {
                studentsList[i].SetIdOfPersons(student.GetIdOfPersons());
                QMessageBox::information(this, "Add teachers", "Successful added your teachers");
                break;
            }
        }
    }
}

//Знаходить вільних викладачів за вказаною датою
void StudentPage::on_pushButton_FindFreeTeachersByDate_clicked()
{
    QList<Teacher> freeTeachers;
    QLocale objectForDayOfWeek;
    QDate selectedDate = ui->calendarWidget->selectedDate();
    QString day = objectForDayOfWeek.dayName(selectedDate.dayOfWeek(),QLocale::ShortFormat);
    QDate startDate,endDate;
    QVector<QString> disciplineDays;
    DisciplineManager *tmpDiscManager = new DisciplineManager;

    for(int i = 0; i < teachersList.size(); ++i)
    {
        bool flag = true;
        for(int j = 0; j < teachersList[i].GetDisciplines().size(); ++j)
        {
            startDate = QDate::fromString(tmpDiscManager->GetStartDate(teachersList[i].GetDisciplines()[j].GetName()),"dd/MM/yyyy");
            endDate = QDate::fromString(tmpDiscManager->GetEndDate(teachersList[i].GetDisciplines()[j].GetName()),"dd/MM/yyyy");
            disciplineDays = tmpDiscManager->GetDaysOfDiscipline(teachersList[i].GetDisciplines()[j].GetName());

            for(int k = 0; k < disciplineDays.size(); ++k)
            {
                if(day == disciplineDays[k] || selectedDate > endDate || selectedDate < startDate)
                {
                     flag = false;
                     continue;
                }
            }
        }
         if(flag) freeTeachers.push_back(teachersList[i]);
    }

    ui->tableWidget_Info->setRowCount(freeTeachers.size());

    int max = freeTeachers[0].GetDisciplines().size();
    for(int i = 1; i < freeTeachers.size(); ++i)
        if(max < freeTeachers[i].GetDisciplines().size())
            max = freeTeachers[i].GetDisciplines().size();

    ui->tableWidget_Info->setColumnCount(2+max);
    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("POSITION"));

    for(int i = 2; i < ui->tableWidget_Info->columnCount(); ++i)
        ui->tableWidget_Info->setHorizontalHeaderItem(i, new QTableWidgetItem("DISCIPLINE"));

    PrintInfo(ui->tableWidget_Info,freeTeachers,PRINT_DISCIPLINE_MODE);
}

//Відкриває головне вікно програми
void StudentPage::on_commandLinkButton_BackLink_clicked()
{
    hide();
    MainWindow window;
    window.show();
}

//Створює контекстне меню
void StudentPage::on_tableWidget_Info_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu();
    menu->setContextMenuPolicy(Qt::ActionsContextMenu);

    QAction *action = new QAction("Sort by surname");
    QAction *action2 = new QAction("Sort by position");
    connect(action, SIGNAL(triggered()), this, SLOT(on_pushButton_SortSurname_clicked()));
    connect(action2, SIGNAL(triggered()), this, SLOT(on_pushButton_SortPosition_clicked()));

    menu->addActions({ action, action2 });
    menu->exec(cursor().pos());
}
