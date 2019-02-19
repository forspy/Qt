#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>//用于槽函数on_actionSave_triggered()的触发
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

    void on_actionSave_triggered();

private:
    Ui::MainWindow *ui;
    bool deviceState;//设备连接状态
};

#endif // MAINWINDOW_H
