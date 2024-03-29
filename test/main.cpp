/*
 * \brief Test the Dhcp discovery library
 *
 * \author Quentin Comte-Gaz <quentin@comte-gaz.com>
 * \date 9 November 2019
 * \license MIT License (contact me if too restrictive)
 * \copyright Copyright (c) 2019 Quentin Comte-Gaz
 * \version 2.0
 */
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <QCoreApplication>
#include <QDebug>
#include <QUdpSocket>

#include <QDhcpDiscovery.h>

TEST_CASE("Invalid address")
{
    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(dhcpDiscover.isAvailable(QHostAddress(), 10, error));
    REQUIRE_FALSE(error.isEmpty());
    qDebug() << "Returned error: " << error;
    REQUIRE(error.contains("Invalid"));
    REQUIRE(error.contains("interface"));
}

TEST_CASE("Create and use instance with no DHCP server")
{
    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(dhcpDiscover.isAvailable(QHostAddress("127.0.0.1"), 10, error));
    REQUIRE_FALSE(error.isEmpty());
    qDebug() << "Returned error: " << error;
    REQUIRE(error.contains("No DHCP server found"));
}

TEST_CASE("Use function without instance with no DHCP server")
{
    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(QDhcpDiscovery::isAvailable(QHostAddress("127.0.0.1"), 10, error));
    REQUIRE_FALSE(error.isEmpty());
    qDebug() << "Returned error: " << error;
    REQUIRE(error.contains("No DHCP server found"));
}

TEST_CASE("Failed receive response from invalid dhcp server")
{
    QUdpSocket *udpServer = new QUdpSocket();
    udpServer->bind(QHostAddress(QHostAddress::SpecialAddress::Broadcast), 67);

    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(QDhcpDiscovery::isAvailable(QHostAddress(QHostAddress::SpecialAddress::Broadcast), 1000, error));
    REQUIRE_FALSE(error.isEmpty());
    qDebug() << "Returned error: " << error;
    REQUIRE(error.contains("No DHCP server found"));

    udpServer->close();
    delete(udpServer);
}

TEST_CASE("Port already bind")
{
    QUdpSocket *udpServer = new QUdpSocket();
    udpServer->bind(QHostAddress("127.0.0.1"), 68);

    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(QDhcpDiscovery::isAvailable(QHostAddress("127.0.0.1"), 1000, error));
    REQUIRE_FALSE(error.isEmpty());
    qDebug() << "Returned error: " << error;
    REQUIRE(error.contains("Impossible to bind port 68"));

    udpServer->close();
    delete(udpServer);
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << QString("Launching test using catch version %1.%2 - %3").arg(CATCH_VERSION_MAJOR).arg(CATCH_VERSION_MINOR).arg(CATCH_VERSION_PATCH);

    int result = Catch::Session().run(argc, argv);
    return result;
}
