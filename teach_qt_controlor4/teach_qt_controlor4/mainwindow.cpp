#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) ://注意这是一个构造函数
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap mImage=QPixmap(":/image/picture/pat.bmp");//设置图片路径
    ui->labelImage->setPixmap(mImage);//加载图片
    ui->labelImage->resize(320,240);//设置图片大小
    ui->labelImage->setScaledContents(true);//图片自适应大小

    QMovie *pMove=new QMovie(":/image/picture/mua.gif");//创建QMovie空间,详见帮助文档
    ui->labelGif->setMovie(pMove);
    ui->labelGif->setFixedSize(320,240);
    pMove->start();

    //计时器
    QTime time=QTime::currentTime();
    //QDateTime::currentDateTime();//另外的时间获取方式
    //QDateTime::currentDateTimeUtc();//UTC格林威治时间
    qDebug()<<time;//debug打印时间
    //显示时间 需要在QLCDNumber类的digitCount 按s输出里面设置8位以上，按毫秒输出设置15位以上
    ui->lcdNumber_2->display(time.toString("hh:mm:ss"));//帮助文档查看QTime

    //定时器设置
    timer.start(1000);//1秒钟一次
    //让定时器跑起来 使用connect让信号和槽函数绑定
    connect(&timer,&QTimer::timeout,
            this,&MainWindow::timeoutSlot);

    //ui->progressBar->setValue(10);//设置百分比
    //例子：文件传输
    int total=100;
    int current=12;
    ui->progressBar->setMaximum(total);
    ui->progressBar->setValue(current);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()//与Qtextedit 配合形成输入输出
{
    QString textStr=ui->textEdit_2->toHtml();
    QString textPlainStr=ui->textEdit_2->toPlainText();

    ui->textBrowser->setText(textStr);
}

void MainWindow::timeoutSlot()
{
    //qDebug()<<"timeout"<<QTime::currentTime();//尝试在debug区先看看
    ui->lcdNumber_2->display(QTime::currentTime().toString("hh:mm:ss"));
}
