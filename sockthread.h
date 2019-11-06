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
#ifndef SOCKTHREAD_H
#define SOCKTHREAD_H

#include "global.h"
#include <QThread>
#include <QTcpSocket>
#include <QMap>

class sockThread : public QThread
{
    Q_OBJECT


public:
    sockThread(QTcpSocket *socket, QObject *parent = nullptr);
    ~sockThread();

signals:
    void ready(QTcpSocket *);

private:
    QTcpSocket *sk;
    void workOnData();
    bool goquit = false;

protected:
    void run() override;

};

#endif // SOCKTHREAD_H
