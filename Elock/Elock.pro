QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
INCLUDEPATH += /usr/local/include/opencv4/opencv2 \
          /usr/local/include/opencv4 \
          /home/pi/LiveFaceReco_RaspberryPi/include/ncnn \
          /home/pi/LiveFaceReco_RaspberryPi/include
LIBS += /usr/local/lib/libopencv_*.so
LIBS += /home/pi/LiveFaceReco_RaspberryPi/include/libs/RaspberryPi4B/libncnn.a
LIBS += -lgomp
LIBS += -lwiringPi
TARGET=ELock
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QMAKE_CXXFLAGS +=-lstdc++fs
QMAKE_CXXFLAGS +=-ldl
QMAKE_CXXFLAGS +=-lpthread
QMAKE_CXXFLAGS +=-Wall
FORMS += \
    welcome.ui

HEADERS += \
    welcome.h \
    arcface.h \
    defs.hpp \
    live.h \
    livefacereco.hpp \
    math.hpp \
    mtcnn_new.h \
    parallel_video_capture.hpp

SOURCES += \
    welcome.cpp \
    arcface.cpp \
    live.cpp \
    livefacereco.cpp \
    main.cpp \
    mtcnn_new.cpp \
    parallel_video_capture.cpp
