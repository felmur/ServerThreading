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
#include "global.h"

QString prgname="ServerThreading";
QString version="1.0a";
QString author="Felice Murolo";
QString copyright="(c) 2019 - all rights reserved";
QString license="LGPL 3.0";
QString email="linuxboy@giove.tk";
QString location="Salerno, Italia";
QString org="Giove.tk";

QString servername="ST_Server";
QString server_message="\nWelcome to "+servername+" v"+version+"\n\n";
quint16 SERVER_PORT = 60006;
int TIMEOUT = 30000;

global::global()
{

}
