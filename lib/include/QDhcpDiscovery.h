/*
 * \brief 'Static class' to check if a DHCP server is available or not
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 2 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 1.0
 */

#ifndef QDHCPDISCOVERY_H
#define QDHCPDISCOVERY_H

#include <QObject>
#include <QtNetwork>

class QDhcpDiscovery
{

public:
    QDhcpDiscovery();

    /*!
   * \brief Try to find a dhcp server
   *
   * \param[in] ipInterface Interface to search the dhcp server
   * \param[in] timoutInMs Max time (in ms) searching the dhcp server
   * \param[out] error More information about why no dhcp server found
   *
   * \return Found a dhcp server?
   *
   * \details Blocking function but allowing Qt events to execute during this function (QEventLoop::AllEvents)
   */
  static bool isAvailable(const QHostAddress& ipInterface, const quint16& timoutInMs, QString& error);

private:
  static QByteArray getDiscoveryRequestFrame();
  static bool isDiscoveryResponseValid(const QByteArray& response, QString& error);

};

#endif // QDHCPDISCOVERY_H
