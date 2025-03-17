#include "mainwindow.h"
#include "ui_mainwindow.h"

//使用信息提示框添加头文件//用法1 information原型
//参数  1：父控件指针   2：标题名称（窗口左上角） 3：信息提示框内容  4：信息提示框（有多少按钮）,一般默认OK  5.指定按下Enter键时使用的按钮
#include<QMessageBox>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //information原型
   //参数  1：父控件指针   2：标题名称（窗口左上角） 3：信息提示框内容  4：信息提示框（有多少按钮）,一般默认OK  5.指定按下Enter键时使用的按钮
    QMessageBox::information(NULL,"information","是否退出此系统",QMessageBox::Yes|QMessageBox::No|QMessageBox::Help,QMessageBox::No);
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::critical(NULL,"critical","文件复制出错，请重新检查",QMessageBox::Yes|QMessageBox::No|QMessageBox::Help,QMessageBox::No);
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::warning(NULL,"warning","删除此文件，对系统造成危害",QMessageBox::Yes|QMessageBox::No|QMessageBox::Help,QMessageBox::No);
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::question(NULL,"question","你是人？",QMessageBox::Yes|QMessageBox::No|QMessageBox::Help,QMessageBox::Yes);
}

void MainWindow::on_pushButton_5_clicked()
{
    QMessageBox::about(NULL,"about","默认提示消息框");
}

void MainWindow::on_pushButton_6BUtton_clicked()
{
    // 创建消息框
    QMessageBox messageBox(QMessageBox::NoIcon, "登录", "用户名是否成功？", QMessageBox::Yes | QMessageBox::No, this);

//    // 设置按钮文本（可选）
//    messageBox.setButtonText(QMessageBox::Yes, "是");
//    messageBox.setButtonText(QMessageBox::No, "否");

    // 显示消息框并获取用户选择
    int reply = messageBox.exec();

    // 处理用户选择
    if (reply == QMessageBox::Yes) {
        qDebug() << "用户点击了“是”";
        // 将 label_6 的背景色变为蓝色，同时保留其他样式
        ui->label_6->setStyleSheet(
            "QLabel {"
            "   background-color: blue;"  // 修改背景色为蓝色
            "   border-radius: 20px;"    // 保留圆角半径
            "   width: 40px;"            // 保留宽度
            "   height: 40px;"          // 保留高度
            "}"
            );
    } else if (reply == QMessageBox::No) {
        qDebug() << "用户点击了“否”";
        // 将 label_6 的背景色变为绿色，同时保留其他样式
        ui->label_6->setStyleSheet(
            "QLabel {"
            "   background-color: green;"  // 修改背景色为绿色
            "   border-radius: 20px;"     // 保留圆角半径
            "   width: 40px;"             // 保留宽度
            "   height: 40px;"            // 保留高度
            "}"
            );
    }
}
