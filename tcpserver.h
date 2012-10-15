#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

namespace Ui {
class TCPServer;
}

class TCPServer : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TCPServer(QWidget *parent = 0);
    ~TCPServer();
    void appendToLog(QString s);
    void processMeasure(char *bytes);
    unsigned long getULong(char *p);
    float getFloat(char *p);
    
private slots:

    void on_listenPushButton_toggled(bool checked);
    void acceptConnection();
    void startRead();

private:
    Ui::TCPServer *ui;
    QTcpServer tcpServer;
    QTcpSocket *client;

};

#endif // TCPSERVER_H
