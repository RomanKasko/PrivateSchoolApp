#ifndef TEACHERPAGE_H
#define TEACHERPAGE_H
#include <QDialog>
//Клас що відповідає за вікно вчителя
namespace Ui {
class TeacherPage;
}

class TeacherPage : public QDialog
{
    Q_OBJECT

public:
    explicit TeacherPage(QWidget *parent = nullptr);
    void PrintTeacherDisciplinesInfo();
    ~TeacherPage();

private slots:
    void on_pushButton_ShowStudents_clicked();
    void on_pushButton_AllEnrolledStud_clicked();
    void on_pushButton_SortStudentsByName_clicked();
    void on_pushButton_SortStudentsbyGroup_clicked();
    void on_commandLinkButton_BackLink_clicked();

private:
    Ui::TeacherPage *ui;
};
#endif // TEACHERPAGE_H
