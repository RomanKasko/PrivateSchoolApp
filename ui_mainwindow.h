/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionAddTeacher;
    QAction *actionDeleteTeacher;
    QAction *actionCreateDiscipline;
    QAction *actionBackToTitle;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_DisciplineName;
    QLabel *label_DisCourse;
    QComboBox *comboBox_DisCourse;
    QLabel *label_Days;
    QCheckBox *checkBox_Mon;
    QLabel *label_DisName;
    QCommandLinkButton *commandLinkButton_Close;
    QCheckBox *checkBox_Tue;
    QCheckBox *checkBox_Wed;
    QCheckBox *checkBox_Thu;
    QCheckBox *checkBox_Fri;
    QPushButton *pushButton_SetDiscipline;
    QLabel *label_EndDate;
    QLabel *label_StartDate;
    QDateEdit *dateEdit_End;
    QDateEdit *dateEdit_Start;
    QVBoxLayout *verticalLayout_4;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *label_TeacherInfo;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *spinBox_Size;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_OkSize;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_Disciplines;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *comboBox_Disciplines;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_Info;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Set;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_SetNewTeacherInfo;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_AddDiscipline;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_Title;
    QLabel *label_Titlelable;
    QPushButton *pushButton_Student;
    QPushButton *pushButton_Teacher;
    QPushButton *pushButton_Registration;
    QPushButton *pushButton_Admin;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(770, 687);
        MainWindow->setMinimumSize(QSize(770, 687));
        MainWindow->setMaximumSize(QSize(770, 687));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow{\n"
"background-color:rgb(247, 255, 247);\n"
"color:rgb(26, 83, 92);\n"
"}"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icons/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionAddTeacher = new QAction(MainWindow);
        actionAddTeacher->setObjectName(QString::fromUtf8("actionAddTeacher"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddTeacher->setIcon(icon1);
        actionDeleteTeacher = new QAction(MainWindow);
        actionDeleteTeacher->setObjectName(QString::fromUtf8("actionDeleteTeacher"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteTeacher->setIcon(icon2);
        actionCreateDiscipline = new QAction(MainWindow);
        actionCreateDiscipline->setObjectName(QString::fromUtf8("actionCreateDiscipline"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icons/addDiscipline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreateDiscipline->setIcon(icon3);
        actionBackToTitle = new QAction(MainWindow);
        actionBackToTitle->setObjectName(QString::fromUtf8("actionBackToTitle"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/icons/editundo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBackToTitle->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 10, 751, 591));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_DisciplineName = new QLineEdit(layoutWidget);
        lineEdit_DisciplineName->setObjectName(QString::fromUtf8("lineEdit_DisciplineName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_DisciplineName->sizePolicy().hasHeightForWidth());
        lineEdit_DisciplineName->setSizePolicy(sizePolicy);
        lineEdit_DisciplineName->setMinimumSize(QSize(190, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        lineEdit_DisciplineName->setFont(font);

        gridLayout->addWidget(lineEdit_DisciplineName, 0, 1, 1, 1);

        label_DisCourse = new QLabel(layoutWidget);
        label_DisCourse->setObjectName(QString::fromUtf8("label_DisCourse"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_DisCourse->sizePolicy().hasHeightForWidth());
        label_DisCourse->setSizePolicy(sizePolicy1);
        label_DisCourse->setFont(font);
        label_DisCourse->setFocusPolicy(Qt::NoFocus);
        label_DisCourse->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_DisCourse->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(label_DisCourse, 2, 0, 1, 1);

        comboBox_DisCourse = new QComboBox(layoutWidget);
        comboBox_DisCourse->addItem(QString());
        comboBox_DisCourse->addItem(QString());
        comboBox_DisCourse->addItem(QString());
        comboBox_DisCourse->addItem(QString());
        comboBox_DisCourse->setObjectName(QString::fromUtf8("comboBox_DisCourse"));
        sizePolicy.setHeightForWidth(comboBox_DisCourse->sizePolicy().hasHeightForWidth());
        comboBox_DisCourse->setSizePolicy(sizePolicy);
        comboBox_DisCourse->setMinimumSize(QSize(190, 0));
        comboBox_DisCourse->setFont(font);

        gridLayout->addWidget(comboBox_DisCourse, 2, 1, 1, 2);

        label_Days = new QLabel(layoutWidget);
        label_Days->setObjectName(QString::fromUtf8("label_Days"));
        label_Days->setFont(font);

        gridLayout->addWidget(label_Days, 0, 2, 1, 1);

        checkBox_Mon = new QCheckBox(layoutWidget);
        checkBox_Mon->setObjectName(QString::fromUtf8("checkBox_Mon"));
        checkBox_Mon->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBox_Mon->sizePolicy().hasHeightForWidth());
        checkBox_Mon->setSizePolicy(sizePolicy2);
        checkBox_Mon->setFont(font);
        checkBox_Mon->setContextMenuPolicy(Qt::DefaultContextMenu);
        checkBox_Mon->setLayoutDirection(Qt::LeftToRight);
        checkBox_Mon->setAutoFillBackground(false);
        checkBox_Mon->setTristate(false);

        gridLayout->addWidget(checkBox_Mon, 0, 3, 1, 1);

        label_DisName = new QLabel(layoutWidget);
        label_DisName->setObjectName(QString::fromUtf8("label_DisName"));
        sizePolicy1.setHeightForWidth(label_DisName->sizePolicy().hasHeightForWidth());
        label_DisName->setSizePolicy(sizePolicy1);
        label_DisName->setFont(font);

        gridLayout->addWidget(label_DisName, 0, 0, 1, 1);

        commandLinkButton_Close = new QCommandLinkButton(layoutWidget);
        commandLinkButton_Close->setObjectName(QString::fromUtf8("commandLinkButton_Close"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(commandLinkButton_Close->sizePolicy().hasHeightForWidth());
        commandLinkButton_Close->setSizePolicy(sizePolicy3);
        commandLinkButton_Close->setMinimumSize(QSize(0, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setUnderline(true);
        font1.setWeight(50);
        commandLinkButton_Close->setFont(font1);
        commandLinkButton_Close->setLayoutDirection(Qt::RightToLeft);
        commandLinkButton_Close->setIconSize(QSize(16, 16));

        gridLayout->addWidget(commandLinkButton_Close, 0, 4, 1, 1);

        checkBox_Tue = new QCheckBox(layoutWidget);
        checkBox_Tue->setObjectName(QString::fromUtf8("checkBox_Tue"));
        checkBox_Tue->setFont(font);
        checkBox_Tue->setTristate(false);

        gridLayout->addWidget(checkBox_Tue, 2, 3, 1, 1);

        checkBox_Wed = new QCheckBox(layoutWidget);
        checkBox_Wed->setObjectName(QString::fromUtf8("checkBox_Wed"));
        checkBox_Wed->setFont(font);
        checkBox_Wed->setTristate(false);

        gridLayout->addWidget(checkBox_Wed, 3, 3, 1, 1);

        checkBox_Thu = new QCheckBox(layoutWidget);
        checkBox_Thu->setObjectName(QString::fromUtf8("checkBox_Thu"));
        sizePolicy2.setHeightForWidth(checkBox_Thu->sizePolicy().hasHeightForWidth());
        checkBox_Thu->setSizePolicy(sizePolicy2);
        checkBox_Thu->setFont(font);
        checkBox_Thu->setTristate(false);

        gridLayout->addWidget(checkBox_Thu, 4, 3, 1, 1);

        checkBox_Fri = new QCheckBox(layoutWidget);
        checkBox_Fri->setObjectName(QString::fromUtf8("checkBox_Fri"));
        checkBox_Fri->setFont(font);
        checkBox_Fri->setTristate(false);

        gridLayout->addWidget(checkBox_Fri, 5, 3, 1, 1);

        pushButton_SetDiscipline = new QPushButton(layoutWidget);
        pushButton_SetDiscipline->setObjectName(QString::fromUtf8("pushButton_SetDiscipline"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_SetDiscipline->sizePolicy().hasHeightForWidth());
        pushButton_SetDiscipline->setSizePolicy(sizePolicy4);
        pushButton_SetDiscipline->setMinimumSize(QSize(60, 26));
        pushButton_SetDiscipline->setFont(font);
        pushButton_SetDiscipline->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));
        pushButton_SetDiscipline->setAutoDefault(false);
        pushButton_SetDiscipline->setFlat(false);

        gridLayout->addWidget(pushButton_SetDiscipline, 4, 4, 2, 1);

        label_EndDate = new QLabel(layoutWidget);
        label_EndDate->setObjectName(QString::fromUtf8("label_EndDate"));
        label_EndDate->setFont(font);
        label_EndDate->setFocusPolicy(Qt::NoFocus);

        gridLayout->addWidget(label_EndDate, 5, 0, 1, 1);

        label_StartDate = new QLabel(layoutWidget);
        label_StartDate->setObjectName(QString::fromUtf8("label_StartDate"));
        label_StartDate->setFont(font);
        label_StartDate->setFocusPolicy(Qt::NoFocus);
        label_StartDate->setLayoutDirection(Qt::LeftToRight);
        label_StartDate->setAutoFillBackground(false);
        label_StartDate->setLocale(QLocale(QLocale::Ukrainian, QLocale::Ukraine));
        label_StartDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_StartDate, 4, 0, 1, 1);

        dateEdit_End = new QDateEdit(layoutWidget);
        dateEdit_End->setObjectName(QString::fromUtf8("dateEdit_End"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(dateEdit_End->sizePolicy().hasHeightForWidth());
        dateEdit_End->setSizePolicy(sizePolicy5);
        dateEdit_End->setFont(font);
        dateEdit_End->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateEdit_End->setDateTime(QDateTime(QDate(2021, 5, 30), QTime(0, 0, 0)));
        dateEdit_End->setMaximumDate(QDate(2050, 12, 31));
        dateEdit_End->setMinimumDate(QDate(2018, 9, 1));
        dateEdit_End->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_End, 5, 1, 1, 1);

        dateEdit_Start = new QDateEdit(layoutWidget);
        dateEdit_Start->setObjectName(QString::fromUtf8("dateEdit_Start"));
        sizePolicy5.setHeightForWidth(dateEdit_Start->sizePolicy().hasHeightForWidth());
        dateEdit_Start->setSizePolicy(sizePolicy5);
        dateEdit_Start->setFont(font);
        dateEdit_Start->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateEdit_Start->setDateTime(QDateTime(QDate(2020, 9, 1), QTime(0, 0, 0)));
        dateEdit_Start->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit_Start, 4, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);


        verticalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_TeacherInfo = new QLabel(layoutWidget);
        label_TeacherInfo->setObjectName(QString::fromUtf8("label_TeacherInfo"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto"));
        font2.setPointSize(12);
        label_TeacherInfo->setFont(font2);

        horizontalLayout->addWidget(label_TeacherInfo);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        spinBox_Size = new QSpinBox(layoutWidget);
        spinBox_Size->setObjectName(QString::fromUtf8("spinBox_Size"));
        sizePolicy4.setHeightForWidth(spinBox_Size->sizePolicy().hasHeightForWidth());
        spinBox_Size->setSizePolicy(sizePolicy4);
        spinBox_Size->setMinimumSize(QSize(50, 0));
        spinBox_Size->setFont(font2);

        horizontalLayout->addWidget(spinBox_Size);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_OkSize = new QPushButton(layoutWidget);
        pushButton_OkSize->setObjectName(QString::fromUtf8("pushButton_OkSize"));
        sizePolicy1.setHeightForWidth(pushButton_OkSize->sizePolicy().hasHeightForWidth());
        pushButton_OkSize->setSizePolicy(sizePolicy1);
        pushButton_OkSize->setMinimumSize(QSize(50, 5));
        pushButton_OkSize->setFont(font2);
        pushButton_OkSize->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));

        horizontalLayout->addWidget(pushButton_OkSize);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label_Disciplines = new QLabel(layoutWidget);
        label_Disciplines->setObjectName(QString::fromUtf8("label_Disciplines"));
        label_Disciplines->setFont(font2);

        horizontalLayout->addWidget(label_Disciplines);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        comboBox_Disciplines = new QComboBox(layoutWidget);
        comboBox_Disciplines->setObjectName(QString::fromUtf8("comboBox_Disciplines"));
        comboBox_Disciplines->setMinimumSize(QSize(300, 0));
        comboBox_Disciplines->setFont(font2);

        horizontalLayout->addWidget(comboBox_Disciplines);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget_Info = new QTableWidget(layoutWidget);
        tableWidget_Info->setObjectName(QString::fromUtf8("tableWidget_Info"));
        tableWidget_Info->setFont(font2);
        tableWidget_Info->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget_Info->horizontalHeader()->setDefaultSectionSize(180);

        verticalLayout->addWidget(tableWidget_Info);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_Set = new QPushButton(layoutWidget);
        pushButton_Set->setObjectName(QString::fromUtf8("pushButton_Set"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButton_Set->sizePolicy().hasHeightForWidth());
        pushButton_Set->setSizePolicy(sizePolicy6);
        pushButton_Set->setMinimumSize(QSize(100, 30));
        pushButton_Set->setFont(font2);
        pushButton_Set->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_Set);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        pushButton_SetNewTeacherInfo = new QPushButton(layoutWidget);
        pushButton_SetNewTeacherInfo->setObjectName(QString::fromUtf8("pushButton_SetNewTeacherInfo"));
        pushButton_SetNewTeacherInfo->setMinimumSize(QSize(200, 30));
        pushButton_SetNewTeacherInfo->setFont(font2);
        pushButton_SetNewTeacherInfo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_SetNewTeacherInfo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_AddDiscipline = new QPushButton(layoutWidget);
        pushButton_AddDiscipline->setObjectName(QString::fromUtf8("pushButton_AddDiscipline"));
        pushButton_AddDiscipline->setMinimumSize(QSize(200, 30));
        pushButton_AddDiscipline->setFont(font2);
        pushButton_AddDiscipline->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_AddDiscipline);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        label_Title = new QLabel(centralwidget);
        label_Title->setObjectName(QString::fromUtf8("label_Title"));
        label_Title->setGeometry(QRect(160, 90, 450, 92));
        sizePolicy1.setHeightForWidth(label_Title->sizePolicy().hasHeightForWidth());
        label_Title->setSizePolicy(sizePolicy1);
        label_Title->setMaximumSize(QSize(450, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Roboto"));
        font3.setPointSize(28);
        font3.setBold(true);
        font3.setWeight(75);
        label_Title->setFont(font3);
        label_Titlelable = new QLabel(centralwidget);
        label_Titlelable->setObjectName(QString::fromUtf8("label_Titlelable"));
        label_Titlelable->setGeometry(QRect(250, 180, 221, 71));
        label_Titlelable->setMaximumSize(QSize(450, 16777215));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Roboto"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setWeight(75);
        label_Titlelable->setFont(font4);
        pushButton_Student = new QPushButton(centralwidget);
        pushButton_Student->setObjectName(QString::fromUtf8("pushButton_Student"));
        pushButton_Student->setGeometry(QRect(220, 250, 321, 71));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pushButton_Student->sizePolicy().hasHeightForWidth());
        pushButton_Student->setSizePolicy(sizePolicy7);
        pushButton_Student->setMinimumSize(QSize(0, 40));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Roboto"));
        font5.setPointSize(16);
        font5.setBold(false);
        font5.setWeight(50);
        pushButton_Student->setFont(font5);
        pushButton_Student->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(78, 205, 196);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(35, 93, 87, 255), stop:1 rgba(97, 255, 240, 255))\n"
"}"));
        pushButton_Teacher = new QPushButton(centralwidget);
        pushButton_Teacher->setObjectName(QString::fromUtf8("pushButton_Teacher"));
        pushButton_Teacher->setGeometry(QRect(220, 340, 321, 71));
        sizePolicy7.setHeightForWidth(pushButton_Teacher->sizePolicy().hasHeightForWidth());
        pushButton_Teacher->setSizePolicy(sizePolicy7);
        pushButton_Teacher->setMinimumSize(QSize(0, 40));
        pushButton_Teacher->setMaximumSize(QSize(16777215, 16777215));
        pushButton_Teacher->setFont(font5);
        pushButton_Teacher->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 230, 109);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(148, 132, 63, 255), stop:1 rgba(255, 230, 109, 255));\n"
"}"));
        pushButton_Registration = new QPushButton(centralwidget);
        pushButton_Registration->setObjectName(QString::fromUtf8("pushButton_Registration"));
        pushButton_Registration->setGeometry(QRect(220, 430, 321, 41));
        sizePolicy2.setHeightForWidth(pushButton_Registration->sizePolicy().hasHeightForWidth());
        pushButton_Registration->setSizePolicy(sizePolicy2);
        QFont font6;
        font6.setFamily(QString::fromUtf8("Roboto"));
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setWeight(50);
        pushButton_Registration->setFont(font6);
        pushButton_Registration->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color: rgb(255, 107, 107);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.484, y1:0, x2:0.505472, y2:1, stop:0 rgba(128, 64, 64, 255), stop:1 rgba(255, 107, 107, 255));\n"
"}"));
        pushButton_Admin = new QPushButton(centralwidget);
        pushButton_Admin->setObjectName(QString::fromUtf8("pushButton_Admin"));
        pushButton_Admin->setGeometry(QRect(390, 480, 151, 21));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Roboto"));
        font7.setPointSize(10);
        font7.setBold(false);
        font7.setWeight(50);
        pushButton_Admin->setFont(font7);
        pushButton_Admin->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 4px;\n"
"background-color: rgb(247, 255, 247);\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,\n"
"														stop: 0 #BEBEBE, stop:1 #D7D7D7);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 770, 20));
        menuBar->setLayoutDirection(Qt::LeftToRight);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(30, 25));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        toolBar->addAction(actionBackToTitle);
        toolBar->addSeparator();
        toolBar->addAction(actionAddTeacher);
        toolBar->addAction(actionDeleteTeacher);
        toolBar->addAction(actionCreateDiscipline);

        retranslateUi(MainWindow);

        pushButton_SetDiscipline->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionAddTeacher->setText(QCoreApplication::translate("MainWindow", "AddTeacher", nullptr));
#if QT_CONFIG(tooltip)
        actionAddTeacher->setToolTip(QCoreApplication::translate("MainWindow", "Add area for teacher info to your list", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDeleteTeacher->setText(QCoreApplication::translate("MainWindow", "DeleteTeacher", nullptr));
#if QT_CONFIG(tooltip)
        actionDeleteTeacher->setToolTip(QCoreApplication::translate("MainWindow", "Delete area with teacher info", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCreateDiscipline->setText(QCoreApplication::translate("MainWindow", "CreateDiscipline", nullptr));
#if QT_CONFIG(tooltip)
        actionCreateDiscipline->setToolTip(QCoreApplication::translate("MainWindow", "Create a new one discipline", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBackToTitle->setText(QCoreApplication::translate("MainWindow", "BackToTitle", nullptr));
#if QT_CONFIG(tooltip)
        actionBackToTitle->setToolTip(QCoreApplication::translate("MainWindow", "Back to title page ", nullptr));
#endif // QT_CONFIG(tooltip)
        label_DisCourse->setText(QCoreApplication::translate("MainWindow", "  Course: ", nullptr));
        comboBox_DisCourse->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_DisCourse->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_DisCourse->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_DisCourse->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));

        label_Days->setText(QCoreApplication::translate("MainWindow", "      Days:", nullptr));
        checkBox_Mon->setText(QCoreApplication::translate("MainWindow", "Monday", nullptr));
        label_DisName->setText(QCoreApplication::translate("MainWindow", "  Discipline name:", nullptr));
#if QT_CONFIG(tooltip)
        commandLinkButton_Close->setToolTip(QCoreApplication::translate("MainWindow", "Closes \"Create discipline\" window", nullptr));
#endif // QT_CONFIG(tooltip)
        commandLinkButton_Close->setText(QCoreApplication::translate("MainWindow", "Close this window", nullptr));
        checkBox_Tue->setText(QCoreApplication::translate("MainWindow", "Tuesday", nullptr));
        checkBox_Wed->setText(QCoreApplication::translate("MainWindow", "Wednesday", nullptr));
        checkBox_Thu->setText(QCoreApplication::translate("MainWindow", "Thursday", nullptr));
        checkBox_Fri->setText(QCoreApplication::translate("MainWindow", "Friday", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_SetDiscipline->setToolTip(QCoreApplication::translate("MainWindow", "Saves information about new discipline", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_SetDiscipline->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_SetDiscipline->setText(QCoreApplication::translate("MainWindow", "SET", nullptr));
        label_EndDate->setText(QCoreApplication::translate("MainWindow", "  End Date:", nullptr));
        label_StartDate->setText(QCoreApplication::translate("MainWindow", "  Start Date:", nullptr));
        dateEdit_End->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        dateEdit_Start->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd/MM/yyyy", nullptr));
        label_TeacherInfo->setText(QCoreApplication::translate("MainWindow", "  Print count of teachers:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_OkSize->setToolTip(QCoreApplication::translate("MainWindow", "Sets count of table rows", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_OkSize->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_OkSize->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_Disciplines->setText(QCoreApplication::translate("MainWindow", "  Disciplines:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Set->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Saves all information in table to create a new teacher list</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_Set->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_Set->setText(QCoreApplication::translate("MainWindow", "Set Info", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_SetNewTeacherInfo->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Saves information about new teachers</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_SetNewTeacherInfo->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_SetNewTeacherInfo->setText(QCoreApplication::translate("MainWindow", "Set new Teachers Info", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_AddDiscipline->setToolTip(QCoreApplication::translate("MainWindow", "Creates an additional column for discipline", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_AddDiscipline->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_AddDiscipline->setText(QCoreApplication::translate("MainWindow", "Add Discipline Area", nullptr));
        label_Title->setText(QCoreApplication::translate("MainWindow", "    IT Private school \342\204\22631", nullptr));
        label_Titlelable->setText(QCoreApplication::translate("MainWindow", "         Log in system as:", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Student->setToolTip(QCoreApplication::translate("MainWindow", "Enters to system as student", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_Student->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_Student->setText(QCoreApplication::translate("MainWindow", "Student", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Teacher->setToolTip(QCoreApplication::translate("MainWindow", "Enters to system as teacher", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_Teacher->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_Teacher->setText(QCoreApplication::translate("MainWindow", "Teacher", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Registration->setToolTip(QCoreApplication::translate("MainWindow", "Creates student account", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_Registration->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_Registration->setText(QCoreApplication::translate("MainWindow", "Registration", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_Admin->setToolTip(QCoreApplication::translate("MainWindow", "Enters to system as admin", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_Admin->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        pushButton_Admin->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
