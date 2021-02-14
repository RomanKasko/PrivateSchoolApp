#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QDialog>
#include <QTableWidget>
#include "Teacher.h"
//Клас що відповідає за вікно студента
namespace Ui {
class StudentPage;
}

class StudentPage : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPage(QWidget *parent = nullptr);
    ~StudentPage();

public slots:
    void tableItemClicked(int row, int column);
    void PrintInfo(QTableWidget *tableTeacherInfo, QList<Teacher> list, int mode);
    void ShowTeachersListInfo(QString subject, QTableWidget *table);
    void ShowMyTeachersWithDisciplines();
    void ShowMyTeachers();
    void ShowMyDisciplines();

private slots:
    void on_pushButton_SortSurname_clicked();
    void on_pushButton_SortPosition_clicked();
    void on_pushButton_Teacher1Disc_clicked();
    void on_pushButton_FindTheMostPopularTeacher_clicked();
    void on_pushButton_ShowTeachers_clicked();
    void on_pushButton_ShowMyDisTeachers_clicked();
    void on_pushButton_ChooseTeacher_clicked();
    void on_pushButton_FindFreeTeachersByDate_clicked();
    void on_commandLinkButton_BackLink_clicked();
    void on_tableWidget_Info_customContextMenuRequested(const QPoint &pos);

private:
    Ui::StudentPage *ui;
};

#endif // STUDENTPAGE_H
