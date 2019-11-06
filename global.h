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
#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>

#define RCU(x) reinterpret_cast<uint>(x)
#define RCU64(x) reinterpret_cast<quint64>(x)

extern QString prgname;
extern QString version;
extern QString author;
extern QString copyright;
extern QString license;
extern QString email;
extern QString location;
extern QString org;

extern QString server_message;
extern QString servername;
extern quint16 SERVER_PORT;
extern int TIMEOUT;

class global
{
public:
    global();
};

#endif // GLOBAL_H
