TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    gausscalc.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    gausscalc.h

