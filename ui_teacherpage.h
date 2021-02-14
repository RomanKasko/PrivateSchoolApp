/********************************************************************************
** Form generated from reading UI file 'teacherpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERPAGE_H
#define UI_TEACHERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherPage
{
public:
    QGridLayout *gridLayout;
    QCommandLinkButton *commandLinkButton_BackLink;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_3;
    QPushButton *pushButton_SortStudentsbyGroup;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_Surname;
    QPushButton *pushButton_AllEnrolledStud;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_SortStudentsByName;
    QPushButton *pushButton_ShowStudents;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comboBox_Disciplines;
    QLabel *label_CountOfStudents;
    QSpacerItem *horizontalSpacer_10;
    QTableWidget *tableWidget_DisciplinesInfo;
    QTableWidget *tableWidget_StudentsInfo;

    void setupUi(QDialog *TeacherPage)
    {
        if (TeacherPage->objectName().isEmpty())
            TeacherPage->setObjectName(QString::fromUtf8("TeacherPage"));
        TeacherPage->resize(896, 549);
        TeacherPage->setStyleSheet(QString::fromUtf8("QTeacherPage{\n"
"background-color:rgb(247, 255, 247);\n"
"}"));
        gridLayout = new QGridLayout(TeacherPage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        commandLinkButton_BackLink = new QCommandLinkButton(TeacherPage);
        commandLinkButton_BackLink->setObjectName(QString::fromUtf8("commandLinkButton_BackLink"));
        QFont font;
        font.setUnderline(true);
        commandLinkButton_BackLink->setFont(font);

        gridLayout->addWidget(commandLinkButton_BackLink, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 15, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 8, 0, 1, 1);

        line_3 = new QFrame(TeacherPage);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_3, 1, 0, 1, 4);

        pushButton_SortStudentsbyGroup = new QPushButton(TeacherPage);
        pushButton_SortStudentsbyGroup->setObjectName(QString::fromUtf8("pushButton_SortStudentsbyGroup"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_SortStudentsbyGroup->sizePolicy().hasHeightForWidth());
        pushButton_SortStudentsbyGroup->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(14);
        pushButton_SortStudentsbyGroup->setFont(font1);
        pushButton_SortStudentsbyGroup->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));
        pushButton_SortStudentsbyGroup->setAutoDefault(false);

        gridLayout_2->addWidget(pushButton_SortStudentsbyGroup, 13, 3, 3, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 10, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 6, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_9, 6, 3, 1, 1);

        label_Surname = new QLabel(TeacherPage);
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

        gridLayout_2->addWidget(label_Surname, 0, 0, 1, 4);

        pushButton_AllEnrolledStud = new QPushButton(TeacherPage);
        pushButton_AllEnrolledStud->setObjectName(QString::fromUtf8("pushButton_AllEnrolledStud"));
        sizePolicy.setHeightForWidth(pushButton_AllEnrolledStud->sizePolicy().hasHeightForWidth());
        pushButton_AllEnrolledStud->setSizePolicy(sizePolicy);
        pushButton_AllEnrolledStud->setFont(font1);
        pushButton_AllEnrolledStud->setMouseTracking(false);
        pushButton_AllEnrolledStud->setTabletTracking(true);
        pushButton_AllEnrolledStud->setAcceptDrops(false);
        pushButton_AllEnrolledStud->setAutoFillBackground(false);
        pushButton_AllEnrolledStud->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));
        pushButton_AllEnrolledStud->setCheckable(false);
        pushButton_AllEnrolledStud->setChecked(false);
        pushButton_AllEnrolledStud->setAutoExclusive(false);
        pushButton_AllEnrolledStud->setAutoDefault(false);
        pushButton_AllEnrolledStud->setFlat(false);

        gridLayout_2->addWidget(pushButton_AllEnrolledStud, 8, 1, 3, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 10, 0, 1, 1);

        pushButton_SortStudentsByName = new QPushButton(TeacherPage);
        pushButton_SortStudentsByName->setObjectName(QString::fromUtf8("pushButton_SortStudentsByName"));
        sizePolicy.setHeightForWidth(pushButton_SortStudentsByName->sizePolicy().hasHeightForWidth());
        pushButton_SortStudentsByName->setSizePolicy(sizePolicy);
        pushButton_SortStudentsByName->setFont(font1);
        pushButton_SortStudentsByName->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));
        pushButton_SortStudentsByName->setAutoDefault(false);

        gridLayout_2->addWidget(pushButton_SortStudentsByName, 13, 0, 3, 1);

        pushButton_ShowStudents = new QPushButton(TeacherPage);
        pushButton_ShowStudents->setObjectName(QString::fromUtf8("pushButton_ShowStudents"));
        sizePolicy.setHeightForWidth(pushButton_ShowStudents->sizePolicy().hasHeightForWidth());
        pushButton_ShowStudents->setSizePolicy(sizePolicy);
        pushButton_ShowStudents->setFont(font1);
        pushButton_ShowStudents->setAutoFillBackground(false);
        pushButton_ShowStudents->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));
        pushButton_ShowStudents->setCheckable(false);
        pushButton_ShowStudents->setAutoRepeat(false);
        pushButton_ShowStudents->setAutoDefault(false);
        pushButton_ShowStudents->setFlat(false);

        gridLayout_2->addWidget(pushButton_ShowStudents, 3, 1, 2, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 13, 1, 1, 1);

        comboBox_Disciplines = new QComboBox(TeacherPage);
        comboBox_Disciplines->setObjectName(QString::fromUtf8("comboBox_Disciplines"));
        sizePolicy.setHeightForWidth(comboBox_Disciplines->sizePolicy().hasHeightForWidth());
        comboBox_Disciplines->setSizePolicy(sizePolicy);
        comboBox_Disciplines->setFont(font1);

        gridLayout_2->addWidget(comboBox_Disciplines, 6, 1, 1, 1);

        label_CountOfStudents = new QLabel(TeacherPage);
        label_CountOfStudents->setObjectName(QString::fromUtf8("label_CountOfStudents"));
        label_CountOfStudents->setFont(font1);

        gridLayout_2->addWidget(label_CountOfStudents, 2, 0, 1, 4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 7, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        tableWidget_DisciplinesInfo = new QTableWidget(TeacherPage);
        tableWidget_DisciplinesInfo->setObjectName(QString::fromUtf8("tableWidget_DisciplinesInfo"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Roboto"));
        font3.setPointSize(10);
        tableWidget_DisciplinesInfo->setFont(font3);

        gridLayout->addWidget(tableWidget_DisciplinesInfo, 2, 0, 1, 1);

        tableWidget_StudentsInfo = new QTableWidget(TeacherPage);
        tableWidget_StudentsInfo->setObjectName(QString::fromUtf8("tableWidget_StudentsInfo"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget_StudentsInfo->sizePolicy().hasHeightForWidth());
        tableWidget_StudentsInfo->setSizePolicy(sizePolicy2);
        tableWidget_StudentsInfo->setMinimumSize(QSize(281, 0));
        tableWidget_StudentsInfo->setFont(font3);
        tableWidget_StudentsInfo->setFrameShadow(QFrame::Plain);
        tableWidget_StudentsInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_StudentsInfo->setTextElideMode(Qt::ElideRight);
        tableWidget_StudentsInfo->setShowGrid(true);
        tableWidget_StudentsInfo->setGridStyle(Qt::DashLine);
        tableWidget_StudentsInfo->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_StudentsInfo->horizontalHeader()->setMinimumSectionSize(40);
        tableWidget_StudentsInfo->horizontalHeader()->setDefaultSectionSize(120);

        gridLayout->addWidget(tableWidget_StudentsInfo, 0, 1, 3, 1);


        retranslateUi(TeacherPage);

        pushButton_AllEnrolledStud->setDefault(false);
        pushButton_ShowStudents->setDefault(false);


        QMetaObject::connectSlotsByName(TeacherPage);
    } // setupUi

    void retranslateUi(QDialog *TeacherPage)
    {
        TeacherPage->setWindowTitle(QCoreApplication::translate("TeacherPage", "Dialog", nullptr));
#if QT_CONFIG(tooltip)
        commandLinkButton_BackLink->setToolTip(QCoreApplication::translate("TeacherPage", "Return to title window", nullptr));
#endif // QT_CONFIG(tooltip)
        commandLinkButton_BackLink->setText(QCoreApplication::translate("TeacherPage", "Back to title", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_SortStudentsbyGroup->setToolTip(QCoreApplication::translate("TeacherPage", "Sorts your students by group name", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SortStudentsbyGroup->setText(QCoreApplication::translate("TeacherPage", "Sort by group", nullptr));
        label_Surname->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_AllEnrolledStud->setToolTip(QCoreApplication::translate("TeacherPage", "Shows all your students", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_AllEnrolledStud->setText(QCoreApplication::translate("TeacherPage", "   Students List        ", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_SortStudentsByName->setToolTip(QCoreApplication::translate("TeacherPage", "Sorts your students by surname", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_SortStudentsByName->setText(QCoreApplication::translate("TeacherPage", "Sort by surname", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_ShowStudents->setToolTip(QCoreApplication::translate("TeacherPage", "Shows students of your chosen discipline", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_ShowStudents->setText(QCoreApplication::translate("TeacherPage", "   Discipline Students", nullptr));
        label_CountOfStudents->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TeacherPage: public Ui_TeacherPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERPAGE_H
