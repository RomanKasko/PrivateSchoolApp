#include "adminpage.h"
#include "ui_adminpage.h"

Adminpage::Adminpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminpage)
{
    ui->setupUi(this);
}

Adminpage::~Adminpage()
{
    delete ui;
}
