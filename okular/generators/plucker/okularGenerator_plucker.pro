# ----------------------------------------------------
# 
# ------------------------------------------------------

TEMPLATE = lib
TARGET = okularGenerator_plucker
DESTDIR = ../../bin/plugins/okular/Debug
QT += core xml network gui widgets printsupport concurrent dbus
CONFIG += debug_and_release
DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 TRANSLATION_DOMAIN=\"okular_plucker\" KCOREADDONS_LIB QT_XML_LIB QT_WIDGETS_LIB QT_DBUS_LIB QT_PRINTSUPPORT_LIB QT_NETWORK_LIB QT_CONCURRENT_LIB CMAKE_INTDIR=\"Debug\" okularGenerator_plucker_EXPORTS
INCLUDEPATH += ../ \
    ../../../../okular/generators/plucker \
    ../okularGenerator_plucker_autogen/include_Debug \
    ../../../../okular \
    ../../../../okular/core/synctex \
    ../../../core \
    ../../../../okular \
    ../../../../okular/generators/plucker/unpluck \
    ../../../ \
    ../../../../../../include/phonon4qt5 \
    ../../../../../../include/phonon4qt5/KDE \
    ../../../../../inst/zlib-1.2.11 \
    ../../../../../inst/jpeg-9d \
    ../../../../../../CraftRoot/include/KF5/KCoreAddons \
    ../../../../../../CraftRoot/include/KF5 \
    $(QTDIR)/./mkspecs/win32-msvc \
    ../../../../../../include/KF5/KXmlGui \
    ../../../../../../include/KF5 \
    ../../../../../../include/KF5/KConfigCore \
    ../../../../../../include/KF5/KConfigWidgets \
    ../../../../../../include/KF5/KCodecs \
    ../../../../../../include/KF5/KWidgetsAddons \
    ../../../../../../include/KF5/KConfigGui \
    ../../../../../../include/KF5/KAuth \
    ../../../../../../include/KF5/KIOCore \
    ../../../../../../include/KF5/KService
LIBS += -L"." \
    -l../../lib/Debug/Okular5Core \
    -lD://lib/KF5KIOCore \
    -lKF5::I18n \
    -lD:/KDE/inst/zlib123dll/static32/zlibstat \
    -lD://lib/KF5XmlGui \
    -lD://lib/KF5ConfigWidgets \
    -lD://lib/KF5ConfigGui \
    -lD://lib/KF5Codecs \
    -lD://lib/KF5Auth \
    -lD://lib/KF5AuthCore \
    -lD://lib/KF5WidgetsAddons \
    -lD://lib/KF5Service \
    -lD://lib/KF5ConfigCore \
    -lD://lib/KF5Crash \
    -lD:/CraftRoot/lib/libKF5CoreAddons.dll.a \
    -lKF5::DBusAddons \
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
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(okularGenerator_plucker.pri)
