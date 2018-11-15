#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <iostream>
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	Dialog dialog;
	dialog.setModal(true);
	dialog.exec();
}
