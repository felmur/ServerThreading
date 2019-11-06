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

    QMap<QString, uint> map;
    map.insert("list",1);
    map.insert("text",2);
    map.insert("help",8);
    map.insert("quit",9);

    switch(map[bf.data()]) {

    case 1: // list
        sk->write("Simulates a ls -l\n");
        sk->write("-rwxr-xr-x  1 felice felice  17272  7 apr  2019  serial\n"
                  "-rw-r--r--  1 felice felice   2869  7 apr  2019  serial.c\n"
                  "-rw-r--r--  1 felice felice   1204 16 apr  2018  term.py\n\n");
        break;
    case 2: // text
        sk->write("Simulates a cat of a textfile\n");
        sk->write("The quick brown fox jumps over the lazy dog\n"
                  "The quick brown fox jumps over the lazy dog\n"
                  "The quick brown fox jumps over the lazy dog\n"
                  "The quick brown fox jumps over the lazy dog\n\n");
        break;

    case 8:
        sk->write("Type 'list' to simulate a ls -l\n"
                  "Type 'text' to simulate a cat of a textfile\n\n");
        break;

    case 9:
        sk->write("QUIT!\n");
        goquit=true;
        break;

    }
}

sockThread::~sockThread()
{
    goquit = true;
    wait();
}

