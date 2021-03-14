# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = calculatetexttest
DESTDIR = ../bin/RelWithDebInfo
CONFIG += debug console
DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER TRANSLATION_DOMAIN=\"okular\" QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 KDESRCDIR=\"D:/Dev/code/okular-20.12.2/autotests/\" QT_WIDGETS_LIB QT_TESTLIB_LIB QT_TESTCASE_BUILDDIR=\"D:/Dev/code/okular-vc\" KCOREADDONS_LIB QT_XML_LIB QT_DBUS_LIB QT_PRINTSUPPORT_LIB CMAKE_INTDIR=\"RelWithDebInfo\"
LIBS += -L"." \
    -lD:/CraftRoot/lib/Qt5Test \
    -l../lib/RelWithDebInfo/Okular5Core \
    -lD:/CraftRoot/lib/KF5XmlGui \
    -lD:/CraftRoot/lib/Qt5PrintSupport \
    -lD:/CraftRoot/lib/KF5ConfigWidgets \
    -lD:/CraftRoot/lib/KF5ConfigGui \
    -lD:/CraftRoot/lib/Qt5Xml \
    -lD:/CraftRoot/lib/KF5Auth \
    -lD:/CraftRoot/lib/KF5AuthCore \
    -lD:/CraftRoot/lib/KF5CoreAddons \
    -lD:/CraftRoot/lib/KF5Codecs \
    -lD:/CraftRoot/lib/KF5WidgetsAddons \
    -lD:/CraftRoot/lib/KF5ConfigCore \
    -lD:/CraftRoot/lib/Qt5DBus \
    -lD:/CraftRoot/lib/Qt5Widgets \
    -lD:/CraftRoot/lib/Qt5Gui \
    -lD:/CraftRoot/lib/Qt5Core \
    -lkernel32 \
    -luser32 \
    -lgdi32 \
    -lwinspool \
    -lshell32 \
    -lole32 \
    -loleaut32 \
    -luuid \
    -lcomdlg32 \
    -ladvapi32 \
    -l$(NOINHERIT)
DEPENDPATH += .
MOC_DIR += GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += relwithdebinfo
UI_DIR += GeneratedFiles
RCC_DIR += GeneratedFiles
include(calculatetexttest.pri)
