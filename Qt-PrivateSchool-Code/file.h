#ifndef FILE_H
#define FILE_H
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
//Клас, який працює із файлами.
class File
{
public:
    File();

    QString path;

    void OpenFileWithChoise(QMainWindow *window);

    void ReadAndCheckFilesInfo(QMainWindow *window);
    void ReadFromFileDisciplines(QString path);
    void ReadFromFileTeachers(QString path);
    void ReadFromFileStudents(QString path);

    void WriteToFileDisciplines(QString path, QMainWindow *window);
    void WriteToFileNewDiscipline(QString path, QMainWindow *window);
    void WriteToFileTeachers(QString path, QMainWindow *window);
    void WriteToFileStudents(QString path, QMainWindow *window);

    void CheckIfOpenFile(QFile &file, QString name);
    void CheckIfEmptyFile(QFile &file, QString name);
    void CheckReadFileLinesIfEmpty(QFile &file, QString name);
    void CheckStudentReadFileFormat(QString path);
    void CheckTeacherReadFileFormat(QString path);
    void CheckDisciplineReadFileFormat(QString path);
};

#endif // FILE_H
