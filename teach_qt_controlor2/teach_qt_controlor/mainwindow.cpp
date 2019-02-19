#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("按键一");//这样也可以设置pushButton的按键名
    //ui是一个MainWindow类的指针,MainWindow类公有继承于Ui_MainWindow类，Ui_MainWindow类下有pushButton的类指针，
    //pushButton类公有继承父控件QAbstractButton类，QAbstractButton类里面有setText()方法
    //----pushbutton2关联信号与槽
    //connect(this,SIGNAL(pushButton2Signal()),
           // this,SLOT(pushButton2Slot()));//配合emit
    connect(ui->pushButton_2,SIGNAL(clicked()),
            this,SLOT(pushButton2Slot()));//connect(发送者对象指针，信号，接收者对象指针，槽函数) 所有控件活动都是基于主窗口，只有接收者为主窗口才能执行槽函数
    //关闭按钮
    connect(ui->pushButton_3,&QPushButton::clicked,/*回调函数*/
            this,&QMainWindow::close/*qt自身槽函数*/);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText("按钮一已经按下");
}

void MainWindow::pushButton2Slot()
{
    ui->lineEdit_2->setText("按钮二已经按下");
}

void MainWindow::on_pushButton_2_clicked()
{
    //emit pushButton2Signal();//emit和上面的配合，或者不设槽函数直接使用上面的connect(),需要去掉click()功能
}
