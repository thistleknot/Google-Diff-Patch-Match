#-------------------------------------------------
#
# Project created by QtCreator 2014-08-09T07:37:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad_v2
TEMPLATE = app


SOURCES += main.cpp\
        diff_match.cpp \
    diff_match_patch.cpp \
    diff_match_patch_test.cpp

HEADERS  += diff_match.h \
    diff_match_patch.h \
    diff_match_patch_test.h

FORMS    += diff_match.ui
