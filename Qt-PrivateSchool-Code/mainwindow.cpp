#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "loginpage.h"
#include "registrationpage.h"
#include "Teacher.h"
#include "student.h"
#include "discipline.h"
#include "disciplinemanager.h"
#include "file.h"

bool CheckStudMode,CheckTeachMode,CheckAdmMode;
bool oneTimeRunningMode = true;

QList<Discipline> listOfDisciplines;
QList<Teacher> teachersList;
QList<Student> studentsList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   if(oneTimeRunningMode)
   {
       File *fileTmp = new File;
       fileTmp->ReadAndCheckFilesInfo(this);

       DisciplineManager *disciplineManagerTmp = new DisciplineManager;
       disciplineManagerTmp->DeleteAllInfoAboutOutdatedSubjects();

       fileTmp->WriteToFileDisciplines("data\\Disciplines.txt",this);

       ShowDisciplines(ui->comboBox_Disciplines);

       HideElementsForTitleWindow();

       connect(ui->tableWidget_Info, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(tableItemClicked(int,int)));

       oneTimeRunningMode = false;
       delete fileTmp, disciplineManagerTmp;
   }
}

MainWindow::~MainWindow()
{
    File* fileTmp = new File;
    fileTmp->WriteToFileTeachers("data\\TeachersList.txt",this);
    fileTmp->WriteToFileStudents("data\\StudentsList.txt",this);
    delete fileTmp;
    delete ui;
}

//Виводить список дисциплін
void MainWindow::ShowDisciplines(QComboBox *disciplinesBox)
{
    for(auto it = listOfDisciplines.begin(); it != listOfDisciplines.end(); ++it)
    {
        disciplinesBox->addItem(it->GetName().replace(" ","_"));
        it->SetName(it->GetName().replace("_"," "));
    }
}

//Ховає елементи для показу титульного вікна
void MainWindow::HideElementsForTitleWindow()
{
    ui->menuBar->hide();
    ui->toolBar->hide();

    ui->tableWidget_Info->hide();
    ui->pushButton_OkSize->hide();
    ui->pushButton_Set->hide();
    ui->label_TeacherInfo->hide();
    ui->spinBox_Size->hide();
    ui->comboBox_Disciplines->hide();
    ui->label_Disciplines->hide();
    ui->pushButton_AddDiscipline->hide();

    HideNewDisciplineWindowElements();
}

//Зчитує комірку,де виводяться дисципліни у таблиці, на яку користувач натиснув,
//Перевіряє чи даної дисципліни немає у вчителя,
//і також перевіряє чи нема вже у викладача дисциплін із даного курсу
void MainWindow::tableItemClicked(int row, int column)
{
    DisciplineManager *tmp = new DisciplineManager;
    if(column >= DISCIPLINE_AREA)
    {
        QString str = ui->comboBox_Disciplines->currentText();
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setFlags(item->flags() ^ Qt::ItemIsEditable);

        for(int i = DISCIPLINE_AREA; i < ui->tableWidget_Info->columnCount(); ++i)
        {
            item = ui->tableWidget_Info->item(row,i);
            if (!item || item->text().isEmpty())
                break;

            if(tmp->FindCourseOfSubject(str) == tmp->FindCourseOfSubject(item->text()))
                return;
        }
        ui->tableWidget_Info->setItem(row,column,new QTableWidgetItem(str));
        ui->tableWidget_Info->clearSelection();
    }
}

//Приховує елементи розділу створення нової дисципліни
void MainWindow::HideNewDisciplineWindowElements()
{
    ui->commandLinkButton_Close->hide();
    ui->label_DisCourse->hide();
    ui->label_DisName->hide();
    ui->lineEdit_DisciplineName->hide();
    ui->comboBox_DisCourse->hide();
    ui->pushButton_SetDiscipline->hide();
    ui->label_EndDate->hide();
    ui->label_StartDate->hide();
    ui->checkBox_Mon->hide();
    ui->checkBox_Tue->hide();
    ui->checkBox_Wed->hide();
    ui->checkBox_Thu->hide();
    ui->checkBox_Fri->hide();
    ui->dateEdit_Start->hide();
    ui->dateEdit_End->hide();
    ui->label_Days->hide();
    ui->line->hide();
    ui->pushButton_SetNewTeacherInfo->hide();
}

