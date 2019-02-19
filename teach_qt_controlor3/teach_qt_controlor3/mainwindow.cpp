#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    deviceState(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   if(!deviceState)//
   {
       ui->pushButton->setText("断开");
       deviceState=true;
   }
   else {
       ui->pushButton->setText("关闭");
       deviceState=false;
   }
}

void MainWindow::on_actionSave_triggered()
{
    qDebug()<<"action open"<<"triggered";//字符串流入
}
