/*
 * \brief Example on how to check if a DHCP Server is available
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 2 July 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 1.0
 */

#include <QDebug>

#include <QDhcpDiscovery.h>

int main(int argc, char *argv[])
{
  // ---- Get ip interface to check ----
  QString ipInterfaceToCheck;
  if (argc >= 2)
  {
      ipInterfaceToCheck = QString(argv[1]);
  }
  else
  {
      qDebug() << "Please provide the ip interface to check and press enter:";
      ipInterfaceToCheck = QTextStream(stdin).readLine();
  }

  // ---- Check if available dhcp server ----
  QString moreInfo;
  if (QDhcpDiscovery::isAvailable(QHostAddress(ipInterfaceToCheck), 500, moreInfo))
  {
    qDebug() << "Dhcp server found on ip interface" << ipInterfaceToCheck;
    return 0;
  }
  else
  {
    qWarning() << "No dhcp server found on ip interface" << ipInterfaceToCheck << ":" << moreInfo;
    return 1;
  }
}