//Відкриває вікно входу в систему як адмін
void MainWindow::on_pushButton_Admin_clicked()
{
    CheckAdmMode = true;
    hide();
    Loginpage window;
    window.setModal(true);
    window.exec();
    show();

    if(CheckAdmMode)
    {
        ui->tableWidget_Info->show();
        ui->menuBar->show();
        ui->toolBar->show();
        ui->pushButton_OkSize->show();
        ui->label_TeacherInfo->show();
        ui->spinBox_Size->show();
        ui->label_Disciplines->show();
        ui->comboBox_Disciplines->show();

        ui->pushButton_Admin->hide();
        ui->pushButton_Student->hide();
        ui->pushButton_Teacher->hide();
        ui->pushButton_Registration->hide();
        ui->label_Title->hide();
        ui->label_Titlelable->hide();
    }
}

//Відкриває вікно реєстрації
void MainWindow::on_pushButton_Registration_clicked()
{
    hide();
    Registrationpage window;
    window.setWindowTitle("Registration");
    window.setWindowIcon(QIcon("Icons\\registration.png"));
    window.setModal(true);
    window.exec();
    show();
}

//Відкриває вікно входу користувача як викладача
void MainWindow::on_pushButton_Teacher_clicked()
{
    CheckTeachMode = true;
    hide();
    Loginpage window;
    window.setWindowTitle("Login");
    window.setWindowIcon(QIcon("Icons\\login.png"));
    window.setModal(true);
    window.exec();
    show();
}

//Відкриває вікно входу користувача як студента
void MainWindow::on_pushButton_Student_clicked()
{
   CheckStudMode = true;
   hide();
   Loginpage window;
   window.setWindowTitle("Login");
   window.setWindowIcon(QIcon("Icons\\login.png"));
   window.setModal(true);
   window.exec();
   show();
}

//Зчитує і виводить ту кількість рядків для вводу інформації про вчителів
void MainWindow::on_pushButton_OkSize_clicked()
{
    int size = ui->spinBox_Size->text().toInt();
    ui->tableWidget_Info->setRowCount(size);

    ShowColumnsHeaderName();

    ui->pushButton_SetNewTeacherInfo->show();
    ui->pushButton_AddDiscipline->show();
    ui->pushButton_Set->show();
}

//Перевіряє і зберігає введену інформацію про вчителів з таблиці
void MainWindow::on_pushButton_Set_clicked()
{
   teachersList.clear();

   try
   {
       CheckReadFromTableInfo();
   }  catch (exception &ex) {
       QMessageBox::critical(this,"Wrong information format",ex.what());
       return;
   }

   for(int i = 0; i < ui->tableWidget_Info->rowCount(); ++i)
   {
     Teacher tmp;
     tmp.surname = ui->tableWidget_Info->item(i,0)->text();
     tmp.SetExperience(ui->tableWidget_Info->item(i,1)->text().toInt());
     QPair<int,QString> tmpPos;
     tmpPos.second = ui->tableWidget_Info->item(i,2)->text();
     tmp.SetPosition(tmpPos);
     tmp.SetPriorityToTeacherPosition();

     tmp.SetPersonalId(ui->tableWidget_Info->item(i,3)->text());
     tmp.SetPassword(ui->tableWidget_Info->item(i,4)->text());

     for(int j = DISCIPLINE_AREA, counter = 0; j < ui->tableWidget_Info->columnCount(); ++j)
     {
         QTableWidgetItem *itm = ui->tableWidget_Info->item(i,j);
         if (!itm || itm->text().isEmpty()) break;
         else
        {
            Discipline tmpDiscip;
            tmpDiscip.SetName(ui->tableWidget_Info->item(i,j)->text());
            tmp.SetDiscipline(tmpDiscip);
            ++counter;
         }
     }
     teachersList.push_back(tmp);
   }
   QMessageBox::information(this,"Set Information", "Successfully saved information");
}

//Виводить заголовки колонок таблиці
void MainWindow::ShowColumnsHeaderName()
{
    ui->tableWidget_Info->setColumnCount(6);

    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("EXPERIENCE(years)"));
    ui->tableWidget_Info->setHorizontalHeaderItem(2, new QTableWidgetItem("POSITION"));
    ui->tableWidget_Info->setHorizontalHeaderItem(3, new QTableWidgetItem("ID"));
    ui->tableWidget_Info->setHorizontalHeaderItem(4, new QTableWidgetItem("PASSWORD"));
    ui->tableWidget_Info->setHorizontalHeaderItem(5, new QTableWidgetItem("DISCIPLINE"));
}

