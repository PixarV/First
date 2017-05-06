#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T15:50:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = diplom_first
TEMPLATE = app

LIBS += -L"C:\Qt_project\diplom_first" -lbass # подключение dll


SOURCES += main.cpp\
        widget.cpp \
    myfirstthread.cpp \
    mysecondthread.cpp

HEADERS  += widget.h \
    myfirstthread.h \
    mysecondthread.h

FORMS    += widget.ui

CONFIG += thread
