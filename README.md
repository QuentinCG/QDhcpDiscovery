# Qt DHCP Server Discovery (Qt4+/Qt5+)
[![Build Status](https://travis-ci.org/QuentinCG/QDhcpDiscovery.svg?branch=master)](https://travis-ci.org/QuentinCG/QDhcpDiscovery) [![codecov](https://codecov.io/gh/QuentinCG/QDhcpDiscovery/branch/master/graph/badge.svg)](https://codecov.io/gh/QuentinCG/QDhcpDiscovery) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/bb06e946714845fa9ae7d224f986e638)](https://www.codacy.com/manual/QuentinCG/QDhcpDiscovery?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=QuentinCG/QDhcpDiscovery&amp;utm_campaign=Badge_Grade) [![License: MIT](https://img.shields.io/badge/License-MIT-brightgreen.svg)](https://github.com/QuentinCG/QDhcpDiscovery/blob/master/LICENSE) [![Donate](https://img.shields.io/badge/Donate-PayPal-blue.svg)](https://paypal.me/QuentinCG)
 
## What is it

This library (with a basic example) is designed to check if a DHCP server is launched in a provided ip interface.

This class works with any Qt4 and Qt5 version (only required libraries: QtNetwork and QtCore)

<img src="dhcp.jpg" width="300">

## How to install

1) Download this repository

2) Open the <a href="https://github.com/QuentinCG/QDhcpDiscovery/blob/master/QDhcpDiscovery.pro">QDhcpDiscovery.pro</a> project with <a href="https://download.qt.io/archive/qt/">QtCreator</a> (or add the QDhcpDiscovery library into your project like done in <a href="https://github.com/QuentinCG/QDhcpDiscovery/blob/master/example/example.pro">example project</a>)

3) Build and launch the project to see the result in the command line (`example.exe 127.0.0.1`, the library will also be generated)

## License

This project is under MIT license. This means you can use it as you want (just don't delete the library header).

## Contribute

If you want to add more examples or improve the library, just create a pull request with proper commit message and right wrapping.
