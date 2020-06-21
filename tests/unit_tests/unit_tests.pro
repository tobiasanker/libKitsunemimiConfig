include(../../defaults.pri)

QT -= qt core gui

CONFIG   -= app_bundle
CONFIG += c++14 console

LIBS +=  -lboost_filesystem -lboost_system
LIBS += -L../../src -lKitsunemimiConfig

LIBS += -L../../../libKitsunemimiPersistence/src -lKitsunemimiPersistence
LIBS += -L../../../libKitsunemimiPersistence/src/debug -lKitsunemimiPersistence
LIBS += -L../../../libKitsunemimiPersistence/src/release -lKitsunemimiPersistence
INCLUDEPATH += ../../../libKitsunemimiPersistence/include

LIBS += -L../../../libKitsunemimiIni/src -lKitsunemimiIni
LIBS += -L../../../libKitsunemimiIni/src/debug -lKitsunemimiIni
LIBS += -L../../../libKitsunemimiIni/src/release -lKitsunemimiIni
INCLUDEPATH += ../../../libKitsunemimiIni/include

LIBS += -L../../../libKitsunemimiCommon/src -lKitsunemimiCommon
LIBS += -L../../../libKitsunemimiCommon/src/debug -lKitsunemimiCommon
LIBS += -L../../../libKitsunemimiCommon/src/release -lKitsunemimiCommon
INCLUDEPATH += ../../../libKitsunemimiCommon/include

INCLUDEPATH += $$PWD

SOURCES += \
    main.cpp \
    config_handler_test.cpp

HEADERS += \
    config_handler_test.h
