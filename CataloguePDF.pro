#-------------------------------------------------
#
# Project created by QtCreator 2015-09-18T14:37:59
#
#-------------------------------------------------

QT       += core

QT       += gui
QT       += sql\
QT       += printsupport\

TARGET = CataloguePDF
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    connexion.cpp \
    pdf.cpp

HEADERS += \
    connexion.h \
    pdf.h
