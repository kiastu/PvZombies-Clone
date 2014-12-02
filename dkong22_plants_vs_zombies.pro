#-------------------------------------------------
#
# Project created by QtCreator 2014-11-11T14:53:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dkong22_plants_vs_zombies
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plant.cpp \
    board.cpp \
    peashooter.cpp \
    sunflower.cpp \
    cherrybomb.cpp \
    wallnut.cpp \
    potatomine.cpp \
    snowpea.cpp \
    chomper.cpp \
    repeater.cpp \
    zombie.cpp \
    projectile.cpp \
    sun.cpp \
    lawnmower.cpp

HEADERS  += mainwindow.h \
    plant.h \
    board.h \
    peashooter.h \
    sunflower.h \
    cherrybomb.h \
    wallnut.h \
    potatomine.h \
    snowpea.h \
    chomper.h \
    repeater.h \
    zombie.h \
    projectile.h \
    sun.h \
    lawnmower.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    images/cherrybomb.png \
    images/chomper.png \
    images/peashooter.png \
    images/Potatomine.png \
    images/repeater.png \
    images/snowpea.png \
    images/SunFlower.png \
    images/Wallnut.png \
    images/zombie.png

RESOURCES += \
    Resources.qrc
