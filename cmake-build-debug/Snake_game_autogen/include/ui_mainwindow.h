/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pauseButton;
    QFrame *pauseFrame;
    QPushButton *continueButton;
    QLabel *label;
    QPushButton *quit_but;
    QFrame *gameOver;
    QLabel *label_2;
    QPushButton *quit_but_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *score_label;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1800, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(16, 15, 51, 41));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pauseButton->sizePolicy().hasHeightForWidth());
        pauseButton->setSizePolicy(sizePolicy);
        pauseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(/Users/sagot/Documents/Snake-game/images/pausebut.png);\n"
"    background-color: white;\n"
"    border-radius: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: blue;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: darkestBlue;\n"
"}"));
        pauseFrame = new QFrame(centralwidget);
        pauseFrame->setObjectName("pauseFrame");
        pauseFrame->setGeometry(QRect(400, 300, 500, 300));
        pauseFrame->setStyleSheet(QString::fromUtf8("background-color:rgb(22, 37, 74);\n"
"border-radius: 30;\n"
""));
        pauseFrame->setFrameShape(QFrame::StyledPanel);
        pauseFrame->setFrameShadow(QFrame::Raised);
        continueButton = new QPushButton(pauseFrame);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(70, 230, 361, 51));
        continueButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius:25;\n"
"	font: 700 30pt \"Arial\";\n"
"	background-color:rgb(9, 20, 96);\n"
"	color: white;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(66, 14, 155);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(34, 10, 105);\n"
"	color: white;\n"
"}\n"
"\n"
""));
        label = new QLabel(pauseFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 40, 391, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(90);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 90pt \"Arial\";"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        quit_but = new QPushButton(pauseFrame);
        quit_but->setObjectName("quit_but");
        quit_but->setGeometry(QRect(70, 170, 361, 51));
        quit_but->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	font: 700 30pt \"Arial\";\n"
"	border-radius: 25;\n"
"	background-color:rgb(9, 20, 96);\n"
"	color: white;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(66, 14, 155);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(34, 10, 105);\n"
"	color: white;\n"
"}\n"
""));
        quit_but->setIconSize(QSize(16, 16));
        gameOver = new QFrame(pauseFrame);
        gameOver->setObjectName("gameOver");
        gameOver->setGeometry(QRect(0, 0, 500, 300));
        gameOver->setStyleSheet(QString::fromUtf8("background-color:rgb(22, 37, 74);\n"
"border-radius: 30;\n"
""));
        gameOver->setFrameShape(QFrame::StyledPanel);
        gameOver->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(gameOver);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 0, 421, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(80);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 80pt \"Arial\";"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);
        quit_but_2 = new QPushButton(gameOver);
        quit_but_2->setObjectName("quit_but_2");
        quit_but_2->setGeometry(QRect(80, 240, 321, 51));
        quit_but_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius:15px;\n"
"	font: 700 30pt \"Arial\";\n"
"	background-color:rgb(9, 20, 96);\n"
"	color: white;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(66, 14, 155);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(34, 10, 105);\n"
"	color: white;\n"
"}\n"
""));
        quit_but_2->setIconSize(QSize(16, 16));
        label_3 = new QLabel(gameOver);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 70, 341, 81));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 80pt \"Arial\";"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);
        label_4 = new QLabel(gameOver);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 150, 201, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(60);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 60pt \"Arial\";"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);
        score_label = new QLabel(gameOver);
        score_label->setObjectName("score_label");
        score_label->setGeometry(QRect(210, 150, 281, 71));
        score_label->setFont(font2);
        score_label->setStyleSheet(QString::fromUtf8("color:white;\n"
"font: 700 60pt \"Arial\";"));
        score_label->setTextFormat(Qt::AutoText);
        score_label->setScaledContents(false);
        score_label->setAlignment(Qt::AlignCenter);
        score_label->setWordWrap(false);
        quit_but_2->raise();
        label_3->raise();
        label_2->raise();
        label_4->raise();
        score_label->raise();
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        pauseButton->raise();
        pauseFrame->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pauseButton->setText(QString());
        continueButton->setText(QCoreApplication::translate("MainWindow", "CONTINUE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        quit_but->setText(QCoreApplication::translate("MainWindow", "QUIT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "GAME ", nullptr));
        quit_but_2->setText(QCoreApplication::translate("MainWindow", "QUIT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "OVER", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        score_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
