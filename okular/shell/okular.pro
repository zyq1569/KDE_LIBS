# ----------------------------------------------------
# 
# ------------------------------------------------------

TEMPLATE = app
TARGET = okular

QT += core xml network gui widgets concurrent dbus

DESTDIR = .././bin

#DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER TRANSLATION_DOMAIN=\"okular\" QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 KCOREADDONS_LIB QT_NETWORK_LIB QT_CONCURRENT_LIB QT_DBUS_LIB QT_WIDGETS_LIB QT_XML_LIB CMAKE_INTDIR=\"Debug\"
INCLUDEPATH +=  ../shell \
                ../../ \
                ../ \
                ../../core/synctex \
                ../../core


# ../ \
#    ../../../okular/shell \
#    ../okular_autogen/include_Debug \
#    ../../../okular \
#    ../../../okular/core/synctex \
#    ../../core \
#    ../../../okular \
#    ../../ \
#    ../../../../../include/phonon4qt5 \
#    ../../../../../include/phonon4qt5/KDE \
#    ../../../../inst/zlib-1.2.11 \
#    ../../../../../include/KF5/KParts \
#    ../../../../../include/KF5 \
#    ../../../../../include/KF5/KIOWidgets \
#    ../../../../../include/KF5/KIOGui \
#    ../../../../../include/KF5/KIOCore \
#    ../../../../../CraftRoot/include/KF5/KCoreAddons \
#    ../../../../../CraftRoot/include/KF5 \
#    $(QTDIR)/./mkspecs/win32-msvc \
#    ../../../../../include/KF5/KService \
#    ../../../../../include/KF5/KConfigCore \
#    ../../../../../include/KF5/KWindowSystem \
#    ../../../../../include/KF5/KJobWidgets \
#    ../../../../../include/KF5/KCompletion \
#    ../../../../../include/KF5/KWidgetsAddons \
#    ../../../../../include/KF5/KXmlGui \
#    ../../../../../include/KF5/KConfigWidgets \
#    ../../../../../include/KF5/KCodecs \
#    ../../../../../include/KF5/KConfigGui \
#    ../../../../../include/KF5/KAuth \
#    ../../../../../include/KF5/KTextWidgets \
#    ../../../../../include/KF5/SonnetUi \
#    ../../../../../include/KF5/KCrash
#LIBS += -L"." \
#    -lD://lib/KF5Parts \
#    -lD://lib/KF5KIOWidgets \
#    -lD://lib/KF5KIOGui \
#    -lD://lib/KF5KIOCore \
#    -lD://lib/KF5Crash \
#    -lD://lib/KF5JobWidgets \
#    -lD://lib/KF5Service \
#    -lKF5::DBusAddons \
#    -lD://lib/KF5Completion \
#    -lD://lib/KF5XmlGui \
#    -lD://lib/KF5WindowSystem \
#    -lD://lib/KF5TextWidgets \
#    -lKF5::I18n \
#    -lD://lib/KF5SonnetUi \
#    -lD://lib/KF5IconThemes \
#    -lD://lib/KF5ConfigWidgets \
#    -lD://lib/KF5WidgetsAddons \
#    -lD://lib/KF5ConfigGui \
#    -lD://lib/KF5ConfigCore \
#    -lD://lib/KF5Codecs \
#    -lD://lib/KF5Auth \
#    -lD://lib/KF5AuthCore \
#    -lD:/CraftRoot/lib/libKF5CoreAddons.dll.a \
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
LIBS +=    -L$${DESTDIR} \
            -lokularcore

UI_DIR       = DESTDIR/tmp/ui
MOC_DIR      = DESTDIR/tmp/moc
RCC_DIR      = DESTDIR/tmp/rcc
OBJECTS_DIR += DESTDIR/tmp/obj

include(../okularAll.pri)
include(okular.pri)

