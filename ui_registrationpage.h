/********************************************************************************
** Form generated from reading UI file 'registrationpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONPAGE_H
#define UI_REGISTRATIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Registrationpage
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_Info;
    QLineEdit *lineEdit_Surname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_Course;
    QLineEdit *lineEdit_GroupName;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *comboBox_GroupNum;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_Password2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Reg;
    QCommandLinkButton *commandLinkButton_BackToLogin;

    void setupUi(QDialog *Registrationpage)
    {
        if (Registrationpage->objectName().isEmpty())
            Registrationpage->setObjectName(QString::fromUtf8("Registrationpage"));
        Registrationpage->resize(444, 565);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Registrationpage->sizePolicy().hasHeightForWidth());
        Registrationpage->setSizePolicy(sizePolicy);
        Registrationpage->setMinimumSize(QSize(420, 500));
        gridLayout = new QGridLayout(Registrationpage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(Registrationpage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(14);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_Info = new QLabel(groupBox);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Info->sizePolicy().hasHeightForWidth());
        label_Info->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(12);
        label_Info->setFont(font1);

        verticalLayout->addWidget(label_Info);

        lineEdit_Surname = new QLineEdit(groupBox);
        lineEdit_Surname->setObjectName(QString::fromUtf8("lineEdit_Surname"));
        sizePolicy.setHeightForWidth(lineEdit_Surname->sizePolicy().hasHeightForWidth());
        lineEdit_Surname->setSizePolicy(sizePolicy);
        lineEdit_Surname->setFont(font);
        lineEdit_Surname->setLayoutDirection(Qt::RightToLeft);
        lineEdit_Surname->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius: 8px;\n"
"}"));
        lineEdit_Surname->setInputMethodHints(Qt::ImhNone);
        lineEdit_Surname->setMaxLength(20);
        lineEdit_Surname->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_Surname->setClearButtonEnabled(false);

        verticalLayout->addWidget(lineEdit_Surname);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        comboBox_Course = new QComboBox(groupBox);
        comboBox_Course->addItem(QString());
        comboBox_Course->addItem(QString());
        comboBox_Course->addItem(QString());
        comboBox_Course->addItem(QString());
        comboBox_Course->setObjectName(QString::fromUtf8("comboBox_Course"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox_Course->sizePolicy().hasHeightForWidth());
        comboBox_Course->setSizePolicy(sizePolicy2);
        comboBox_Course->setMinimumSize(QSize(168, 40));
        comboBox_Course->setFont(font);
        comboBox_Course->setLayoutDirection(Qt::RightToLeft);
        comboBox_Course->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"}"));

        horizontalLayout_2->addWidget(comboBox_Course);


        verticalLayout->addLayout(horizontalLayout_2);

        lineEdit_GroupName = new QLineEdit(groupBox);
        lineEdit_GroupName->setObjectName(QString::fromUtf8("lineEdit_GroupName"));
        sizePolicy.setHeightForWidth(lineEdit_GroupName->sizePolicy().hasHeightForWidth());
        lineEdit_GroupName->setSizePolicy(sizePolicy);
        lineEdit_GroupName->setMinimumSize(QSize(100, 0));
        lineEdit_GroupName->setLayoutDirection(Qt::RightToLeft);
        lineEdit_GroupName->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius: 8px;\n"
"}"));
        lineEdit_GroupName->setMaxLength(3);

        verticalLayout->addWidget(lineEdit_GroupName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        comboBox_GroupNum = new QComboBox(groupBox);
        comboBox_GroupNum->addItem(QString());
        comboBox_GroupNum->addItem(QString());
        comboBox_GroupNum->addItem(QString());
        comboBox_GroupNum->addItem(QString());
        comboBox_GroupNum->addItem(QString());
        comboBox_GroupNum->addItem(QString());
        comboBox_GroupNum->setObjectName(QString::fromUtf8("comboBox_GroupNum"));
        sizePolicy1.setHeightForWidth(comboBox_GroupNum->sizePolicy().hasHeightForWidth());
        comboBox_GroupNum->setSizePolicy(sizePolicy1);
        comboBox_GroupNum->setMinimumSize(QSize(168, 40));
        comboBox_GroupNum->setFont(font);
        comboBox_GroupNum->setLayoutDirection(Qt::RightToLeft);
        comboBox_GroupNum->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"border-radius: 8px;\n"
"background-color:white;\n"
"}"));

        horizontalLayout->addWidget(comboBox_GroupNum);


        verticalLayout->addLayout(horizontalLayout);

        lineEdit_Password = new QLineEdit(groupBox);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        sizePolicy.setHeightForWidth(lineEdit_Password->sizePolicy().hasHeightForWidth());
        lineEdit_Password->setSizePolicy(sizePolicy);
        lineEdit_Password->setLayoutDirection(Qt::LeftToRight);
        lineEdit_Password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius: 8px;\n"
"}"));
        lineEdit_Password->setMaxLength(15);

        verticalLayout->addWidget(lineEdit_Password);

        lineEdit_Password2 = new QLineEdit(groupBox);
        lineEdit_Password2->setObjectName(QString::fromUtf8("lineEdit_Password2"));
        sizePolicy.setHeightForWidth(lineEdit_Password2->sizePolicy().hasHeightForWidth());
        lineEdit_Password2->setSizePolicy(sizePolicy);
        lineEdit_Password2->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius: 8px;\n"
"}"));
        lineEdit_Password2->setMaxLength(15);
        lineEdit_Password2->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_Password2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pushButton_Reg = new QPushButton(groupBox);
        pushButton_Reg->setObjectName(QString::fromUtf8("pushButton_Reg"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_Reg->sizePolicy().hasHeightForWidth());
        pushButton_Reg->setSizePolicy(sizePolicy4);
        pushButton_Reg->setMinimumSize(QSize(0, 50));
        pushButton_Reg->setMaximumSize(QSize(1000, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto"));
        font2.setPointSize(16);
        pushButton_Reg->setFont(font2);
        pushButton_Reg->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"color:white;\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.523, x2:1, y2:0.534, stop:0 rgba(57, 60, 106, 255), stop:1 rgba(93, 205, 173, 255));\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0.478, x2:1, y2:0.534, stop:0 rgba(34, 36, 63, 255), stop:1 rgba(37, 81, 68, 255));\n"
"}"));
        pushButton_Reg->setAutoDefault(false);

        verticalLayout->addWidget(pushButton_Reg);

        commandLinkButton_BackToLogin = new QCommandLinkButton(groupBox);
        commandLinkButton_BackToLogin->setObjectName(QString::fromUtf8("commandLinkButton_BackToLogin"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(commandLinkButton_BackToLogin->sizePolicy().hasHeightForWidth());
        commandLinkButton_BackToLogin->setSizePolicy(sizePolicy5);
        commandLinkButton_BackToLogin->setMinimumSize(QSize(0, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Roboto"));
        font3.setPointSize(14);
        font3.setUnderline(true);
        commandLinkButton_BackToLogin->setFont(font3);
        commandLinkButton_BackToLogin->setStyleSheet(QString::fromUtf8("QCommandLinkButton{\n"
"color:rgb(26, 83, 92);\n"
"}"));

        verticalLayout->addWidget(commandLinkButton_BackToLogin);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);


        retranslateUi(Registrationpage);

        QMetaObject::connectSlotsByName(Registrationpage);
    } // setupUi

    void retranslateUi(QDialog *Registrationpage)
    {
        Registrationpage->setWindowTitle(QCoreApplication::translate("Registrationpage", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Registrationpage", "Student registration", nullptr));
        label_Info->setText(QString());
        lineEdit_Surname->setText(QString());
        label_3->setText(QCoreApplication::translate("Registrationpage", " Course:", nullptr));
        comboBox_Course->setItemText(0, QCoreApplication::translate("Registrationpage", "1", nullptr));
        comboBox_Course->setItemText(1, QCoreApplication::translate("Registrationpage", "2", nullptr));
        comboBox_Course->setItemText(2, QCoreApplication::translate("Registrationpage", "3", nullptr));
        comboBox_Course->setItemText(3, QCoreApplication::translate("Registrationpage", "4", nullptr));

        label_4->setText(QCoreApplication::translate("Registrationpage", "Group Num:", nullptr));
        comboBox_GroupNum->setItemText(0, QCoreApplication::translate("Registrationpage", "1", nullptr));
        comboBox_GroupNum->setItemText(1, QCoreApplication::translate("Registrationpage", "2", nullptr));
        comboBox_GroupNum->setItemText(2, QCoreApplication::translate("Registrationpage", "3", nullptr));
        comboBox_GroupNum->setItemText(3, QCoreApplication::translate("Registrationpage", "4", nullptr));
        comboBox_GroupNum->setItemText(4, QCoreApplication::translate("Registrationpage", "5", nullptr));
        comboBox_GroupNum->setItemText(5, QCoreApplication::translate("Registrationpage", "6", nullptr));

#if QT_CONFIG(tooltip)
        pushButton_Reg->setToolTip(QCoreApplication::translate("Registrationpage", "Creates an account", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Reg->setText(QCoreApplication::translate("Registrationpage", "Sign up", nullptr));
#if QT_CONFIG(tooltip)
        commandLinkButton_BackToLogin->setToolTip(QCoreApplication::translate("Registrationpage", "Returns to login window", nullptr));
#endif // QT_CONFIG(tooltip)
        commandLinkButton_BackToLogin->setText(QCoreApplication::translate("Registrationpage", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registrationpage: public Ui_Registrationpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONPAGE_H
