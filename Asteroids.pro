#-------------------------------------------------
#
# Project created by QtCreator 2016-03-28T10:09:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Asteroids
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    bullet.cpp \
    rocks.cpp

HEADERS  += mainwindow.h \
    player.h \
    bullet.h \
    rocks.h

FORMS    += mainwindow.ui
