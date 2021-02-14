#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_OkSize_clicked()
{
    int size = ui->lineEdit_Size->text().toInt();
    ui->tableWidget_Info->setRowCount(size);
    ui->tableWidget_Info->setColumnCount(3);

    ui->tableWidget_Info->setHorizontalHeaderItem(0, new QTableWidgetItem("SURNAME"));
    ui->tableWidget_Info->setHorizontalHeaderItem(1, new QTableWidgetItem("EXPERIENCE"));
    ui->tableWidget_Info->setHorizontalHeaderItem(2, new QTableWidgetItem("DISCIPLINE"));

}

void Admin::on_pushButton_Add_clicked()
{
    ui->tableWidget_Info->setRowCount(ui->tableWidget_Info->rowCount()+1);
}

void Admin::on_pushButton_Delete_clicked()
{
    ui->tableWidget_Info->setRowCount(ui->tableWidget_Info->rowCount()-1);
}

