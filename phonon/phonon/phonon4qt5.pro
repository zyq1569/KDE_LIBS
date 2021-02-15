
TEMPLATE = lib
TARGET = phonon4qt5
DESTDIR =  ../libs/
QT += core gui widgets
CONFIG += debug_and_release  c++11
#DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS PHONON_PLUGIN_PATH=\"bin\" PHONON_BACKEND_DIR_SUFFIX=\"/phonon4qt5_backend/\" QT_WIDGETS_LIB CMAKE_INTDIR=\"Debug\" MAKE_PHONON_LIB
DEFINES += MAKE_PHONON_LIB
INCLUDEPATH +=  ../ \
                ../phonon \
                ../../phonon/phonon/experimental \
                ../includes

LIBS += -L$${DESTDIR} \
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

include(phonon4qt5.pri)
