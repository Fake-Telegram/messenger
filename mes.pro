#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T03:03:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addfriend.cpp \
    user.cpp \
    client.cpp \
    message.cpp \
#    client_model.c
    chat.cpp \
    authorization.cpp

HEADERS  += mainwindow.h \
    addfriend.h \
    user.h \
    message.h \
    client.h \
    chat.h \
    authorization.h

FORMS    += mainwindow.ui
