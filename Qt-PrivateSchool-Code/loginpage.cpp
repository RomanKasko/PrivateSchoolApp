#include "loginpage.h"
#include "ui_loginpage.h"

#include "mainwindow.h"
#include "registrationpage.h"
#include "studentpage.h"
#include "teacherpage.h"

#include "student.h"
#include "Teacher.h"
Student student;
Teacher teacher;

Loginpage::Loginpage(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Loginpage)
{
    ui->setupUi(this);

    if(!CheckStudMode)
    {
        ui->commandLinkButton->hide();
        ui->label_ToRegistration->hide();
    }

    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_login->setValidator(validator);
    ui->label_Info->hide();

    Qt::WindowFlags flags = windowFlags();
    Qt::WindowFlags closeFlag = Qt::WindowCloseButtonHint;
    flags = flags & (~closeFlag);
    setWindowFlags(flags);
}

Loginpage::~Loginpage()
{
    if(CheckStudMode)
        CheckStudMode = !CheckStudMode;
    delete ui;
}

//після натискання цієї кнопки зчитує інформацію про прізвище та пароль,
//і викликає функцію, що перевіряє їх формат
//та функції, які шукають відповідного користувача серед адміна та списків учнів і вчителів
void Loginpage::on_pushButton_Login_clicked()
{
    CheckLoginInput();

    QString login = ui->lineEdit_login->text();
    QString password = ui->lineEdit_password->text();

    CheckLoginAdmin(login,password);
    CheckLoginStudent(login,password);
    CheckLoginTeacher(login,password);
}

//Перевіряє ввід прізвища та пароля
void Loginpage::CheckLoginInput()
{
    QPalette palette = ui->label_Info->palette();

    if(ui->lineEdit_login->text().isEmpty())
    {
       palette.setColor(ui->label_Info->backgroundRole(), Qt::white);
       palette.setColor(ui->label_Info->foregroundRole(), Qt::red);
       ui->label_Info->show();
       ui->label_Info->setPalette(palette);
       ui->label_Info->setText("Surname area is empty. Please write your surname.");
       return;
    }
    else if(ui->lineEdit_password->text().isEmpty())
    {
       palette.setColor(ui->label_Info->backgroundRole(), Qt::white);
       palette.setColor(ui->label_Info->foregroundRole(), Qt::red);
       ui->label_Info->setPalette(palette);
       ui->label_Info->show();
       ui->label_Info->setText("Password area is empty. Please enter your password.");
       return;
    }
}

//Перевіряє чи користувач є адміном
void Loginpage::CheckLoginAdmin(QString surname, QString password)
{
    if(!CheckAdmMode) return;

    if(surname.toLower() == "admin" && password == "admin")
        ShowAdminWindow();
    else if(surname.toLower() != "admin")
        SetWrongLoginMessage("login");
    else if(password != "admin")
        SetWrongLoginMessage("password");
}

//Перевіряє чи користувач є вчителем
void Loginpage::CheckLoginTeacher(QString surname, QString password)
{
   if(!CheckTeachMode) return;

   bool check = false;
   for(int i = 0; i < teachersList.size(); ++i)
   {
       if(surname.toLower() == teachersList[i].surname.toLower() && password == teachersList[i].GetPassword())
       {
           check = true;
           SetTeacherInfo(surname,password,i);
           ShowTeacherWindow();
       }
   }
   if(!check) SetWrongLoginMessage("surname or password");
}

//Перевіряє чи користувач є учнем
void Loginpage::CheckLoginStudent(QString surname, QString password)
{
    if(!CheckStudMode) return;

    bool check = false;
    for(int i = 0; i < studentsList.size(); ++i)
    {
        if(surname.toLower() == studentsList[i].surname.toLower() && password == studentsList[i].GetPassword())
        {
            check = true;
            SetStudentInfo(surname,password,i);
            ShowStudentWindow();
        }
    }
    if(!check) SetWrongLoginMessage("surname or password");
}

//Виводить помилку входу із переданою стрічкою
void Loginpage::SetWrongLoginMessage(QString whatsWrongString)
{
    QPalette palette = ui->label_Info->palette();
    palette.setColor(ui->label_Info->backgroundRole(), Qt::white);
    palette.setColor(ui->label_Info->foregroundRole(), Qt::red);
    ui->label_Info->setPalette(palette);
    ui->label_Info->show();
    ui->label_Info->setText("Your " + whatsWrongString +" is wrong. Try again");
}

//Відкриває вікно студента
void Loginpage::ShowStudentWindow()
{
    this->hide();
    StudentPage page;
    page.setWindowTitle("Student`s cabinet");
    page.setWindowIcon(QIcon("Icons\\student.png"));
    page.setModal(true);
    page.exec();
}

//Відкриває вікно викладача
void Loginpage::ShowTeacherWindow()
{
    this->hide();
    TeacherPage page;
    page.setWindowTitle("Teacher`s cabinet");
    page.setWindowIcon(QIcon("Icons\\teacher.png"));
    page.setModal(true);
    page.exec();
}

//Відкриває вікно адміна
void Loginpage::ShowAdminWindow()
{
    this->hide();
    MainWindow window;
    window.show();
}

//Записує всю інформацію про користувача-викладача
void Loginpage::SetTeacherInfo(QString surname, QString password, int index)
{
    teacher.surname = surname;
    teacher.SetPassword(password);
    teacher.SetPosition(teachersList[index].GetPosition());
    teacher.SetExperience(teachersList[index].GetExperience());
    teacher.DeleteDisciplines();
    for(int j = 0; j < teachersList[index].GetDisciplines().size(); ++j)
        teacher.SetDiscipline(teachersList[index].GetDisciplines()[j]);

    teacher.SetPersonalId(teachersList[index].GetPersonalId());
}

//Записує всю інформацію про користувача-студента
void Loginpage::SetStudentInfo(QString surname, QString password, int index)
{
    QVector<QString> studTmpVect;
    student.surname = surname;
    student.SetPassword(password);
    student.SetGroup(studentsList[index].GetGroup());
    student.SetYear(studentsList[index].GetYear());
    student.GetLessons().clear();
    for(int j = 0; j < studentsList[index].GetLessons().size(); ++j)
        studTmpVect.push_back(studentsList[index].GetLessons()[j]);;

    student.SetLessons(studTmpVect);
    studTmpVect.clear();
    student.SetPersonalId(studentsList[index].GetPersonalId());
    for(int j = 0; j < studentsList[index].GetSizeOfIdOfPersons(); ++j)
         studTmpVect.push_back(studentsList[index].GetIdOfPersonsByIndex(j));

    student.SetIdOfPersons(studTmpVect);
}

//Відкиває вікно реєстраціїї
void Loginpage::on_commandLinkButton_clicked()
{
    hide();
    Registrationpage window;
    window.setWindowTitle("Registration");
    window.setWindowIcon(QIcon("Icons\\registration.png"));
    window.setModal(true);
    window.exec();
}

//Відкиває головне вікно програми
void Loginpage::on_commandLinkButton_BackToTitle_clicked()
{
    hide();
    MainWindow window;
    CheckAdmMode = false;
    window.show();
}
