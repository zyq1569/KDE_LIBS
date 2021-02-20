# ----------------------------------------------------
# 
# ------------------------------------------------------

TEMPLATE = lib
TARGET = okularcore
DESTDIR = ./bin/Debug
QT += core xml network gui widgets printsupport concurrent dbus
CONFIG += debug_and_release
DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER TRANSLATION_DOMAIN=\"okular\" QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 KCOREADDONS_LIB QT_NETWORK_LIB QT_CONCURRENT_LIB QT_DBUS_LIB QT_WIDGETS_LIB QT_XML_LIB QT_PRINTSUPPORT_LIB CMAKE_INTDIR=\"Debug\" okularcore_EXPORTS
INCLUDEPATH += ../ \
    ../../okular \
    ../okularcore_autogen/include_Debug \
    ../../okular/core/synctex \
    ../core \
    ../../../../include/phonon4qt5/KDE \
    ../../../inst/zlib-1.2.11 \
    ../../../../include/phonon4qt5 \
    ../../../../include/KF5/KArchive \
    ../../../../include/KF5 \
    $(QTDIR)/./mkspecs/win32-msvc \
    ../../../../include/KF5/KIOCore \
    ../../../../CraftRoot/include/KF5/KCoreAddons \
    ../../../../CraftRoot/include/KF5 \
    ../../../../include/KF5/KService \
    ../../../../include/KF5/KConfigCore \
    ../../../../include/KF5/KIOWidgets \
    ../../../../include/KF5/KIOGui \
    ../../../../include/KF5/KWindowSystem \
    ../../../../include/KF5/KJobWidgets \
    ../../../../include/KF5/KCompletion \
    ../../../../include/KF5/KWidgetsAddons
LIBS += -L"." \
    -lshlwapi \
    -lD://lib/KF5KIOCore \
    -lD://lib/KF5KIOWidgets \
    -lKF5::I18n \
    -lD://lib/KF5ThreadWeaver \
    -lD://lib/KF5Bookmarks \
    -lD://lib/phonon4qt5 \
    -lD:/KDE/inst/zlib123dll/static32/zlibstat \
    -lD://lib/KF5XmlGui \
    -lD://lib/KF5Wallet \
    -lD://lib/KF5JS \
    -lD://lib/KF5JSApi \
    -lD://lib/KF5KIOGui \
    -lD://lib/KF5Service \
    -lD://lib/KF5Crash \
    -lKF5::DBusAddons \
    -lD://lib/KF5JobWidgets \
    -lD://lib/KF5Completion \
    -lD://lib/KF5IconThemes \
    -lD://lib/KF5Archive \
    -lD://lib/KF5ConfigWidgets \
    -lD://lib/KF5ConfigGui \
    -lD://lib/KF5WidgetsAddons \
    -lD://lib/KF5Codecs \
    -lD://lib/KF5Auth \
    -lD://lib/KF5AuthCore \
    -lD:/CraftRoot/lib/libKF5CoreAddons.dll.a \
    -lD://lib/KF5WindowSystem \
    -lD://lib/KF5ConfigCore \
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
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += D:/KDE/KDE_LIBS/okular_vc
RCC_DIR += D:/KDE/KDE_LIBS/okular_vc
include(okularcore.pri)
