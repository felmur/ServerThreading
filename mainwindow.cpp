/**************************************************
 * ServerThreading
 * An example of a simple TCP server based on QT
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * all rights reserved
 * email: linuxboy@giove.tk
 * license: released under LGPL license
 * see: https://www.gnu.org/licenses/lgpl-3.0.html
 *
***************************************************/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srv = new QTcpServer(this);
    srv->listen(QHostAddress::AnyIPv4, SERVER_PORT);
    connect(srv,SIGNAL(newConnection()),this,SLOT(srv_newConnection()));

}

void MainWindow::srv_newConnection(){
    qDebug("New Connection Incoming");
    sk = srv->nextPendingConnection();
    sk->write(server_message.toUtf8().data(),server_message.length());
    qDebug("Incoming address: %s", sk->peerAddress().toString().toUtf8().data());
    st = new sockThread(sk, this);
    connect(st,SIGNAL(ready(QTcpSocket *)),this,SLOT(socketReady(QTcpSocket *)));
    st->start();
}

void MainWindow::socketReady(QTcpSocket *socket){
    qDebug("Ok, socket thread is ready");
    socket->flush();
    socket->close();
}


MainWindow::~MainWindow()
{
    delete ui;
}

