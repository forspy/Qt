#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMovie>

#include <QProgressBar>//进度条

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->statusBar->showMessage("状态栏");
    ui->statusBar->showMessage("状态栏",5000);//显示5秒

    //状态栏添加widget
    QProgressBar* pStateProgressBar=new QProgressBar(this);
    //状态栏添加widget 添加widget定义可以使用右键单击类，选择refactor---选择头文件  [重要]
    ui->statusBar->addPermanentWidget(pStateProgressBar);//在状态栏中添加widget
    pStateProgressBar->setValue(10);
    pStateProgressBar->setAlignment(Qt::AlignCenter);
    //当界面可以实现而忘了代码的接口时可以新建一个widget，找到该widget的类，查看方法[重要] 进入setui---找到progressbar对象指针 查看设置

    //[重要]可以把以前用的资源文件和原图片添加到新的项目
    //方法：
    //.qrc资源路径文件和资源文件复制黏贴
    //选择工程文件夹--添加现有文件 --选择.qrc文件

    //照片放在scrollArea中
    //1.把先放在label中 //能不能把照片直接放入scrollArea中？待解决 不能 scrollArea只支持setWidget，所以要把照片先放入Label中
    QLabel* pImageLabel=new QLabel(this);
    pImageLabel->setPixmap(QPixmap(":/image/picture/pat.bmp"));
    //2.把label放入scrollArea中
    ui->scrollArea->setWidget(pImageLabel);
    //放动图
    //1.把gif放入label中
    QMovie *pMove=new QMovie(":/image/picture/mua.gif");//创建QMovie空间,详见帮助文档
    QLabel* labelGif=new QLabel(this);//这种方法创建的label会在默认位置显示
    labelGif->setMovie(pMove);//拿来直接用
    //2.把label放入scrollArea_2中  注意ui界面上创建的都是ui-> ,自己new的可以直接用 [重要]
    ui->scrollArea_2->setWidget(labelGif);
    pMove->start();



}

MainWindow::~MainWindow()
{
    delete ui;
}
