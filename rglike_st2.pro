TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    crt.cpp

HEADERS += \
    crt.h


unix|win32: LIBS += -lsfml-graphics

unix|win32: LIBS += -lsfml-system

unix|win32: LIBS += -lsfml-window

unix|win32: LIBS += -lsfml-audio
