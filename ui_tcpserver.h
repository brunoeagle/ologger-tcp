/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created: Fri 12. Oct 16:48:04 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPServer
{
public:
    QWidget *centralWidget;
    QPushButton *listenPushButton;
    QLineEdit *portLineEdit;
    QLabel *labelPort;
    QPlainTextEdit *logTextEdit;
    QLabel *labelMeasures;
    QLabel *labelLog;
    QTableWidget *measuresTableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TCPServer)
    {
        if (TCPServer->objectName().isEmpty())
            TCPServer->setObjectName(QString::fromUtf8("TCPServer"));
        TCPServer->resize(640, 480);
        centralWidget = new QWidget(TCPServer);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listenPushButton = new QPushButton(centralWidget);
        listenPushButton->setObjectName(QString::fromUtf8("listenPushButton"));
        listenPushButton->setGeometry(QRect(10, 10, 461, 41));
        listenPushButton->setCheckable(true);
        listenPushButton->setAutoDefault(false);
        listenPushButton->setDefault(false);
        listenPushButton->setFlat(false);
        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setGeometry(QRect(530, 15, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Lucida Console"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        portLineEdit->setFont(font);
        labelPort = new QLabel(centralWidget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        labelPort->setGeometry(QRect(480, 20, 41, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Console"));
        font1.setPointSize(11);
        labelPort->setFont(font1);
        logTextEdit = new QPlainTextEdit(centralWidget);
        logTextEdit->setObjectName(QString::fromUtf8("logTextEdit"));
        logTextEdit->setGeometry(QRect(10, 350, 621, 71));
        labelMeasures = new QLabel(centralWidget);
        labelMeasures->setObjectName(QString::fromUtf8("labelMeasures"));
        labelMeasures->setGeometry(QRect(20, 70, 91, 21));
        labelMeasures->setFont(font1);
        labelLog = new QLabel(centralWidget);
        labelLog->setObjectName(QString::fromUtf8("labelLog"));
        labelLog->setGeometry(QRect(20, 330, 91, 21));
        labelLog->setFont(font1);
        measuresTableWidget = new QTableWidget(centralWidget);
        if (measuresTableWidget->columnCount() < 11)
            measuresTableWidget->setColumnCount(11);
        measuresTableWidget->setObjectName(QString::fromUtf8("measuresTableWidget"));
        measuresTableWidget->setGeometry(QRect(10, 90, 621, 221));
        measuresTableWidget->setAlternatingRowColors(true);
        measuresTableWidget->setColumnCount(11);
        measuresTableWidget->horizontalHeader()->setVisible(true);
        measuresTableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        measuresTableWidget->horizontalHeader()->setDefaultSectionSize(56);
        measuresTableWidget->horizontalHeader()->setMinimumSectionSize(10);
        measuresTableWidget->horizontalHeader()->setStretchLastSection(false);
        TCPServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TCPServer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        TCPServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TCPServer);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TCPServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TCPServer);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TCPServer->setStatusBar(statusBar);

        retranslateUi(TCPServer);

        QMetaObject::connectSlotsByName(TCPServer);
    } // setupUi

    void retranslateUi(QMainWindow *TCPServer)
    {
        TCPServer->setWindowTitle(QApplication::translate("TCPServer", "TCPServer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        TCPServer->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        listenPushButton->setText(QApplication::translate("TCPServer", "Listen", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("TCPServer", "Port:", 0, QApplication::UnicodeUTF8));
        labelMeasures->setText(QApplication::translate("TCPServer", "Measures:", 0, QApplication::UnicodeUTF8));
        labelLog->setText(QApplication::translate("TCPServer", "Log:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TCPServer: public Ui_TCPServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
