#ifndef REGISTRATIONPAGE_H
#define REGISTRATIONPAGE_H

#include <QDialog>
#include "student.h"
#include "discipline.h"
#include "loginpage.h"
#include <random>
#include <ctime>
//Клас, що відповідає за вікно реєстрації
namespace Ui {
class Registrationpage;
}

class Registrationpage : public QDialog
{
    Q_OBJECT
public:
    explicit Registrationpage(QWidget *parent = nullptr);
    void CheckIfStudentAlreadyInList(Student regStudent);
    void CheckInput();
    ~Registrationpage();

private slots:
    void on_pushButton_Reg_clicked();
    void on_commandLinkButton_BackToLogin_clicked();

private:
    Ui::Registrationpage *ui;
};

#endif // REGISTRATIONPAGE_H
