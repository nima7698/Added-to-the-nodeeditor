#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loodText();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_findb_clicked()
{
    QString search = ui->lineEdit->text();
    ui->textEdit->find(search,QTextDocument::FindWholeWords);

}
void MainWindow::loodText(){
    QFile inputFile("D:\\pc\\dow\\test.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    QPalette pl = palette();
    pl.setColor(QPalette::Base,Qt::gray);
    setPalette(pl);

    ui->textEdit->setPlainText(line);
    QTextCursor cursar = ui->textEdit->textCursor();
    cursar.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor);




}
