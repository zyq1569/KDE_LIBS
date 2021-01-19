# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = KF5ConfigGui
DESTDIR = ../../bin
QT += core xml gui
CONFIG += debug
#DEFINES += _WINDOWS KCONFIGGUI_DISABLE_DEPRECATED_BEFORE_AND_AT=0x0 KCONFIGGUI_DEPRECATED_WARNINGS_SINCE=0x0 WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII QT_NO_URL_CAST_FROM_STRING QT_NO_CAST_FROM_BYTEARRAY QT_NO_SIGNALS_SLOTS_KEYWORDS QT_USE_QSTRINGBUILDER QT_NO_NARROWING_CONVERSIONS_IN_CONNECT QT_DEPRECATED_WARNINGS_SINCE=0x060000 KF_DEPRECATED_WARNINGS_SINCE=0x060000 QT_NO_FOREACH QT_DISABLE_DEPRECATED_BEFORE=0x050d00 QT_XML_LIB KCONFIGCORE_DISABLE_DEPRECATED_BEFORE_AND_AT=0x0 KCONFIGCORE_DEPRECATED_WARNINGS_SINCE=0x0 CMAKE_INTDIR=\"Debug\" KF5ConfigGui_EXPORTS
DEFINES += KF5ConfigGui_EXPORTS KCONFIGGUI_DISABLE_DEPRECATED_BEFORE_AND_AT=0x0 KCONFIGGUI_DEPRECATED_WARNINGS_SINCE=0x0
INCLUDEPATH += ../ \
    ../../../../../src/kconfig-5.75.0/src/gui \
    ../KF5ConfigGui_autogen/include_Debug \
    ../../core \
    ../../../../../src/kconfig-5.75.0/src/core \
    $(QTDIR)/./mkspecs/win32-msvc
LIBS += -L"." \
    -l../../lib/Debug/KF5ConfigCore \
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
include(KF5ConfigGui.pri)
