#ifndef TITLE_H
#define TITLE_H

#include <QDialog>

namespace Ui {
class Title;
}

class Title : public QDialog
{
    Q_OBJECT

public:
    explicit Title(QWidget *parent = nullptr);
    ~Title();

private slots:
    void on_pushButton_Student_clicked();

    void on_pushButton_Teacher_clicked();

    void on_pushButton_Registration_clicked();

    void on_pushButton_Admin_clicked();

private:
    Ui::Title *ui;
};

#endif // TITLE_H
