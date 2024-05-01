//
// Created by Stas Maslakov on 26.04.2024.
//

#ifndef SNAKE_GAME_MENUWINDOW_H
#define SNAKE_GAME_MENUWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MenuWindow; }
QT_END_NAMESPACE

class MenuWindow : public QWidget {
Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = nullptr);

    ~MenuWindow() override;

private:
    Ui::MenuWindow *ui;
};


#endif //SNAKE_GAME_MENUWINDOW_H
