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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *pauseFrame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *continueButton;
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
        pauseFrame->setGeometry(QRect(400, 100, 391, 261));
        pauseFrame->setFrameShape(QFrame::StyledPanel);
        pauseFrame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(pauseFrame);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(pauseFrame);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton = new QPushButton(pauseFrame);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        continueButton = new QPushButton(pauseFrame);
        continueButton->setObjectName("continueButton");

        verticalLayout->addWidget(continueButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(16, 15, 44, 45));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pauseButton->sizePolicy().hasHeightForWidth());
        pauseButton->setSizePolicy(sizePolicy);
        pauseButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(/Users/sagot/Documents/2024-04-30_15.14.11-removebg-preview 2.png);\n"
"    background-color: white;\n"
"    border-radius: 20px;\n"
"    border-width: 5px;  \n"
"    border-image-repeat: stretch; \n"
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
        label->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        continueButton->setText(QCoreApplication::translate("MainWindow", "continue", nullptr));
        pauseButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
