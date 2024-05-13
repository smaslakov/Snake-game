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
    QPushButton *pauseButton;
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
        pauseFrame = new QFrame(centralwidget);
        pauseFrame->setObjectName("pauseFrame");
        pauseFrame->setGeometry(QRect(500, 100, 371, 251));
        pauseFrame->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius: 30;\n"
""));
        pauseFrame->setFrameShape(QFrame::StyledPanel);
        pauseFrame->setFrameShadow(QFrame::Raised);
        continueButton = new QPushButton(pauseFrame);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(40, 190, 311, 32));
        continueButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	background-color: blue;\n"
"	color: white;\n"
"	font-size:25px;\n"
"	font-family:Arial;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: purple;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: darkestBlue;\n"
"	color: white;\n"
"}\n"
""));
        label = new QLabel(pauseFrame);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 30, 391, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(80);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:blue;"));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        quit_but = new QPushButton(pauseFrame);
        quit_but->setObjectName("quit_but");
        quit_but->setGeometry(QRect(40, 130, 311, 32));
        quit_but->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	background-color: blue;\n"
"	color: white;\n"
"	font-size:25px;\n"
"	font-family:Arial;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: purple;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: darkestBlue;\n"
"	color: white;\n"
"}\n"
""));
        quit_but->setIconSize(QSize(16, 16));
        gameOver = new QFrame(pauseFrame);
        gameOver->setObjectName("gameOver");
        gameOver->setGeometry(QRect(0, 0, 371, 251));
        gameOver->setStyleSheet(QString::fromUtf8("background-color:white;\n"
"border-radius: 30;\n"
""));
        gameOver->setFrameShape(QFrame::StyledPanel);
        gameOver->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(gameOver);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 351, 71));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:blue;"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);
        quit_but_2 = new QPushButton(gameOver);
        quit_but_2->setObjectName("quit_but_2");
        quit_but_2->setGeometry(QRect(20, 211, 311, 31));
        quit_but_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 15px;\n"
"	background-color: blue;\n"
"	color: white;\n"
"	font-size:25px;\n"
"	font-family:Arial;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: purple;\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: darkestBlue;\n"
"	color: white;\n"
"}\n"
""));
        quit_but_2->setIconSize(QSize(16, 16));
        label_3 = new QLabel(gameOver);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 70, 341, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(75);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:blue;"));
        label_3->setTextFormat(Qt::AutoText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);
        label_4 = new QLabel(gameOver);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 140, 181, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(50);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color:blue;"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);
        score_label = new QLabel(gameOver);
        score_label->setObjectName("score_label");
        score_label->setGeometry(QRect(170, 140, 181, 71));
        score_label->setFont(font2);
        score_label->setStyleSheet(QString::fromUtf8("color:blue;"));
        score_label->setTextFormat(Qt::AutoText);
        score_label->setScaledContents(false);
        score_label->setAlignment(Qt::AlignCenter);
        score_label->setWordWrap(false);
        quit_but_2->raise();
        label_3->raise();
        label_2->raise();
        label_4->raise();
        score_label->raise();
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        pauseFrame->raise();
        pauseButton->raise();
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
        continueButton->setText(QCoreApplication::translate("MainWindow", "CONTINUE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        quit_but->setText(QCoreApplication::translate("MainWindow", "QUIT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "GAME ", nullptr));
        quit_but_2->setText(QCoreApplication::translate("MainWindow", "QUIT", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "OVER", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Score:", nullptr));
        score_label->setText(QString());
        pauseButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
