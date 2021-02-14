#include "registrationpage.h"
#include "ui_registrationpage.h"

Registrationpage::Registrationpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrationpage)
{
    ui->setupUi(this);
    QRegExp rx("[a-zA-Z]+");
    QValidator *validator = new QRegExpValidator(rx, this);
    ui->lineEdit_Surname->setValidator(validator);
    ui->lineEdit_Surname->setPlaceholderText("Your Surname");
    ui->lineEdit_GroupName->setPlaceholderText("Your Group Name");
    ui->lineEdit_Password->setPlaceholderText("Password");
    ui->lineEdit_Password2->setPlaceholderText("Confirm your Password");
    ui->lineEdit_GroupName->setValidator(validator);

}

Registrationpage::~Registrationpage()
{
    delete ui;
}

//Викликає ф-ю, що перевіряє дані.
//Зберігає дані введені у поля реєстрації
void Registrationpage::on_pushButton_Reg_clicked()
{
   CheckInput();

   Student person;
   person.surname = ui->lineEdit_Surname->text();

   QStringList parts = person.surname.toLower().split(' ', QString::SkipEmptyParts);
       for (int i = 0; i < parts.size(); ++i)
           parts[i].replace(0, 1, parts[i][0].toUpper());

   person.surname = parts.join(" ");
   person.SetYear(ui->comboBox_Course->currentText().toInt());
   person.SetGroup(ui->lineEdit_GroupName->text().toUpper() + "-" +
                   QString::number(person.GetYear()) + ui->comboBox_GroupNum->currentText());
   person.SetDisciplinesToStudent(person,person.GetYear());

   mt19937 engine;
   engine.seed(time(nullptr));
   person.SetPersonalId(QString::number(engine() %1000000 + 1));

   QPalette palette = ui->label_Info->palette();
   QString password;
   if(ui->lineEdit_Password->text() == ui->lineEdit_Password2->text())
   {
        password = ui->lineEdit_Password2->text();
        person.SetPassword(password);
   }
   else
   {
      palette.setColor(ui->label_Info->backgroundRole(), Qt::white);
      palette.setColor(ui->label_Info->foregroundRole(), Qt::red);
      ui->label_Info->setPalette(palette);
      ui->label_Info->setText("Your password inputs are not equel. Try again.");
      return;
   }

   try
   {
      CheckIfStudentAlreadyInList(person);
   }  catch (exception &ex)
   {
       QMessageBox::warning(this,"Registration",ex.what());
       return;
   }

   studentsList.push_back(person);

   palette.setColor(ui->label_Info->foregroundRole(), Qt::darkGreen);
   ui->label_Info->setPalette(palette);
   ui->label_Info->setText("You are successfully signed up!");
}

//Перевіряє введені у вікні дані
void Registrationpage::CheckInput()
{
    QPalette palette = ui->label_Info->palette();

    if(ui->lineEdit_Surname->text().isEmpty() ||
       ui->lineEdit_GroupName->text().isEmpty() ||
       ui->lineEdit_Password->text().isEmpty() ||
       ui->lineEdit_Password2->text().isEmpty())
    {
       palette.setColor(ui->label_Info->backgroundRole(), Qt::white);
       palette.setColor(ui->label_Info->foregroundRole(), Qt::red);
       ui->label_Info->setPalette(palette);
       ui->label_Info->setText("Some of registration lines are empty. Fill empty lines.");
       return;
    }

    QString str = ui->lineEdit_Password->text();
    if(str.size() < 5)
    {
        palette.setColor(ui->label_Info->foregroundRole(), Qt::red);
        ui->label_Info->setPalette(palette);
        ui->label_Info->setText("Your password should be at least 5 characters. Try again.");
        return;
    }
}


//Перевіряє чи зареєстрований студент є унікальним
void Registrationpage::CheckIfStudentAlreadyInList(Student regStudent)
{
    for(int i = 0; i < studentsList.size(); ++i)
        if(regStudent.surname == studentsList.at(i).surname && regStudent.GetGroup() == studentsList[i].GetGroup())
            throw runtime_error("This student is already registered");
}

//Відкриває вікно входу в систему
void Registrationpage::on_commandLinkButton_BackToLogin_clicked()
{
    hide();
    Loginpage page;
    CheckStudMode = true;
    page.setModal(true);
    page.exec();
}
