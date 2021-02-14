#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
//Клас, який відповідає за вікно входу в систему
namespace Ui {
class Loginpage;
}

class Loginpage : public QDialog
{
    Q_OBJECT

public:
    explicit Loginpage(QWidget *parent = nullptr);
    void CheckLoginInput();
    void CheckLoginAdmin(QString surname, QString password);
    void CheckLoginTeacher(QString surname, QString password);
    void CheckLoginStudent(QString surname, QString password);

    void SetTeacherInfo(QString surname, QString password, int index);
    void SetStudentInfo(QString surname, QString password, int index);
    void SetWrongLoginMessage(QString whatsWrongString);

    void ShowStudentWindow();
    void ShowTeacherWindow();
    void ShowAdminWindow();

    ~Loginpage();

private slots:
    void on_pushButton_Login_clicked();
    void on_commandLinkButton_clicked();
    void on_commandLinkButton_BackToTitle_clicked();

private:
    Ui::Loginpage *ui;
};
//Глобальні змінні, які відповідають за те, який користувач зайшов в систему(Адмін, Вчитель, Учень).
extern bool CheckAdmMode,CheckStudMode,CheckTeachMode;
#endif // LOGINPAGE_H