//Викликає функцію для вибору файла із викладачами та зчитує інформацію з нього
void MainWindow::on_actionOpen_triggered()
{
    ui->pushButton_Set->show();

    File *fileTmp = new File;
    fileTmp->OpenFileWithChoise(this);

    QFile file(fileTmp->path);
    QString line,tmp;
    QRegExp symbols("(\\ |\\,|\\.|\\:|\\t+|\\s+)");

    try
    {
       fileTmp->CheckIfOpenFile(file, fileTmp->path);
    }  catch (exception &ex)
    {
        QMessageBox::critical(this,"Pr school:File error",ex.what());
    }

    QTextStream input(&file);

    int counter = 0,max = 0;
    while(!input.atEnd())
    {
        tmp = input.readLine();

        QStringList lineList = tmp.split(symbols);
        if(max < lineList.length())
            max = lineList.length();

        ++counter;
    }
    file.close();
    file.open(QFile::ReadOnly | QFile::Text);

    ui->tableWidget_Info->setRowCount(counter);
    ui->tableWidget_Info->setColumnCount(max);

    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("EXPERIENCE(years)"));
    ui->tableWidget_Info->setHorizontalHeaderItem(2, new QTableWidgetItem("POSITION"));
    ui->tableWidget_Info->setHorizontalHeaderItem(3, new QTableWidgetItem("ID"));
    ui->tableWidget_Info->setHorizontalHeaderItem(4, new QTableWidgetItem("PASSWORD"));
    for(int i = DISCIPLINE_AREA; i < ui->tableWidget_Info->columnCount(); ++i)
        ui->tableWidget_Info->setHorizontalHeaderItem(i, new QTableWidgetItem("DISCIPLINE"));

    ui->pushButton_AddDiscipline->show();
    ui->pushButton_Set->show();

    int j = 0;
    for (int i = 0; i < counter; ++i)
    {
       line = input.readLine();
       QStringList query = line.split(symbols);
       for(int i = 0; i < query.size(); ++i)
           ui->tableWidget_Info->setItem(j,i,new QTableWidgetItem(query.at(i)));
       ++j;
    }
    file.close();

    delete fileTmp;
}

//Добавляє поле для вводу нової дисципліни
void MainWindow::on_pushButton_AddDiscipline_clicked()
{
    ui->tableWidget_Info->setColumnCount(ui->tableWidget_Info->columnCount()+1);
    ui->tableWidget_Info->setHorizontalHeaderItem(ui->tableWidget_Info->columnCount()-1, new QTableWidgetItem("DISCIPLINE"));
}

//Добавляє поле для вводу нового викладача
void MainWindow::on_actionAddTeacher_triggered()
{
    ui->tableWidget_Info->setRowCount(ui->tableWidget_Info->rowCount()+1);
    ui->pushButton_AddDiscipline->show();
    ui->pushButton_SetNewTeacherInfo->show();
}

//Видаляє останнє поле таблиці
void MainWindow::on_actionDeleteTeacher_triggered()
{
    ui->tableWidget_Info->setRowCount(ui->tableWidget_Info->rowCount()-1);
    ui->pushButton_AddDiscipline->show();
}

//Викликає функцію для показу розділу із створенням нової дисципліни
void MainWindow::on_actionCreateDiscipline_triggered()
{
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_DisciplineName->setValidator(validator);

    ShowNewDisciplineWindowElements();
}

//Виводить розділ із створенням нової дисципліни
void MainWindow::ShowNewDisciplineWindowElements()
{
    ui->label_DisCourse->show();
    ui->label_DisName->show();
    ui->lineEdit_DisciplineName->show();
    ui->comboBox_DisCourse->show();
    ui->pushButton_SetDiscipline->show();
    ui->label_EndDate->show();
    ui->label_StartDate->show();
    ui->checkBox_Mon->show();
    ui->checkBox_Tue->show();
    ui->checkBox_Wed->show();
    ui->checkBox_Thu->show();
    ui->checkBox_Fri->show();
    ui->dateEdit_Start->show();
    ui->dateEdit_End->show();
    ui->label_Days->show();
    ui->commandLinkButton_Close->show();
    ui->line->show();
}

