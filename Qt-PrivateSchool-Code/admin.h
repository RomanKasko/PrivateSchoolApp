#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_pushButton_Delete_clicked();

    void on_pushButton_OkSize_clicked();

    void on_pushButton_Add_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
