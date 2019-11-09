QT += core
QT += network

QT -= gui

DEFINES += QDHCPDISCOVERY_LIBRARY

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

CONFIG(release, debug|release): TARGET = QDhcpDiscovery
else:CONFIG(debug, debug|release): TARGET = QDhcpDiscoveryd

TEMPLATE = lib

SOURCES += \
           src/QDhcpDiscovery.cpp

HEADERS += \
           include/QDhcpDiscovery.h \
           include/QDhcpDiscovery_global.h

INCLUDEPATH += \
           include/

# -- Test coverage (if requested only) --
TEST_COVERAGE {
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov
}
