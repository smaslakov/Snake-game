
#include "leaderboardwindow.h"
#include "ui_LeaderBoardWindow.h"
#include "mainwindow.h"
#include <QTableWidgetItem>
LeaderBoardWindow::LeaderBoardWindow(int col,QString n,QWidget *parent) :
        QWidget(parent), ui(new Ui::LeaderBoardWindow) {
    name = n;
    colorIndex = col;
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/sagot/Documents/Snake-game/usersdb.db");
    if(db.open()){
        model = new QSqlTableModel(this,db);
        model->setTable("LeaderBoard");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->setColumnWidth(0, 200); // Optional: Set the width of the first column
        ui->tableView->setColumnWidth(1, 150); // Optional: Set the width of the second column
        ui->tableView->horizontalHeader()->setStretchLastSection(true);
        //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        addToTable();
    }
    connect(ui->backToMenuBut,&QPushButton::clicked,this,&LeaderBoardWindow::backToMenu);
}
void LeaderBoardWindow::backToMenu() {
    menuWindow = new MenuWindow(colorIndex,name);
    this->close();
    menuWindow->show();
}

void LeaderBoardWindow::addToTable() {
    //int score = mainwindow->snake->getLength();
    //QString name = mainwindow->snake->getName();
    int score = 450;
    QString name = "Balda";
    model->insertRow(model->rowCount());
    QModelIndex index = model->index(model->rowCount() - 1, 0);
    model->setData(index, name, Qt::DisplayRole); // Устанавливаем имя в первый столбец

    index = model->index(model->rowCount() - 1, 1); // Получаем индекс ячейки второго столбца
    model->setData(index, score, Qt::DisplayRole); // Устанавливаем счет во второй столбец

    model->submitAll(); // Подтверждаем изменения в базе данных
}
LeaderBoardWindow::~LeaderBoardWindow() {
    delete ui;
}
