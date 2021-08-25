

TEMPLATE   = app
TARGET     = kxmlguiwindowtest
DESTDIR    = ../bin/Debug
QT        +=  core xml network printsupport concurrent dbus
QT        += testlib
#DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII QT_NO_URL_CAST_FROM_STRING QT_NO_CAST_FROM_BYTEARRAY QT_USE_QSTRINGBUILDER QT_NO_NARROWING_CONVERSIONS_IN_CONNECT QT_NO_SIGNALS_SLOTS_KEYWORDS QT_DEPRECATED_WARNINGS_SINCE=0x060000 KF_DEPRECATED_WARNINGS_SINCE=0x060000 QT_DISABLE_DEPRECATED_BEFORE=0x050d00 KF_DISABLE_DEPRECATED_BEFORE_AND_AT=0x054900 TRANSLATION_DOMAIN=\"kxmlgui5\" QT_NO_FOREACH QT_TESTLIB_LIB QT_TESTCASE_BUILDDIR=\"D:/Dev/KDE_LIBS/kxmlgui-5.75.0-vc\" KCOREADDONS_LIB QT_WIDGETS_LIB KXMLGUI_DISABLE_DEPRECATED_BEFORE_AND_AT=0x0 KXMLGUI_DEPRECATED_WARNINGS_SINCE=0x0 QT_XML_LIB QT_DBUS_LIB CMAKE_INTDIR=\"Debug\"

#INCLUDEPATH += ../ \
#    ../../../tests \
#    ../kxmlguiwindowtest_autogen/include_Debug \
#    ../../src \
#    ../../../src \
#    $(QTDIR)/qt5 \
#    $(QTDIR)/qt5/QtCore \
#    ../../../../../CraftRoot/mkspecs/win32-g++ \
#    $(QTDIR)/KF5/KCoreAddons \
#    $(QTDIR)/KF5 \
#    $(QTDIR)/KF5/KWidgetsAddons \
#    $(QTDIR)/qt5/QtWidgets \
#    $(QTDIR)/qt5/QtGui \
#    $(QTDIR)/qt5/QtANGLE \
#    $(QTDIR)/KF5/KI18n \
#    $(QTDIR)/qt5/QtXml \
#    $(QTDIR)/KF5/KConfigCore \
#    $(QTDIR)/KF5/KConfigWidgets \
#    $(QTDIR)/KF5/KCodecs \
#    $(QTDIR)/KF5/KConfigGui \
#    $(QTDIR)/KF5/KAuth \
#    $(QTDIR)/qt5/QtDBus
#LIBS += -L"." \
#    -l../lib/Debug/KF5XmlGui \
#    -lD:/CraftRoot/lib/libKF5ConfigWidgets.dll.a \
#    -lD:/CraftRoot/lib/libKF5WidgetsAddons.dll.a \
#    -lD:/CraftRoot/lib/libKF5I18n.dll.a \
#    -lD:/CraftRoot/lib/libKF5Codecs.dll.a \
#    -lD:/CraftRoot/lib/libKF5ConfigGui.dll.a \
#    -lD:/CraftRoot/lib/libQt5Xml.a \
#    -lD:/CraftRoot/lib/libKF5ConfigCore.dll.a \
#    -lD:/CraftRoot/lib/libKF5Auth.dll.a \
#    -lD:/CraftRoot/lib/libKF5AuthCore.dll.a \
#    -lD:/CraftRoot/lib/libKF5CoreAddons.dll.a \
#    -lD:/CraftRoot/lib/libQt5Widgets.a \
#    -lD:/CraftRoot/lib/libQt5Gui.a \
#    -lD:/CraftRoot/lib/libQt5DBus.a \
#    -lD:/CraftRoot/lib/libQt5Core.a \
#    -lD:/CraftRoot/lib/libqtmain.a \
#    -lkernel32 \
#    -luser32 \
#    -lgdi32 \
#    -lwinspool \
#    -lshell32 \
#    -lole32 \
#    -loleaut32 \
#    -luuid \
#    -lcomdlg32 \
#    -ladvapi32 \
#    -l$(NOINHERIT)
#DEPENDPATH += .
#MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
#OBJECTS_DIR += debug
#UI_DIR += ./GeneratedFiles
#RCC_DIR += ./GeneratedFiles
DESTDIR      = ../../bin/bin/
LIBS      +=   -L$${DESTDIR} \
               -lKF5XmlGui

include(kxmlguiwindowtest.pri)
include(../kxmlgui.pri)
