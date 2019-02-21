#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMovie>
#include<QTime>//获取时间
#include<QDateTime>
#include<QtDebug>

#include<QTimer>//定时器
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void timeoutSlot();

private:
    Ui::MainWindow *ui;
    QTimer timer;
};

#endif // MAINWINDOW_H
