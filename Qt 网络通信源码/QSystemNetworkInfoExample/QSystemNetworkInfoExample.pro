TEMPLATE = app
TARGET = QSystemNetworkInfoExample 

QT        += core
QT        += gui
QT        += network

HEADERS   += QSystemNetworkInfoExample.h
SOURCES   += QSystemNetworkInfoExample_reg.rss \
    main.cpp \
    QSystemNetworkInfoExample.cpp
FORMS	  += QSystemNetworkInfoExample.ui
RESOURCES +=

CONFIG += mobility
MOBILITY = systeminfo

qtAddLibrary(QtSystemInfo)

symbian:TARGET.UID3 = 0xEA4CB665
symbian:TARGET.CAPABILITY = ReadDeviceData
