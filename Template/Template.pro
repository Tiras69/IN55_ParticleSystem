######################################################################
# Automatically generated by qmake (2.01a) Sun Mar 6 14:27:38 2011
######################################################################

CONFIG += console release
QT += core gui opengl
TARGET = TP01
TEMPLATE = app

DEPENDPATH += src
INCLUDEPATH = ../Common/ src "../glew-mingw/include"
#win32:LIBS += -L"../glew-mingw/lib" libGLEW.a

DESTDIR = release
OBJECTS_DIR = obj

# Input
HEADERS += \
    ../Common/GlFramework.h \
    ../Common/GlWindow.h \
    ../Common/LF_String.h \
    ../Common/Object3D.h \
    ../Common/Shapes/Basis.h \
    src/TP01.h \
    ../Common/Shapes/cylinder.h \
    ../Common/Shapes/Cube.h \
    src/gruewindow.h \
    ../Common/quaternion.h \
    ../Common/camera.h \
    src/testcamera.h

SOURCES += \
    ../Common/GlFramework.cpp \
    ../Common/GlWindow.cpp \
    ../Common/LF_String.cpp \
    ../Common/Object3D.cpp \
    ../Common/Shapes/Basis.cpp \
    src/TP01.cpp \
    src/main.cpp \
    ../Common/Shapes/cylinder.cpp \
    ../Common/Shapes/Cube.cpp \
    src/gruewindow.cpp \
    ../Common/quaternion.cpp \
    ../Common/camera.cpp \
    src/testcamera.cpp

unix:!macx: LIBS += -L$$PWD/../glew-mingw/lib/ -lGLEW

INCLUDEPATH += $$PWD/../glew-mingw/include
DEPENDPATH += $$PWD/../glew-mingw/include

unix:!macx: PRE_TARGETDEPS += $$PWD/../glew-mingw/lib/libGLEW.a
