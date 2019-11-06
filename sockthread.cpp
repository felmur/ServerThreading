/**************************************************
 * ServerThreading
 * An example of a simple TCP server based on QT
 * (c) 2019 by Felice Murolo, Salerno, Italia
 * all rights reserved
 * email: linuxboy@giove.tk
 * license: released under GPL license
 * see: https://www.gnu.org/licenses/gpl-3.0.html
 *
***************************************************/

#include "sockthread.h"

sockThread::sockThread(QTcpSocket *socket, QObject *parent)
{
    (void) parent;
    sk = socket;
}

void sockThread::run(){
    forever{
        if (goquit) break;
        bool ok = sk->waitForReadyRead(TIMEOUT);
        if (!ok) {
            qDebug() << QThread::currentThreadId() << ": TIMEOUT!";
            break;
        }
        else {
            qDebug() << QThread::currentThreadId() << ": Reading incoming data...";
            workOnData();
        }
    }
    emit(ready(sk));
}

void sockThread::workOnData(){
    QByteArray bf = sk->readAll().toLower().trimmed();
    qDebug() << QThread::currentThreadId() << ": received '" << bf.data() << "'";
    QString s = QString("I've received this: '%1'\n").arg(bf.data());
    sk->write(s.toUtf8().data(), s.length());
    if (bf == "quit") {
        qDebug() << QThread::currentThreadId() << ": QUIT RECEIVED!";
        goquit = true;
    }
}


sockThread::~sockThread()
{
    goquit = true;
    wait();
}

