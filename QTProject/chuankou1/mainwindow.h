#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>  // 提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo>  // 提供系统中存在的串口信息
#include <QDebug>          //debug用


QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6BUtton_clicked();


private:
    Ui::MainWindow *ui;
    QSerialPort  *serial; //定义串口对象
};
#endif // MAINWINDOW_H
