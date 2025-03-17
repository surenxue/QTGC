#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serial = new QSerialPort(this);
    isOpen = false;

    // 填充串口和波特率选项
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        ui->comboBoxPort->addItem(port.portName());
    }

    ui->comboBoxBaudRate->addItem("9600");
    ui->comboBoxBaudRate->addItem("19200");
    ui->comboBoxBaudRate->addItem("38400");
    ui->comboBoxBaudRate->addItem("57600");
    ui->comboBoxBaudRate->addItem("115200");

    // 连接信号和槽
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (serial->isOpen()) {
        serial->close();
    }
    delete serial;
}

void MainWindow::on_openCloseButton_clicked()
{
    if (!isOpen) {
        // 打开串口
        serial->setPortName(ui->comboBoxPort->currentText());
        serial->setBaudRate(ui->comboBoxBaudRate->currentText().toInt());
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);

        if (serial->open(QIODevice::ReadWrite)) {
            isOpen = true;
            ui->openCloseButton->setText("关闭串口");
        } else {
            QMessageBox::critical(this, "错误", "无法打开串口！");
        }
    } else {
        // 关闭串口
        serial->close();
        isOpen = false;
        ui->openCloseButton->setText("打开串口");
    }
}

void MainWindow::on_sendButton_clicked()
{
    if (serial->isOpen()) {
        QString data = ui->lineEditSend->text();
        serial->write(data.toUtf8());
    } else {
        QMessageBox::warning(this, "警告", "串口未打开！");
    }
}

void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    ui->textEditReceive->append(data);
}
