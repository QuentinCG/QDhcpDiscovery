/*
 * \brief 'Static class' to check if a DHCP server is available or not
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 2 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 1.0
 */

#include "QDhcpDiscovery.h"

namespace
{

const quint8 DHCP_SERVER_PORT = 67;
const quint8 DHCP_CLIENT_PORT = 68;
const quint8 MINIMUM_SIZEOF_DHCP_FRAME = 236; //! Frame size without options

}

QDhcpDiscovery::QDhcpDiscovery()
{
}

QByteArray QDhcpDiscovery::getDiscoveryRequestFrame()
{
    QByteArray discoveryFrame;
    // Fill discovery frame with necessary bytes

    // op
    const quint8 op = 0x01;
    discoveryFrame.push_back(char(op));

    // htype
    const quint8 htype = 0x01;
    discoveryFrame.push_back(char(htype));

    // hlen
    const quint8 hlen = 0x06;
    discoveryFrame.push_back(char(hlen));

    // hops
    const quint8 hops = 0x00;
    discoveryFrame.push_back(char(hops));

    // xid

    const std::list<quint8> xid = {0xfb, 0x4a, 0x62, 0x30};
    for(const quint8& byte : xid)
    {
        discoveryFrame.push_back(byte);
    }

    // secs
    const std::list<quint8> secs = {0x00, 0x00};
    for(const quint8& byte : secs)
    {
        discoveryFrame.push_back(byte);
    }

    // flags
    const std::list<quint8> flags = {0x80, 0x00};
    for(const quint8& byte : flags)
    {
        discoveryFrame.push_back(byte);
    }

    // ciaddr
    const std::list<quint8> ciaddr = {0x00, 0x00, 0x00, 0x00};
    for(const quint8& byte : ciaddr)
    {
        discoveryFrame.push_back(byte);
    }

    // yiaddr
    const std::list<quint8> yiaddr = {0x00, 0x00, 0x00, 0x00};
    for(const quint8& byte : yiaddr)
    {
        discoveryFrame.push_back(byte);
    }

    // siaddr
    const std::list<quint8> siaddr = {0x00, 0x00, 0x00, 0x00};
    for(const quint8& byte : siaddr)
    {
        discoveryFrame.push_back(byte);
    }

    // giaddr
    const std::list<quint8> giaddr = {0x00, 0x00, 0x00, 0x00};
    for(const quint8& byte : giaddr)
    {
        discoveryFrame.push_back(byte);
    }

    // chaddr
    const std::list<quint8> chaddr =
    {
        0x94, 0x31, 0xe3, 0xa0, 0xad, 0x9d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    for(const quint8& byte : chaddr)
    {
        discoveryFrame.push_back(byte);
    }

    // sname
    const std::list<quint8> sname =
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    for(const quint8& byte : sname)
    {
        discoveryFrame.push_back(byte);
    }

    // file
    const std::list<quint8> file =
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    for(const quint8& byte : file)
    {
        discoveryFrame.push_back(byte);
    }

    // options + end (magic cookie)
    const std::list<quint8> options = {0x63, 0x82, 0x53, 0x63, 0x35, 0x01, 0x01, 0xff};
    for(const quint8& byte : options)
    {
        discoveryFrame.push_back(byte);
    }

    return discoveryFrame;
}

bool QDhcpDiscovery::isDiscoveryResponseValid(const QByteArray& response, QString& error)
{
    if (response.size() < MINIMUM_SIZEOF_DHCP_FRAME)
    {
        error = QObject::tr("Invalid DHCP server: Invalid frame size returned by the server");
        return false;
    }

    if (response.at(0) != 0x02)
    {
        error = QObject::tr("Invalid DHCP server: 'op' value from response frame is not of type BOOTREPLY.");
        return false;
    }

    return true;
}

bool QDhcpDiscovery::isAvailable(const QHostAddress& ipInterface, const quint16& timoutInMs, QString& error)
{
    QByteArray discoveryFrame = getDiscoveryRequestFrame();
    QUdpSocket udpSocket;

    if (ipInterface.isNull())
    {
        error = QObject::tr("Invalid %1 interface").arg(ipInterface.toString());
        return false;
    }

    if (!udpSocket.bind(ipInterface, DHCP_CLIENT_PORT))
    {
        error = QObject::tr("No DHCP server found in %1 interface: Impossible to bind port %2")
                .arg(ipInterface.toString()).arg(QString::number(DHCP_CLIENT_PORT));
        return false;
    }

    // --- Send discovery request ---
    const qint64 writtenBytes = udpSocket.writeDatagram(discoveryFrame.data(), discoveryFrame.size(),
                                          QHostAddress::Broadcast, DHCP_SERVER_PORT);
    if (writtenBytes != discoveryFrame.size())
    {
        error = QObject::tr("Discovery frame request not sent properly to %1 interface: Only %2 bytes sent over %3")
               .arg(ipInterface.toString()).arg(writtenBytes).arg(discoveryFrame.size());
        return false;
    }

    // --- Wait discovery response ---
    QHostAddress senderAddress;
    quint16 senderPort;
    quint16 retries = 0;
    do
    {
        QElapsedTimer timeoutCounter;
        timeoutCounter.start();
        while (timeoutCounter.elapsed() < 250)
        {
            if (udpSocket.hasPendingDatagrams())
            {
                udpSocket.readDatagram(discoveryFrame.data(), discoveryFrame.size(),
                                       &senderAddress, &senderPort);

                if (senderPort == DHCP_SERVER_PORT)
                {
                    return isDiscoveryResponseValid(discoveryFrame, error);
                }
            }

            QCoreApplication::processEvents(QEventLoop::AllEvents);
        }
    }
    while (retries++ < timoutInMs / 250);

    error = QObject::tr("No DHCP server found in %1 interface: Timeout").arg(ipInterface.toString());
    return false;
}
