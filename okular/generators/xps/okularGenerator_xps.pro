# ----------------------------------------------------
# 
# ------------------------------------------------------

TEMPLATE = lib
TARGET = okularGenerator_xps
LIBDIR  = ../.././bin/
DESTDIR = ../.././bin/okular/generators
QT += core xml network gui widgets printsupport concurrent dbus

#DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 TRANSLATION_DOMAIN=\"okular_xps\" KCOREADDONS_LIB QT_XML_LIB QT_WIDGETS_LIB QT_DBUS_LIB QT_PRINTSUPPORT_LIB QT_NETWORK_LIB QT_CONCURRENT_LIB CMAKE_INTDIR=\"Debug\" okularGenerator_xps_EXPORTS
DEFINES += okularGenerator_xps_EXPORTS
INCLUDEPATH += ../ \
                ../../generators/xps \
                ../../ \
                ../../core/synctex \
                ../../core


LIBS +=    -L$${LIBDIR} \
           -lOkularCore


include(../../okularAll.pri)
include(okularGenerator_xps.pri)
