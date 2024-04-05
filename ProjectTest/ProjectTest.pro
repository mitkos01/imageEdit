QT += testlib core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qt console
CONFIG -= app_bundle

TARGET = projectTest
TEMPLATE = app

SOURCES += tst_imageprojecttest.cpp \
           ../untitled3/editor.cpp
HEADERS += ../untitled3/editor.h
