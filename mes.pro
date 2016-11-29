#-------------------------------------------------
#
# Project created by QtCreator 2016-10-14T03:03:15
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mes
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11 -g
LIBS += -lboost_system -lboost_thread -lpthread

CONFIG += console

SOURCES += main.cpp\
        mainwindow.cpp \
    addfriend.cpp \
    user.cpp \
    client.cpp \
    message.cpp \
#    client_model.c
    chat.cpp \
#    mes.cpp \
#    sMessage.cpp \
#    mes.cpp \
#    client_model.c \
    authorization.cpp \
    networkl.cpp \
    thread_pool.cpp

HEADERS  += mainwindow.h \
    addfriend.h \
    user.h \
    message.h \
    client.h \
    chat.h \
#    sMessage.h \
    authorization.h \
    aut.h \
    network.h \
    thread_pool.h

FORMS    += mainwindow.ui \
    addfriend.ui \
    authorization.ui
