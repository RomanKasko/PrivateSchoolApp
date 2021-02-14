 #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <QDebug>
#include <QAction>
#include <QMenu>
#include <QComboBox>
#include <QTableWidget>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
//Клас який відповідає за вигляд титульної сторінки і вікна адміністратора
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void tableItemClicked(int row, int column);
    void HideNewDisciplineWindowElements();
    void HideElementsForTitleWindow();

    void CheckReadFromTableInfo();
    void CheckReadFromTableLineInfo(int index);

    void SetNewTeacherInfo(int index);
    void ShowDisciplines(QComboBox *disciplinesBox);
    void ShowNewDisciplineWindowElements();
    void ShowColumnsHeaderName();

private slots:
    void on_pushButton_Admin_clicked();
    void on_pushButton_Registration_clicked();
    void on_pushButton_Teacher_clicked();
    void on_pushButton_Student_clicked();
    void on_pushButton_OkSize_clicked();
    void on_actionOpen_triggered();
    void on_pushButton_Set_clicked();
    void on_pushButton_AddDiscipline_clicked();
    void on_actionAddTeacher_triggered();
    void on_actionDeleteTeacher_triggered();
    void on_actionCreateDiscipline_triggered();
    void on_pushButton_SetDiscipline_clicked();
    void on_actionBackToTitle_triggered();
    void on_commandLinkButton_Close_clicked();
    void on_pushButton_SetNewTeacherInfo_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
