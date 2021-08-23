
TEMPLATE    = app
TARGET      = ki18n-ktranscriptcleantest
#DESTDIR     = ../bin/Debug
QT         += core network qml concurrent  testlib
DEFINES    += _WINDOWS KTRANSCRIPT_TESTBUILD WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS QT_NO_CAST_TO_ASCII QT_NO_URL_CAST_FROM_STRING QT_USE_QSTRINGBUILDER QT_NO_NARROWING_CONVERSIONS_IN_CONNECT QT_NO_SIGNALS_SLOTS_KEYWORDS QT_DEPRECATED_WARNINGS_SINCE=0x060000 KF_DEPRECATED_WARNINGS_SINCE=0x060000 QT_DISABLE_DEPRECATED_BEFORE=0x050d00 QT_NO_FOREACH QT_QML_LIB QT_NETWORK_LIB QT_TESTLIB_LIB  QT_CONCURRENT_LIB KI18N_DISABLE_DEPRECATED_BEFORE_AND_AT=0x0 KI18N_DEPRECATED_WARNINGS_SINCE=0x0

INCLUDEPATH += ../ \
               ../src

LIBS        += -L"." \
              -l../bin/bin/KF5I18n
#            -lkernel32 \
#            -luser32 \
#            -lgdi32 \
#            -lwinspool \
#            -lshell32 \
#            -lole32 \
#            -loleaut32 \
#            -luuid \
#            -lcomdlg32 \
#            -ladvapi32 \
#            -l$(NOINHERIT)

#DEPENDPATH  += .
#MOC_DIR     += ./GeneratedFiles/$(ConfigurationName)
#OBJECTS_DIR += debug
#UI_DIR      += ./GeneratedFiles
#RCC_DIR     += ./GeneratedFiles

include(ki18n-ktranscriptcleantest.pri)
include(../ki18n.pri)
