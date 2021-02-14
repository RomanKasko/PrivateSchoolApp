#include "teacherpage.h"
#include "ui_teacherpage.h"
#include "mainwindow.h"
#include "Teacher.h"
#include "loginpage.h"

TeacherPage::TeacherPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeacherPage)
{
    ui->setupUi(this);

    QStringList parts = teacher.surname.toLower().split(' ', QString::SkipEmptyParts);
        for (int i = 0; i < parts.size(); ++i)
            parts[i].replace(0, 1, parts[i][0].toUpper());

    ui->label_Surname->setText("Welcome " + parts.join(" "));

    ui->pushButton_SortStudentsByName->hide();
    ui->pushButton_SortStudentsbyGroup->hide();
    PrintTeacherDisciplinesInfo();

    QPixmap pixmap("D:\\University\\Project\\PrivateSchool\\Icons\\list.ico");
    QIcon ButtonIcon(pixmap);
    ui->pushButton_AllEnrolledStud->setIcon(ButtonIcon);
    ui->pushButton_AllEnrolledStud->setIconSize(pixmap.rect().size());

    QPixmap studentPixmap("D:\\University\\Project\\PrivateSchool\\Icons\\student.ico");
    ui->pushButton_ShowStudents->setIcon(QIcon(studentPixmap));
    ui->pushButton_ShowStudents->setIconSize(studentPixmap.rect().size());

    if(teacher.GetDisciplines().size() == 1)
    {
        ui->comboBox_Disciplines->hide();
        ui->pushButton_AllEnrolledStud->hide();
    }

    for(int i = 0; i < teacher.GetDisciplines().size(); ++i)
        ui->comboBox_Disciplines->addItem(teacher.GetDisciplines()[i].GetName().replace("_"," "));
}

TeacherPage::~TeacherPage()
{
    delete ui;
}

//Виводить інформацію про дисципліни викладача
void TeacherPage::PrintTeacherDisciplinesInfo()
{
    int maxDaysCounter = 0;
    for(int i = 0; i < teacher.GetDisciplines().size(); ++i)
        if(maxDaysCounter < teacher.GetDisciplines()[i].GetDaysInWeek().size())
            maxDaysCounter = teacher.GetDisciplines()[i].GetDaysInWeek().size();

    ui->tableWidget_DisciplinesInfo->setColumnCount(3 + maxDaysCounter);
    ui->tableWidget_DisciplinesInfo->setRowCount(teacher.GetDisciplines().size());

    ui->tableWidget_DisciplinesInfo->setHorizontalHeaderItem(0, new QTableWidgetItem("DISCIPLINE"));
    ui->tableWidget_DisciplinesInfo->setHorizontalHeaderItem(1, new QTableWidgetItem("START PERIOD"));
    ui->tableWidget_DisciplinesInfo->setHorizontalHeaderItem(2, new QTableWidgetItem("END PERIOD"));

    for(int i = 3; i < 3 + maxDaysCounter; ++i)
        ui->tableWidget_DisciplinesInfo->setHorizontalHeaderItem(i, new QTableWidgetItem("DAY"));

    for(int i = 0; i < teacher.GetDisciplines().size(); ++i)
    {
        ui->tableWidget_DisciplinesInfo->setItem(i,0,new QTableWidgetItem(teacher.GetDisciplines()[i].GetName().replace("_"," ")));
        ui->tableWidget_DisciplinesInfo->setItem(i,1,new QTableWidgetItem(teacher.GetDisciplines()[i].GetStartDate()));
        ui->tableWidget_DisciplinesInfo->setItem(i,2,new QTableWidgetItem(teacher.GetDisciplines()[i].GetEndDate()));

        for(int j = 3, b = 0; j < 3 + teacher.GetDisciplines()[i].GetDaysInWeek().size(); ++j, ++b)
            ui->tableWidget_DisciplinesInfo->setItem(i,j,new QTableWidgetItem(teacher.GetDisciplines()[i].GetDaysInWeek()[b]));
    }
}

//Виводить інформацію про студентів викладача за вибраною дисципліною
void TeacherPage::on_pushButton_ShowStudents_clicked()
{
    ui->pushButton_SortStudentsByName->show();
    ui->pushButton_SortStudentsbyGroup->show();

    QString subject = ui->comboBox_Disciplines->currentText();
    teacher.FindMyStudentsInDiscipline(subject);
    ui->tableWidget_StudentsInfo->setRowCount(teacher.GetSizeOfIdOfPersons());
    teacher.PrintInfoAboutStudents(ui->tableWidget_StudentsInfo);
    ui->label_CountOfStudents->setText("You have " + QString::number(teacher.GetSizeOfIdOfPersons()) + " enrolled students");
}

//Виводить інформацію про всіх студентів викладача
void TeacherPage::on_pushButton_AllEnrolledStud_clicked()
{
    ui->pushButton_SortStudentsByName->show();
    ui->pushButton_SortStudentsbyGroup->show();

    ui->tableWidget_StudentsInfo->setColumnCount(2);
    ui->tableWidget_StudentsInfo->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_StudentsInfo->setHorizontalHeaderItem(1, new QTableWidgetItem("GROUP"));
    teacher.FindAllMyStudents();
    ui->tableWidget_StudentsInfo->setRowCount(teacher.GetSizeOfIdOfPersons());
    teacher.PrintInfoAboutStudents(ui->tableWidget_StudentsInfo);
    ui->label_CountOfStudents->setText("You have " + QString::number(teacher.GetSizeOfIdOfPersons()) + " enrolled students");
}

void TeacherPage::on_pushButton_SortStudentsByName_clicked()
{
   teacher.SortMyStudentsBySurname();
   teacher.PrintInfoAboutStudents(ui->tableWidget_StudentsInfo);
}

void TeacherPage::on_pushButton_SortStudentsbyGroup_clicked()
{
    teacher.SortMyStudentsByGroup();
    teacher.PrintInfoAboutStudents(ui->tableWidget_StudentsInfo);
}

//Відкриває головне вікно програми
void TeacherPage::on_commandLinkButton_BackLink_clicked()
{
    hide();
    MainWindow window;
    window.show();
}
