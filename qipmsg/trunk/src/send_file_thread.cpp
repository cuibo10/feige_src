// This file is part of QIpMsg.
//
// QIpMsg is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QIpMsg is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QIpMsg.  If not, see <http://www.gnu.org/licenses/>.
//

#include "global.h"
#include "constants.h"
#include "transfer_codec.h"
#include "serve_socket.h"
#include "send_file_thread.h"

#include <QFile>
#include <QtDebug>
#include <QFileInfo>
#include <QTextCodec>
#include <QTextCodec>
#include <QDir>
#include <QDateTime>

SendFileThread::SendFileThread(int socketDescriptor, QObject *parent)
    : QThread(parent), m_socketDescriptor(socketDescriptor)
{
}

void SendFileThread::run()
{
    qDebug("SendFileThread::run: begin");

    ServeSocket serveSocket(m_socketDescriptor);

    serveSocket.startSendFile();

    qDebug("SendFileThread::run: end");
}

