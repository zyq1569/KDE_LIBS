# ----------------------------------------------------
# 
# ------------------------------------------------------

TEMPLATE = lib
TARGET = okularpart
DESTDIR = ./bin/Debug
QT += core xml network gui svg widgets printsupport concurrent dbus texttospeech
CONFIG += debug_and_release
DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER TRANSLATION_DOMAIN=\"okular\" QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 KCOREADDONS_LIB QT_XML_LIB QT_WIDGETS_LIB QT_DBUS_LIB QT_PRINTSUPPORT_LIB QT_SVG_LIB QT_NETWORK_LIB QT_CONCURRENT_LIB QT_TEXTTOSPEECH_LIB CMAKE_INTDIR=\"Debug\" okularpart_EXPORTS
INCLUDEPATH += ../ \
    ../../okular \
    ../okularpart_autogen/include_Debug \
    ../../okular/core/synctex \
    ../core \
    ../../../../include/phonon4qt5/KDE \
    ../../../inst/zlib-1.2.11 \
    ../../../../include/phonon4qt5 \
    ../../../../CraftRoot/include/KF5/KCoreAddons \
    ../../../../CraftRoot/include/KF5 \
    $(QTDIR)/./mkspecs/win32-msvc \
    ../../../../include/KF5/KXmlGui \
    ../../../../include/KF5 \
    ../../../../include/KF5/KConfigCore \
    ../../../../include/KF5/KConfigWidgets \
    ../../../../include/KF5/KCodecs \
    ../../../../include/KF5/KWidgetsAddons \
    ../../../../include/KF5/KConfigGui \
    ../../../../include/KF5/KAuth \
    ../../../../include \
    ../../../../include/KF5/KArchive \
    ../../../../include/KF5/KBookmarks \
    ../../../../include/KF5/KIconThemes \
    ../../../../include/KF5/KItemViews \
    ../../../../include/KF5/KIOCore \
    ../../../../include/KF5/KService \
    ../../../../include/KF5/KIOFileWidgets \
    ../../../../include/KF5/KIOWidgets \
    ../../../../include/KF5/KIOGui \
    ../../../../include/KF5/KWindowSystem \
    ../../../../include/KF5/KJobWidgets \
    ../../../../include/KF5/KCompletion \
    ../../../../include/KF5/Solid \
    ../../../../include/KF5/KParts \
    ../../../../include/KF5/KTextWidgets \
    ../../../../include/KF5/SonnetUi \
    ../../../../include/KF5/KWallet \
    ../../../../CraftRoot/include/KF5/purposewidgets \
    ../../../../CraftRoot/include/KF5/purpose
LIBS += -L"." \
    -llib/Debug/Okular5Core \
    -lD://lib/phonon4qt5 \
    -lKF5::I18n \
    -lD://lib/KF5KIOCore \
    -lD://lib/KF5KIOFileWidgets \
    -lD://lib/KF5KIOWidgets \
    -lD://lib/KF5Parts \
    -lD://lib/KF5Solid \
    -lD://lib/KF5Wallet \
    -lD:/CraftRoot/lib/libKF5PurposeWidgets.dll.a \
    -lD://lib/KF5Bookmarks \
    -lsetupapi \
    -lD://lib/KF5KIOGui \
    -lD://lib/KF5Service \
    -lD://lib/KF5Crash \
    -lKF5::DBusAddons \
    -lD://lib/KF5JobWidgets \
    -lD://lib/KF5Completion \
    -lD://lib/KF5XmlGui \
    -lD://lib/KF5IconThemes \
    -lD://lib/KF5Archive \
    -lD://lib/KF5ItemViews \
    -lD://lib/KF5WindowSystem \
    -lD://lib/KF5TextWidgets \
    -lD://lib/KF5ConfigWidgets \
    -lD://lib/KF5ConfigGui \
    -lD://lib/KF5WidgetsAddons \
    -lD://lib/KF5Codecs \
    -lD://lib/KF5Auth \
    -lD://lib/KF5AuthCore \
    -lD://lib/KF5SonnetUi \
    -lD:/CraftRoot/lib/libKF5Purpose.dll.a \
    -lD:/CraftRoot/lib/libKF5CoreAddons.dll.a \
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
RCC_DIR += ./GeneratedFiles
include(okularpart.pri)
