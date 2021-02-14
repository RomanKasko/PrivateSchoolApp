/********************************************************************************
** Form generated from reading UI file 'studentpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPAGE_H
#define UI_STUDENTPAGE_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StudentPage
{
public:
    QGridLayout *gridLayout;
    QFrame *line;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_Disciplines;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_MyDisciplines;
    QPushButton *pushButton_ShowMyDisTeachers;
    QPushButton *pushButton_ChooseTeacher;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton_FindFreeTeachersByDate;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_Surname;
    QFrame *line_3;
    QLabel *label_2;
    QComboBox *comboBox_Disciplines;
    QPushButton *pushButton_ShowTeachers;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton_SortSurname;
    QPushButton *pushButton_SortPosition;
    QVBoxLayout *verticalLayout_4;
    QCommandLinkButton *commandLinkButton_BackLink;
    QLabel *label_5;
    QPushButton *pushButton_Teacher1Disc;
    QPushButton *pushButton_FindTheMostPopularTeacher;
    QFrame *line_2;
    QTableWidget *tableWidget_Info;

    void setupUi(QDialog *StudentPage)
    {
        if (StudentPage->objectName().isEmpty())
            StudentPage->setObjectName(QString::fromUtf8("StudentPage"));
        StudentPage->resize(911, 716);
        StudentPage->setMaximumSize(QSize(911, 716));
        StudentPage->setStyleSheet(QString::fromUtf8("StudentPage{\n"
"background-color:rgb(247, 255, 247);\n"
"}"));
        gridLayout = new QGridLayout(StudentPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line = new QFrame(StudentPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 1, 1, 3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tableWidget_Disciplines = new QTableWidget(StudentPage);
        tableWidget_Disciplines->setObjectName(QString::fromUtf8("tableWidget_Disciplines"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_Disciplines->sizePolicy().hasHeightForWidth());
        tableWidget_Disciplines->setSizePolicy(sizePolicy);
        tableWidget_Disciplines->setMinimumSize(QSize(300, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(10);
        tableWidget_Disciplines->setFont(font);
        tableWidget_Disciplines->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        tableWidget_Disciplines->setFrameShape(QFrame::StyledPanel);
        tableWidget_Disciplines->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_Disciplines->setGridStyle(Qt::DashDotLine);
        tableWidget_Disciplines->horizontalHeader()->setDefaultSectionSize(150);

        verticalLayout_5->addWidget(tableWidget_Disciplines);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(StudentPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(12);
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        comboBox_MyDisciplines = new QComboBox(StudentPage);
        comboBox_MyDisciplines->setObjectName(QString::fromUtf8("comboBox_MyDisciplines"));
        sizePolicy.setHeightForWidth(comboBox_MyDisciplines->sizePolicy().hasHeightForWidth());
        comboBox_MyDisciplines->setSizePolicy(sizePolicy);
        comboBox_MyDisciplines->setMinimumSize(QSize(300, 30));
        comboBox_MyDisciplines->setFont(font1);
        comboBox_MyDisciplines->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_2->addWidget(comboBox_MyDisciplines);

        pushButton_ShowMyDisTeachers = new QPushButton(StudentPage);
        pushButton_ShowMyDisTeachers->setObjectName(QString::fromUtf8("pushButton_ShowMyDisTeachers"));
        sizePolicy.setHeightForWidth(pushButton_ShowMyDisTeachers->sizePolicy().hasHeightForWidth());
        pushButton_ShowMyDisTeachers->setSizePolicy(sizePolicy);
        pushButton_ShowMyDisTeachers->setMinimumSize(QSize(300, 30));
        pushButton_ShowMyDisTeachers->setFont(font1);
        pushButton_ShowMyDisTeachers->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout_2->addWidget(pushButton_ShowMyDisTeachers);

        pushButton_ChooseTeacher = new QPushButton(StudentPage);
        pushButton_ChooseTeacher->setObjectName(QString::fromUtf8("pushButton_ChooseTeacher"));
        sizePolicy.setHeightForWidth(pushButton_ChooseTeacher->sizePolicy().hasHeightForWidth());
        pushButton_ChooseTeacher->setSizePolicy(sizePolicy);
        pushButton_ChooseTeacher->setMinimumSize(QSize(300, 30));
        pushButton_ChooseTeacher->setFont(font1);
        pushButton_ChooseTeacher->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout_2->addWidget(pushButton_ChooseTeacher);


        verticalLayout_5->addLayout(verticalLayout_2);

        groupBox = new QGroupBox(StudentPage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(300, 200));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        calendarWidget = new QCalendarWidget(groupBox);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        sizePolicy.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy);
        calendarWidget->setMinimumSize(QSize(270, 0));
        calendarWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        calendarWidget->setMinimumDate(QDate(2018, 1, 1));
        calendarWidget->setMaximumDate(QDate(2050, 12, 30));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(false);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(false);
        calendarWidget->setDateEditAcceptDelay(0);

        verticalLayout_6->addWidget(calendarWidget);

        pushButton_FindFreeTeachersByDate = new QPushButton(groupBox);
        pushButton_FindFreeTeachersByDate->setObjectName(QString::fromUtf8("pushButton_FindFreeTeachersByDate"));
        sizePolicy.setHeightForWidth(pushButton_FindFreeTeachersByDate->sizePolicy().hasHeightForWidth());
        pushButton_FindFreeTeachersByDate->setSizePolicy(sizePolicy);
        pushButton_FindFreeTeachersByDate->setMinimumSize(QSize(270, 30));
        pushButton_FindFreeTeachersByDate->setFont(font1);
        pushButton_FindFreeTeachersByDate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));
        pushButton_FindFreeTeachersByDate->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        verticalLayout_6->addWidget(pushButton_FindFreeTeachersByDate);


        verticalLayout_5->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 328, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_5, 3, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_Surname = new QLabel(StudentPage);
        label_Surname->setObjectName(QString::fromUtf8("label_Surname"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Surname->sizePolicy().hasHeightForWidth());
        label_Surname->setSizePolicy(sizePolicy1);
        label_Surname->setMinimumSize(QSize(0, 32));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto"));
        font2.setPointSize(16);
        label_Surname->setFont(font2);

        verticalLayout->addWidget(label_Surname);

        line_3 = new QFrame(StudentPage);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        label_2 = new QLabel(StudentPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        comboBox_Disciplines = new QComboBox(StudentPage);
        comboBox_Disciplines->setObjectName(QString::fromUtf8("comboBox_Disciplines"));
        sizePolicy1.setHeightForWidth(comboBox_Disciplines->sizePolicy().hasHeightForWidth());
        comboBox_Disciplines->setSizePolicy(sizePolicy1);
        comboBox_Disciplines->setMinimumSize(QSize(0, 30));
        comboBox_Disciplines->setFont(font1);
        comboBox_Disciplines->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(comboBox_Disciplines);

        pushButton_ShowTeachers = new QPushButton(StudentPage);
        pushButton_ShowTeachers->setObjectName(QString::fromUtf8("pushButton_ShowTeachers"));
        pushButton_ShowTeachers->setMinimumSize(QSize(0, 30));
        pushButton_ShowTeachers->setFont(font1);
        pushButton_ShowTeachers->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout->addWidget(pushButton_ShowTeachers);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(StudentPage);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 40));
        label->setFont(font1);

        verticalLayout_3->addWidget(label);

        label_4 = new QLabel(StudentPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font3;
        font3.setPointSize(12);
        label_4->setFont(font3);

        verticalLayout_3->addWidget(label_4);

        pushButton_SortSurname = new QPushButton(StudentPage);
        pushButton_SortSurname->setObjectName(QString::fromUtf8("pushButton_SortSurname"));
        sizePolicy1.setHeightForWidth(pushButton_SortSurname->sizePolicy().hasHeightForWidth());
        pushButton_SortSurname->setSizePolicy(sizePolicy1);
        pushButton_SortSurname->setMinimumSize(QSize(0, 30));
        pushButton_SortSurname->setFont(font1);
        pushButton_SortSurname->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout_3->addWidget(pushButton_SortSurname);

        pushButton_SortPosition = new QPushButton(StudentPage);
        pushButton_SortPosition->setObjectName(QString::fromUtf8("pushButton_SortPosition"));
        pushButton_SortPosition->setMinimumSize(QSize(0, 30));
        pushButton_SortPosition->setFont(font1);
        pushButton_SortPosition->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout_3->addWidget(pushButton_SortPosition);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        commandLinkButton_BackLink = new QCommandLinkButton(StudentPage);
        commandLinkButton_BackLink->setObjectName(QString::fromUtf8("commandLinkButton_BackLink"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(commandLinkButton_BackLink->sizePolicy().hasHeightForWidth());
        commandLinkButton_BackLink->setSizePolicy(sizePolicy2);
        commandLinkButton_BackLink->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Roboto"));
        font4.setPointSize(11);
        font4.setUnderline(true);
        commandLinkButton_BackLink->setFont(font4);

        verticalLayout_4->addWidget(commandLinkButton_BackLink);

        label_5 = new QLabel(StudentPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        pushButton_Teacher1Disc = new QPushButton(StudentPage);
        pushButton_Teacher1Disc->setObjectName(QString::fromUtf8("pushButton_Teacher1Disc"));
        sizePolicy1.setHeightForWidth(pushButton_Teacher1Disc->sizePolicy().hasHeightForWidth());
        pushButton_Teacher1Disc->setSizePolicy(sizePolicy1);
        pushButton_Teacher1Disc->setMinimumSize(QSize(0, 30));
        pushButton_Teacher1Disc->setFont(font1);
        pushButton_Teacher1Disc->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout_4->addWidget(pushButton_Teacher1Disc);

        pushButton_FindTheMostPopularTeacher = new QPushButton(StudentPage);
        pushButton_FindTheMostPopularTeacher->setObjectName(QString::fromUtf8("pushButton_FindTheMostPopularTeacher"));
        pushButton_FindTheMostPopularTeacher->setMinimumSize(QSize(0, 30));
        pushButton_FindTheMostPopularTeacher->setFont(font1);
        pushButton_FindTheMostPopularTeacher->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));

        verticalLayout_4->addWidget(pushButton_FindTheMostPopularTeacher);


        horizontalLayout->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 3);

        line_2 = new QFrame(StudentPage);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 2, 1, 1);

        tableWidget_Info = new QTableWidget(StudentPage);
        tableWidget_Info->setObjectName(QString::fromUtf8("tableWidget_Info"));
        tableWidget_Info->setMinimumSize(QSize(550, 0));
        tableWidget_Info->setFont(font);
        tableWidget_Info->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget_Info->setAcceptDrops(false);
        tableWidget_Info->setLayoutDirection(Qt::LeftToRight);
        tableWidget_Info->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        tableWidget_Info->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        tableWidget_Info->setTextElideMode(Qt::ElideMiddle);
        tableWidget_Info->setGridStyle(Qt::DashLine);
        tableWidget_Info->horizontalHeader()->setDefaultSectionSize(170);

        gridLayout->addWidget(tableWidget_Info, 3, 3, 1, 1);


        retranslateUi(StudentPage);

        QMetaObject::connectSlotsByName(StudentPage);
    } // setupUi

    void retranslateUi(QDialog *StudentPage)
    {
        StudentPage->setWindowTitle(QCoreApplication::translate("StudentPage", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        tableWidget_Disciplines->setToolTip(QCoreApplication::translate("StudentPage", "Shows information about your disciplines and teachers", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("StudentPage", "My disciplines:", nullptr));
#if QT_CONFIG(tooltip)
        comboBox_MyDisciplines->setToolTip(QCoreApplication::translate("StudentPage", "Your disciplines", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton_ShowMyDisTeachers->setToolTip(QCoreApplication::translate("StudentPage", "Shows all teachers who has chosen discipline", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_ShowMyDisTeachers->setText(QCoreApplication::translate("StudentPage", "Show My disc Teachers List", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_ChooseTeacher->setToolTip(QCoreApplication::translate("StudentPage", "Saves your chosen discipline teacher", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_ChooseTeacher->setText(QCoreApplication::translate("StudentPage", "Choose teacher on this discipline", nullptr));
        groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        pushButton_FindFreeTeachersByDate->setToolTip(QCoreApplication::translate("StudentPage", "Finds all free teachers by chosen date", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_FindFreeTeachersByDate->setText(QCoreApplication::translate("StudentPage", "Find free teachers", nullptr));
        label_Surname->setText(QString());
        label_2->setText(QCoreApplication::translate("StudentPage", "All available disciplines:", nullptr));
#if QT_CONFIG(tooltip)
        comboBox_Disciplines->setToolTip(QCoreApplication::translate("StudentPage", "All disciplines", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButton_ShowTeachers->setToolTip(QCoreApplication::translate("StudentPage", "Shows all teachers who has chosen discipline", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_ShowTeachers->setText(QCoreApplication::translate("StudentPage", "Show Teachers List", nullptr));
        label->setText(QCoreApplication::translate("StudentPage", "                 Sort Teachers by:", nullptr));
        label_4->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_SortSurname->setToolTip(QCoreApplication::translate("StudentPage", "Sorts all teachers by surname", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SortSurname->setText(QCoreApplication::translate("StudentPage", "Surname", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_SortPosition->setToolTip(QCoreApplication::translate("StudentPage", "Sorts all teachers by their position", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SortPosition->setText(QCoreApplication::translate("StudentPage", "Position", nullptr));
#if QT_CONFIG(tooltip)
        commandLinkButton_BackLink->setToolTip(QCoreApplication::translate("StudentPage", "Return to title window", nullptr));
#endif // QT_CONFIG(tooltip)
        commandLinkButton_BackLink->setText(QCoreApplication::translate("StudentPage", "Back To Title Window", nullptr));
        label_5->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Teacher1Disc->setToolTip(QCoreApplication::translate("StudentPage", "Finds  all teachers that have one discipline", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Teacher1Disc->setText(QCoreApplication::translate("StudentPage", "One discipline teachers", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_FindTheMostPopularTeacher->setToolTip(QCoreApplication::translate("StudentPage", "Finds teacher with the most students in chosen discipline", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_FindTheMostPopularTeacher->setText(QCoreApplication::translate("StudentPage", "Most popular ", nullptr));
#if QT_CONFIG(tooltip)
        tableWidget_Info->setToolTip(QCoreApplication::translate("StudentPage", "Shows information about teachers", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class StudentPage: public Ui_StudentPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPAGE_H
