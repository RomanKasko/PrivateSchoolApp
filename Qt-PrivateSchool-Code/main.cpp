#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
    w.setWindowTitle("IT Private School");
    w.setWindowIcon(QIcon("Icons\\school.png"));
    w.show();
    return a.exec();
}
