#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T05:25:09
#
#-------------------------------------------------

QT       += core gui \
        multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AirStrike
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    player.cpp \
    game.cpp \
    health.cpp \
    score.cpp \
    over.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    player.h \
    game.h \
    health.h \
    score.h \
    over.h

RESOURCES += \
    res.qrc
