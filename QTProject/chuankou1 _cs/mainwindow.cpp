#include "mainwindow.h"
#include "ui_mainwindow.h"

//使用信息提示框添加头文件//用法1 information原型
#include<QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QserialPortInfo> list = QserialPortInfo::availablePorts();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 配置串口数据并打开
void MainWindow::on_Button_opensereial_clicked()
{

}
