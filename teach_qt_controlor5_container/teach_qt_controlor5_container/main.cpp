#include "mainwindow.h"
#include <QApplication>
//#include<QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QThread::sleep(5);//睡5秒，单个线程阻塞还是会阻塞整个进程？
    return a.exec();
}
