
TEMPLATE = app
TARGET = phononsettings
DESTDIR =   ../libs/
QT += core gui widgets
CONFIG += debug_and_release  c++11
#DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS PHONON_LIB_SONAME=\"phonon4qt5\" QT_WIDGETS_LIB CMAKE_INTDIR=\"Debug\"
INCLUDEPATH +=
            ../settings \
            ../ \
            ../includes \
            ../phonon

LIBS += -L$${DESTDIR} \
        -lphonon4qt5 \
        -lkernel32 \
        -luser32 \
        -lgdi32 \
        -lwinspool \
        -lshell32 \
        -lole32 \
        -loleaut32 \
        -luuid \
        -lcomdlg32 \
        -ladvapi32
#DEPENDPATH += .
#MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
#OBJECTS_DIR += debug
#UI_DIR += ./GeneratedFiles
#RCC_DIR += ./GeneratedFiles
include(phononsettings.pri)
