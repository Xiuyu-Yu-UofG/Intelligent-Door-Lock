/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *lock_btn;
    QWidget *tab_2;
    QLabel *label_save;
    QLineEdit *lineEdit;
    QPushButton *save_btn;
    QWidget *tab_3;
    QListWidget *listWidget;
    QLabel *label_delete;
    QLabel *label_info;
    QPushButton *delete_btn;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(1280, 720);
        tabWidget = new QTabWidget(Welcome);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 1221, 691));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane{\n"
"	border: 2px solid rgb(210, 210, 210);\n"
"	background:rgb(246, 246, 246);\n"
"	border-top-color:transparent;\n"
"}\n"
"QTabWidget::tab-bar{\n"
"	background:rgb(0, 0, 0);\n"
"	subcontrol-position:center;\n"
"}\n"
"QTabBar::tab{\n"
"	width:400px;/*\345\256\275\345\272\246\346\240\271\346\215\256\345\256\236\351\231\205\351\234\200\350\246\201\350\277\233\350\241\214\350\260\203\346\225\264*/\n"
"	height:100px;\n"
"	background:rgb(210, 210, 210);\n"
"	border: 2px solid rgb(210, 210, 210);\n"
"	border-top-left-radius: 8px;\n"
"	border-top-right-radius: 8px;\n"
"    font-size:30px;\n"
"}\n"
"QTabBar::tab:selected{	\n"
"	background:rgb(246, 246, 246);\n"
"	border-bottom-color:rgb(246, 246, 246);\n"
"}\n"
"QTabBar::tab:!selected{\n"
"	background:qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(240, 240, 240, 255), stop:0.5 rgba(210, 210, 210, 255), stop:1 rgba(225, 225, 225, 255));\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 10, 640, 480));
        label->setFrameShape(QFrame::Box);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 500, 641, 71));
        QFont font;
        font.setPointSize(20);
        pushButton->setFont(font);
        lock_btn = new QPushButton(tab);
        lock_btn->setObjectName(QStringLiteral("lock_btn"));
        lock_btn->setGeometry(QRect(1010, 180, 151, 131));
        lock_btn->setFont(font);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_save = new QLabel(tab_2);
        label_save->setObjectName(QStringLiteral("label_save"));
        label_save->setGeometry(QRect(290, 10, 640, 480));
        label_save->setFrameShape(QFrame::Box);
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(290, 500, 641, 71));
        lineEdit->setFont(font);
        save_btn = new QPushButton(tab_2);
        save_btn->setObjectName(QStringLiteral("save_btn"));
        save_btn->setGeometry(QRect(950, 150, 251, 201));
        save_btn->setFont(font);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        listWidget = new QListWidget(tab_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(940, 10, 271, 381));
        label_delete = new QLabel(tab_3);
        label_delete->setObjectName(QStringLiteral("label_delete"));
        label_delete->setGeometry(QRect(290, 10, 640, 480));
        label_delete->setFrameShape(QFrame::Box);
        label_info = new QLabel(tab_3);
        label_info->setObjectName(QStringLiteral("label_info"));
        label_info->setGeometry(QRect(10, 10, 271, 481));
        delete_btn = new QPushButton(tab_3);
        delete_btn->setObjectName(QStringLiteral("delete_btn"));
        delete_btn->setGeometry(QRect(940, 400, 271, 91));
        delete_btn->setFont(font);
        tabWidget->addTab(tab_3, QString());

        retranslateUi(Welcome);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "E-Lock", nullptr));
        label->setText(QString());
        pushButton->setText(QApplication::translate("Welcome", "CLICK TO UNLOCK", nullptr));
        lock_btn->setText(QApplication::translate("Welcome", "LOCK\n"
"NOW", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Welcome", "Unlock", nullptr));
        label_save->setText(QString());
        save_btn->setText(QApplication::translate("Welcome", "SAVE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Welcome", "Create", nullptr));
        label_delete->setText(QString());
        label_info->setText(QString());
        delete_btn->setText(QApplication::translate("Welcome", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Welcome", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