//Перевіряє та зберігає інформацію про нову дисципліну
void MainWindow::on_pushButton_SetDiscipline_clicked()
{
   ui->comboBox_Disciplines->addItem(ui->lineEdit_DisciplineName->text());
   int course = ui->comboBox_DisCourse->currentText().toInt();

   Discipline tmpDiscipline;
   tmpDiscipline.SetCourse(course);
   tmpDiscipline.SetName(ui->lineEdit_DisciplineName->text());
   tmpDiscipline.SetStartDate(ui->dateEdit_Start->text());
   tmpDiscipline.SetEndDate(ui->dateEdit_End->text());

   QVector<QString> daysForDiscipline;
   if(ui->checkBox_Mon->isChecked())
       daysForDiscipline.push_back("Mon");
   if(ui->checkBox_Tue->isChecked())
       daysForDiscipline.push_back("Tue");
   if(ui->checkBox_Wed->isChecked())
       daysForDiscipline.push_back("Wed");
   if(ui->checkBox_Thu->isChecked())
       daysForDiscipline.push_back("Thu");
   if(ui->checkBox_Fri->isChecked())
       daysForDiscipline.push_back("Fri");

   tmpDiscipline.SetDaysInWeek(daysForDiscipline);

   for(int i = 0; i < listOfDisciplines.size(); ++i)
       if(listOfDisciplines[i].GetName() == tmpDiscipline.GetName())
       {
           QMessageBox::critical(this,"Add new discipline","This discipline already exists");
           return;
       }

   listOfDisciplines.push_back(tmpDiscipline);

   QDate start = QDate::fromString(tmpDiscipline.GetStartDate(),"dd/MM/yyyy");
   QDate end = QDate::fromString(tmpDiscipline.GetEndDate(),"dd/MM/yyyy");

   if(tmpDiscipline.GetName() == "")
   {
       QMessageBox::critical(this,"DISCIPLINE","Enter name of discipline");
       return;
   }
   else if(end <= start)
   {
       QMessageBox::critical(this,"DISCIPLINE","End date must be more than start date");
       return;
   }
   else if(!daysForDiscipline.size())
   {
       QMessageBox::critical(this,"DISCIPLINE","Choose days for discipline");
       return;
   }
   else
       QMessageBox::information(this, "Add new discipline", "Successful added new discipline to Discipline list");

   QString filePathDisciplines = "data\\Disciplines.txt";
   File *tmpFile = new File;
   tmpFile->WriteToFileNewDiscipline(filePathDisciplines,this);

   HideNewDisciplineWindowElements();

   delete tmpFile;
}

//Ховає елементи вікна для виводу титульної сторінки програми
void MainWindow::on_actionBackToTitle_triggered()
{
    ui->pushButton_Admin->show();
    ui->pushButton_Student->show();
    ui->pushButton_Teacher->show();
    ui->pushButton_Registration->show();
    ui->label_Title->show();
    ui->label_Titlelable->show();

    HideNewDisciplineWindowElements();

    ui->tableWidget_Info->hide();
    ui->menuBar->hide();
    ui->toolBar->hide();
    ui->pushButton_OkSize->hide();
    ui->label_TeacherInfo->hide();
    ui->spinBox_Size->hide();
    ui->label_Disciplines->hide();
    ui->comboBox_Disciplines->hide();
    ui->pushButton_SetNewTeacherInfo->hide();
    ui->pushButton_Set->hide();
    ui->pushButton_AddDiscipline->hide();
}

//Ховає елементи розділу для добавлення нової дисципліни
void MainWindow::on_commandLinkButton_Close_clicked()
{
   HideNewDisciplineWindowElements();
}

//Шукає нових викладачів із таблиці та викликає функцію що зберігає дані про них
void MainWindow::on_pushButton_SetNewTeacherInfo_clicked()
{
    QVector<int> indexesOfNewTeachers;

    for(int i = 0; i < ui->tableWidget_Info->rowCount(); ++i)
    {
        bool checkIfRegisteredString = false;
        for(int j = 0; j < teachersList.size(); ++j)
            if(ui->tableWidget_Info->item(i,0)->text() == teachersList[j].surname)
                checkIfRegisteredString = true;

        if(!checkIfRegisteredString)
            indexesOfNewTeachers.push_back(i);
    }

    if(!indexesOfNewTeachers.size())
    {
        QMessageBox::warning(this,"Add new teachers","There aren`t new teachers in table");
        return;
    }

    int oldSizeTeacherList,newSizeTeacherList;
    oldSizeTeacherList = teachersList.size();

    for(int i = 0; i < indexesOfNewTeachers.size(); ++i)
        SetNewTeacherInfo(indexesOfNewTeachers.at(i));

    newSizeTeacherList = teachersList.size();
    if(newSizeTeacherList - oldSizeTeacherList > 0)
    {
        QMessageBox::information(this,"Add new teachers","Successfully added " +
                                 QString::number(indexesOfNewTeachers.size()) + " teacher(s)");
    }
}

