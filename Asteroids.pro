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
    rocks.cpp \
    Score.cpp \
    Health.cpp

HEADERS  += mainwindow.h \
    player.h \
    bullet.h \
    rocks.h \
    Score.h \
    Health.h

FORMS    += mainwindow.ui
