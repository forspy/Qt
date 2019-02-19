#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    deviceState(false)
{
    ui->setupUi(this);
    ui->pushButton_2->setIcon(QIcon(":/image/picture/pat.bmp"));//选中resourec里面的图片右键copypath(不推荐)
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
int count;
void MainWindow::on_checkBox_clicked()
{
    if(count<=2&&ui->checkBox->isChecked()==true)
        count++;
    else if(ui->checkBox->isChecked()==false)
        count--;
    else
    {
        ui->checkBox->setChecked(false);
    }
}

void MainWindow::on_checkBox_2_clicked()
{
    if(count<=2&&ui->checkBox_2->isChecked()==true)
        count++;
    else if(ui->checkBox_2->isChecked()==false)
        count--;
    else {
        ui->checkBox_2->setChecked(false);
    }
}

void MainWindow::on_checkBox_3_clicked()
{
    if(count<=2&&ui->checkBox_3->isChecked()==true)
        count++;
    else if(ui->checkBox_3->isChecked()==false)
        count--;
    else {
        ui->checkBox_3->setChecked(false);
    }
}

void MainWindow::on_checkBox_4_clicked()
{
    if(count<=2&&ui->checkBox_4->isChecked()==true)
        count++;
    else if(ui->checkBox_4->isChecked()==false)
        count--;
    else {
        ui->checkBox_4->setChecked(false);
    }
}