//Перевіряє та зберігає інформацію про нового викладача
void MainWindow::SetNewTeacherInfo(int index)
{
    try {
        CheckReadFromTableLineInfo(index);
    }  catch (exception &ex) {
        QMessageBox::warning(this,"Add new teacher",ex.what());
        return;
    }

    Teacher tmp;
    tmp.surname = ui->tableWidget_Info->item(index,0)->text();
    tmp.SetExperience(ui->tableWidget_Info->item(index,1)->text().toInt());
    QPair<int,QString> tmpPos;
    tmpPos.second = ui->tableWidget_Info->item(index,2)->text();
    tmp.SetPosition(tmpPos);
    tmp.SetPriorityToTeacherPosition();

    tmp.SetPersonalId(ui->tableWidget_Info->item(index,3)->text());
    tmp.SetPassword(ui->tableWidget_Info->item(index,4)->text());

    for(int i = DISCIPLINE_AREA; i < ui->tableWidget_Info->columnCount(); ++i)
    {
        QTableWidgetItem *itm = ui->tableWidget_Info->item(index,i);
        if (!itm || itm->text().isEmpty()) break;
        else
       {
           QString discipName;
           discipName = ui->tableWidget_Info->item(index,i)->text();

           for(int j = 0; j < listOfDisciplines.size(); ++j)
           {
               if(discipName == listOfDisciplines[j].GetName().replace(" ","_"))
               {
                   tmp.SetDiscipline(listOfDisciplines[j]);
                   teachersList.push_back(tmp);
                   return;
               }
           }
        }
    }
}

//Перевіряє правильність введеної інформації у таблиці
void MainWindow::CheckReadFromTableInfo()
{
    for(int i = 0; i < ui->tableWidget_Info->rowCount(); ++i)
        CheckReadFromTableLineInfo(i);
}

//Перевіряє правильність введеної інформації у рядку таблиці
void MainWindow::CheckReadFromTableLineInfo(int index)
{
    QRegExp surnameCheck("(\\d*|\\W*)");// a digit (\d), zero or more times (*), (\w*) word character more than 1
    QRegExp idAndExperienceCheck("\\D*");
    Teacher tmp;

    tmp.surname = ui->tableWidget_Info->item(index,0)->text();
    if (surnameCheck.exactMatch(tmp.surname) || tmp.surname.isEmpty())
        throw runtime_error("In line " + QString::number(index+1).toStdString() + " surname wrong");

    QString experience = ui->tableWidget_Info->item(index,1)->text();
    if (idAndExperienceCheck.exactMatch(experience) || experience.isEmpty())
        throw runtime_error("In line " + QString::number(index+1).toStdString() + " experience wrong");

    QPair<int,QString> tmpPos;
    tmpPos.second = ui->tableWidget_Info->item(index,2)->text();
    tmp.SetPosition(tmpPos);
    tmp.SetPriorityToTeacherPosition();
    if(tmp.GetPosition().first < 0)
        throw runtime_error("In line " + QString::number(index+1).toStdString() + " position wrong");

    QString teacherID = ui->tableWidget_Info->item(index,3)->text();
    for(int i = 0; i < teachersList.size(); ++i)
        if(teacherID == teachersList[i].GetPersonalId())
            throw runtime_error("In line " + QString::number(index+1).toStdString() + " personal id is not unique");
    tmp.SetPersonalId(teacherID);

    if (idAndExperienceCheck.exactMatch(tmp.GetPersonalId()) || tmp.GetPersonalId() == "")
        throw runtime_error("In line " + QString::number(index+1).toStdString() + " id wrong");

    tmp.SetPassword(ui->tableWidget_Info->item(index,4)->text());
    if(tmp.GetPassword() == "")
            throw runtime_error("In line " + QString::number(index+1).toStdString()  + " password is empty");

    for(int j = DISCIPLINE_AREA; j < ui->tableWidget_Info->columnCount(); ++j)
    {
        QTableWidgetItem *itm = ui->tableWidget_Info->item(index,j);
        if (!itm || itm->text().isEmpty()) break;

         QString checkString = itm->text();
        for(int z = 0; z < checkString.size(); ++z)
        {
            if(!checkString[z].isLetter() && checkString[z] != '_' && checkString[z] != '-')
                throw runtime_error("In line " + QString::number(index+1).toStdString() + " discipline format wrong");
        }

        bool check = false;
        for(int k = 0; k < listOfDisciplines.size(); ++k)
        {
            QString name = listOfDisciplines[k].GetName();
            QString formatName = name.replace(" ","_");
            if(formatName == ui->tableWidget_Info->item(index,j)->text())
                check = true;
        }
        if(!check)
            throw runtime_error("In line " + QString::number(index+1).toStdString() + " discipline wrong");
    }
}
