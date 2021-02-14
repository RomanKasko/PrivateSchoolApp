/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Loginpage
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLabel *label_Info;
    QCommandLinkButton *commandLinkButton_BackToTitle;
    QLabel *label;
    QLineEdit *lineEdit_login;
    QLabel *label_2;
    QLineEdit *lineEdit_password;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Login;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ToRegistration;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *Loginpage)
    {
        if (Loginpage->objectName().isEmpty())
            Loginpage->setObjectName(QString::fromUtf8("Loginpage"));
        Loginpage->resize(468, 414);
        Loginpage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(Loginpage);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(Loginpage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"background-color:rgb(255,255,255);\n"
"}"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        label_Info = new QLabel(groupBox);
        label_Info->setObjectName(QString::fromUtf8("label_Info"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Info->sizePolicy().hasHeightForWidth());
        label_Info->setSizePolicy(sizePolicy);
        label_Info->setMinimumSize(QSize(0, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        label_Info->setFont(font1);
        label_Info->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(label_Info);

        commandLinkButton_BackToTitle = new QCommandLinkButton(groupBox);
        commandLinkButton_BackToTitle->setObjectName(QString::fromUtf8("commandLinkButton_BackToTitle"));
        sizePolicy.setHeightForWidth(commandLinkButton_BackToTitle->sizePolicy().hasHeightForWidth());
        commandLinkButton_BackToTitle->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Roboto"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setUnderline(true);
        font2.setWeight(50);
        commandLinkButton_BackToTitle->setFont(font2);
        commandLinkButton_BackToTitle->setStyleSheet(QString::fromUtf8("QCommandLinkButton{\n"
"color:rgb(26, 83, 92);\n"
"}"));

        verticalLayout->addWidget(commandLinkButton_BackToTitle);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Roboto"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        label->setFont(font3);

        verticalLayout->addWidget(label);

        lineEdit_login = new QLineEdit(groupBox);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setMinimumSize(QSize(0, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Roboto"));
        font4.setPointSize(14);
        font4.setItalic(true);
        lineEdit_login->setFont(font4);

        verticalLayout->addWidget(lineEdit_login);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);

        verticalLayout->addWidget(label_2);

        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMinimumSize(QSize(0, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Roboto"));
        font5.setPointSize(14);
        font5.setItalic(false);
        lineEdit_password->setFont(font5);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lineEdit_password);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        pushButton_Login = new QPushButton(groupBox);
        pushButton_Login->setObjectName(QString::fromUtf8("pushButton_Login"));
        pushButton_Login->setMinimumSize(QSize(0, 50));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Roboto"));
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setUnderline(false);
        font6.setWeight(75);
        font6.setStrikeOut(false);
        font6.setStyleStrategy(QFont::PreferAntialias);
        pushButton_Login->setFont(font6);
        pushButton_Login->setAutoFillBackground(false);
        pushButton_Login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 8px;\n"
"background-color:rgb(26, 83, 92) ;\n"
"color:white;\n"
"border: 1px solid gray; \n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"background-color:qlineargradient(spread:pad, x1:0.493, y1:0, x2:0.517, y2:0.994, stop:0 rgba(13, 43, 47, 255), stop:1 rgba(26, 83, 92, 255));\n"
"}"));
        pushButton_Login->setIconSize(QSize(16, 50));

        verticalLayout->addWidget(pushButton_Login);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ToRegistration = new QLabel(groupBox);
        label_ToRegistration->setObjectName(QString::fromUtf8("label_ToRegistration"));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Roboto"));
        font7.setPointSize(11);
        font7.setBold(false);
        font7.setUnderline(true);
        font7.setWeight(50);
        label_ToRegistration->setFont(font7);
        label_ToRegistration->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:rgb(26, 83, 92);\n"
"}"));

        horizontalLayout->addWidget(label_ToRegistration);

        commandLinkButton = new QCommandLinkButton(groupBox);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(commandLinkButton->sizePolicy().hasHeightForWidth());
        commandLinkButton->setSizePolicy(sizePolicy1);
        commandLinkButton->setMinimumSize(QSize(0, 0));
        commandLinkButton->setFont(font2);
        commandLinkButton->setContextMenuPolicy(Qt::NoContextMenu);
        commandLinkButton->setStyleSheet(QString::fromUtf8("QCommandLinkButton{\n"
"color:rgb(26, 83, 92);\n"
"}"));

        horizontalLayout->addWidget(commandLinkButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(groupBox);


        retranslateUi(Loginpage);

        QMetaObject::connectSlotsByName(Loginpage);
    } // setupUi

    void retranslateUi(QDialog *Loginpage)
    {
        Loginpage->setWindowTitle(QCoreApplication::translate("Loginpage", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label_4->setText(QCoreApplication::translate("Loginpage", "                                   Log In", nullptr));
        label_Info->setText(QString());
#if QT_CONFIG(tooltip)
        commandLinkButton_BackToTitle->setToolTip(QCoreApplication::translate("Loginpage", "Returns to title window", nullptr));
#endif // QT_CONFIG(tooltip)
        commandLinkButton_BackToTitle->setText(QCoreApplication::translate("Loginpage", "Back to title", nullptr));
        label->setText(QCoreApplication::translate("Loginpage", "Surname:", nullptr));
        lineEdit_login->setText(QString());
        label_2->setText(QCoreApplication::translate("Loginpage", "Password:", nullptr));
        lineEdit_password->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_Login->setToolTip(QCoreApplication::translate("Loginpage", "Enters to system", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_Login->setText(QCoreApplication::translate("Loginpage", "Log In", nullptr));
        label_ToRegistration->setText(QCoreApplication::translate("Loginpage", " Don`t have an account?", nullptr));
#if QT_CONFIG(tooltip)
        commandLinkButton->setToolTip(QCoreApplication::translate("Loginpage", "Creates a new student account", nullptr));
#endif // QT_CONFIG(tooltip)
        commandLinkButton->setText(QCoreApplication::translate("Loginpage", "Sign up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Loginpage: public Ui_Loginpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
