#-------------------------------------------------
#
# Project created by QtCreator 2012-12-14T21:30:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finred
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    directorydialog.cpp \
    dirvalidator.cpp \
    validatedlineedit.cpp

HEADERS  += mainwindow.h \
    directorydialog.h \
    dirvalidator.h \
    validatedlineedit.h

FORMS    += mainwindow.ui \
    directorydialog.ui
