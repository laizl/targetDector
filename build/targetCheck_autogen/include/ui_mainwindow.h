/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *videoPlayer;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *videoText;
    QLineEdit *lineEdit_video;
    QPushButton *openVideo;
    QLabel *label;
    QTableView *CheckResult_tableView;
    QPushButton *startCheck;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1007, 617);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        videoPlayer = new QLabel(centralwidget);
        videoPlayer->setObjectName(QStringLiteral("videoPlayer"));
        videoPlayer->setGeometry(QRect(90, 70, 561, 481));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(81, 10, 581, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        videoText = new QLabel(layoutWidget);
        videoText->setObjectName(QStringLiteral("videoText"));

        horizontalLayout->addWidget(videoText);

        lineEdit_video = new QLineEdit(layoutWidget);
        lineEdit_video->setObjectName(QStringLiteral("lineEdit_video"));

        horizontalLayout->addWidget(lineEdit_video);

        openVideo = new QPushButton(layoutWidget);
        openVideo->setObjectName(QStringLiteral("openVideo"));

        horizontalLayout->addWidget(openVideo);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(780, 20, 54, 18));
        CheckResult_tableView = new QTableView(centralwidget);
        CheckResult_tableView->setObjectName(QStringLiteral("CheckResult_tableView"));
        CheckResult_tableView->setGeometry(QRect(690, 40, 291, 521));
        startCheck = new QPushButton(centralwidget);
        startCheck->setObjectName(QStringLiteral("startCheck"));
        startCheck->setGeometry(QRect(670, 10, 80, 26));
        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        videoPlayer->raise();
        label->raise();
        CheckResult_tableView->raise();
        startCheck->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1007, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        videoPlayer->setText(QString());
        videoText->setText(QApplication::translate("MainWindow", "\350\247\206\351\242\221\350\267\257\345\276\204", 0));
        openVideo->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\350\247\206\351\242\221", 0));
        label->setText(QApplication::translate("MainWindow", "\346\243\200\346\237\245\347\273\223\346\236\234", 0));
        startCheck->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\346\243\200\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
