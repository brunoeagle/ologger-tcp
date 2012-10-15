#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QDateTime>
#include <QHostAddress>
#include <QDebug>

TCPServer::TCPServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TCPServer)
{
    ui->setupUi(this);
    connect(&tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    ui->measuresTableWidget->verticalHeader()->setDefaultSectionSize(25);

}

TCPServer::~TCPServer()
{
    //client->close();
    delete client;
    tcpServer.close();
    delete ui;
}

void TCPServer::acceptConnection()
{
    client = tcpServer.nextPendingConnection();
    appendToLog(client->peerAddress().toString());
    connect(client, SIGNAL(readyRead()), this, SLOT(startRead()));
}

void TCPServer::startRead()
{
    char buffer[1024] = {0};
    client->read(buffer, client->bytesAvailable());
    processMeasure(buffer);

    //client->close();
}


void TCPServer::on_listenPushButton_toggled(bool checked)
{
    if (checked)
    {
        tcpServer.listen(QHostAddress::Any, ui->portLineEdit->text().toInt());
        appendToLog("Listening on port " + ui->portLineEdit->text());
    }
    else
    {
        tcpServer.close();
        appendToLog("Stopped");
    }
}

void TCPServer::processMeasure(char *bytes)
{
    QTableWidgetItem *newItem;
    ui->measuresTableWidget->insertRow(ui->measuresTableWidget->rowCount());
    unsigned int actualRow = ui->measuresTableWidget->rowCount() - 1;

    QString timeReceived(QDateTime::currentDateTime().toString("hh:mm:ss"));
    newItem = new QTableWidgetItem(tr("%1").arg(timeReceived));
    ui->measuresTableWidget->setItem(actualRow, 0, newItem);

    unsigned long id;
    id = getULong(&bytes[1]);
    //qDebug() << "ID: " + QString::number(id);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(id)));
    ui->measuresTableWidget->setItem(actualRow, 1, newItem);

    unsigned long unixTime;
    unixTime = getULong(&bytes[5]);
    //qDebug() << "Unixtime: " + QString::number(unixTime);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(unixTime)));
    ui->measuresTableWidget->setItem(actualRow, 2, newItem);

    float external_voltage;
    external_voltage = (float)bytes[9] + ((float)bytes[10] / 100);
    //qDebug() << "External Voltage: " + QString::number(external_voltage);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(external_voltage)));
    ui->measuresTableWidget->setItem(actualRow, 3, newItem);

    float supply_voltage;
    supply_voltage = (float)bytes[11] + ((float)bytes[12] / 100);
    //qDebug() << "Supply Voltage: " + QString::number(supply_voltage);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(supply_voltage)));
    ui->measuresTableWidget->setItem(actualRow, 4, newItem);

    float battery_voltage;
    battery_voltage = (float)bytes[13] + ((float)bytes[14] / 100);
    //qDebug() << "Battery Voltage: " + QString::number(battery_voltage);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(battery_voltage)));
    ui->measuresTableWidget->setItem(actualRow, 5, newItem);

    float temperature;
    temperature = (float)bytes[15] + ((float)bytes[16] / 100);
    //qDebug() << "Temperature: " + QString::number(temperature);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(temperature)));
    ui->measuresTableWidget->setItem(actualRow, 6, newItem);

    int gsm_level;
    gsm_level = (int)bytes[17];
    qDebug() << "GSM signal strength: " + QString::number(gsm_level);
    newItem = new QTableWidgetItem(tr("%1").arg(QString::number(gsm_level)));
    ui->measuresTableWidget->setItem(actualRow, 7, newItem);

    int sensorIndex = 18;
    float measure;
    while (bytes[sensorIndex] != ';')   // until the end of the packet
    {
        measure = getFloat(&bytes[sensorIndex + 1]);
        unsigned int tableIndex = ((sensorIndex - 18) / 5);
        //qDebug() << "Sensor " + QString::number(tableIndex + 1) + ": " + QString::number(measure);
        newItem = new QTableWidgetItem(tr("%1").arg(QString::number(measure)));
        ui->measuresTableWidget->setItem(actualRow, (8 + tableIndex), newItem);
        sensorIndex += 5;
    }
    ui->measuresTableWidget->scrollToBottom();

}

float TCPServer::getFloat(char *p)
{
    union
    {
        char bytes[4];
        float value;
    }uf;
    char *pChar = p;
    uf.bytes[0] = *pChar++;
    uf.bytes[1] = *pChar++;
    uf.bytes[2] = *pChar++;
    uf.bytes[3] = *pChar;
    return uf.value;
}

unsigned long TCPServer::getULong(char *p)
{
    char *pChar = p + 3;
    static union
    {
        unsigned long ul;
        char array[4];
    }pToUL;
    pToUL.array[0] = *pChar--;
    pToUL.array[1] = *pChar--;
    pToUL.array[2] = *pChar--;
    pToUL.array[3] = *pChar;
    return pToUL.ul;
}

void TCPServer::appendToLog(QString s)
{
    QString log(QDateTime::currentDateTime().toString("hh:mm:ss"));
    log.append(" " + s);
    ui->logTextEdit->appendPlainText(log);
}
