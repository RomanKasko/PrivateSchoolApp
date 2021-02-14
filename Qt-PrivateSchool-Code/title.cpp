#include "title.h"
#include "ui_title.h"
#include "registrationpage.h"
#include "loginpage.h"

Title::Title(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Title)
{
    ui->setupUi(this);
}

Title::~Title()
{
    delete ui;
}


void Title::on_pushButton_Student_clicked()
{
   hide();
   Loginpage window;
   window.setModal(true);
   window.exec();
}

void Title::on_pushButton_Teacher_clicked()
{
    hide();
    Loginpage window;
    window.setModal(true);
    window.exec();
}

void Title::on_pushButton_Registration_clicked()
{
    hide();
    Registrationpage window;
    window.setModal(true);
    window.exec();
}

void Title::on_pushButton_Admin_clicked()
{
    hide();
    Loginpage window;
    window.setModal(true);
    window.exec();
}


