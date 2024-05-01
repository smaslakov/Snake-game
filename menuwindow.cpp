//
// Created by Stas Maslakov on 26.04.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MenuWindow.h" resolved

#include "menuwindow.h"
#include "ui_MenuWindow.h"


MenuWindow::MenuWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MenuWindow) {
    ui->setupUi(this);
}

MenuWindow::~MenuWindow() {
    delete ui;
}
