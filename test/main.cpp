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

#include <QDhcpDiscovery.h>

TEST_CASE("Create and use instance")
{
    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(dhcpDiscover.isAvailable(QHostAddress("127.0.01"), 10, error));
    REQUIRE_FALSE(error.isEmpty());
}

TEST_CASE("Use function without instance")
{
    QDhcpDiscovery dhcpDiscover;
    QString error;

    REQUIRE_FALSE(QDhcpDiscovery::isAvailable(QHostAddress("127.0.01"), 10, error));
    REQUIRE_FALSE(error.isEmpty());
}

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << QString("Launching test using catch version %1.%2 - %3").arg(CATCH_VERSION_MAJOR).arg(CATCH_VERSION_MINOR).arg(CATCH_VERSION_PATCH);

    int result = Catch::Session().run(argc, argv);
    return result;
}
