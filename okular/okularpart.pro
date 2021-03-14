# ----------------------------------------------------
#
# ------------------------------------------------------

TEMPLATE = lib
TARGET   = okularpart
DESTDIR  = ./bin
QT       += core xml gui svg widgets dbus printsupport gui texttospeech network concurrent
#DEFINES +=  WIN32_LEAN_AND_MEAN _WIN32_WINNT=0x0600 WINVER=0x0600 _WIN32_IE=0x0600 _UNICODE _USE_MATH_DEFINES _CRT_SECURE_NO_DEPRECATE _CRT_SECURE_NO_WARNINGS _CRT_NONSTDC_NO_DEPRECATE _SCL_SECURE_NO_WARNINGS HAVE_SPEECH WITH_KWALLET=1 WITH_KJS=1 QT_USE_QSTRINGBUILDER TRANSLATION_DOMAIN=\"okular\" QT_NO_URL_CAST_FROM_STRING QT_DEPRECATED_WARNINGS_SINCE=0x050C00 KF_DEPRECATED_WARNINGS_SINCE=0x054400 KCOREADDONS_LIB QT_XML_LIB QT_WIDGETS_LIB QT_DBUS_LIB QT_PRINTSUPPORT_LIB QT_SVG_LIB QT_NETWORK_LIB QT_CONCURRENT_LIB QT_TEXTTOSPEECH_LIB CMAKE_INTDIR=\"Release\" okularpart_EXPORTS
DEFINES += okularpart_EXPORTS WITH_KWALLET=1 WITH_KJS=1 _USE_MATH_DEFINES
CONFIG  += C++ 14

DEFINES += DHAVE_SPEECH
DEFINES += DKCOREADDONS_LIB
DEFINES += DKF_DEPRECATED_WARNINGS_SINCE=0x054400
DEFINES += DQT_CONCURRENT_LIB
DEFINES += DQT_CORE_LIB
DEFINES += DQT_DBUS_LIB
DEFINES += DQT_DEPRECATED_WARNINGS_SINCE=0x050C00
DEFINES += DQT_GUI_LIB
DEFINES += DQT_NETWORK_LIB
DEFINES += DQT_NO_DEBUG
DEFINES += DQT_NO_URL_CAST_FROM_STRING
DEFINES += DQT_PRINTSUPPORT_LIB
DEFINES += DQT_SVG_LIB
DEFINES += DQT_TEXTTOSPEECH_LIB
DEFINES += DQT_USE_QSTRINGBUILDER
DEFINES += DQT_WIDGETS_LIB
DEFINES += DQT_XML_LIB
DEFINES += DTRANSLATION_DOMAIN=\"okular\"
DEFINES += DUNICODE
DEFINES += DWIN32_LEAN_AND_MEAN
DEFINES += DWINVER=0x0600
DEFINES += DWITH_KJS=1
DEFINES += DWITH_KWALLET=1
DEFINES += D_CRT_NONSTDC_NO_DEPRECATE
DEFINES += D_CRT_SECURE_NO_DEPRECATE
DEFINES += D_CRT_SECURE_NO_WARNINGS
DEFINES += D_SCL_SECURE_NO_WARNINGS
DEFINES += D_UNICODE
DEFINES += D_USE_MATH_DEFINES
DEFINES += D_WIN32_IE=0x0600
DEFINES += D_WIN32_WINNT=0x0600

INCLUDEPATH +=  ../ \
                conf/ \
                ../core/synctex \
                ../core \
                mobile/components


LIBS +=    -L$${DESTDIR} \
           -lOkular5Core

#LIBS += -L"." \
#    -lD:/Dev/code/okular-vc/lib/Release/Okular5Core \
#    -lD:/CraftRoot/lib/phonon4qt5 \
#    -lD:/CraftRoot/lib/KF5KIOFileWidgets \
#    -lD:/CraftRoot/lib/KF5Parts \
#    -lD:/CraftRoot/lib/KF5Solid \
#    -lD:/CraftRoot/lib/KF5Wallet \
#    -lD:/CraftRoot/lib/KF5PurposeWidgets \
#    -lD:/CraftRoot/lib/KF5Bookmarks \
#    -lD:/CraftRoot/lib/KF5KIOWidgets \
#    -lD:/CraftRoot/lib/KF5KIOGui \
#    -lD:/CraftRoot/lib/KF5KIOCore \
#    -lD:/CraftRoot/lib/KF5Service \
#    -lD:/CraftRoot/lib/Qt5Concurrent \
#    -lD:/CraftRoot/lib/KF5WindowSystem \
#    -lD:/CraftRoot/lib/KF5JobWidgets \
#    -lD:/CraftRoot/lib/KF5XmlGui \
#    -lD:/CraftRoot/lib/KF5IconThemes \
#    -lD:/CraftRoot/lib/Qt5Svg \
#    -lD:/CraftRoot/lib/KF5Archive \
#    -lD:/CraftRoot/lib/KF5ItemViews \
#    -lD:/CraftRoot/lib/Qt5PrintSupport \
#    -lD:/CraftRoot/lib/KF5TextWidgets \
#    -lD:/CraftRoot/lib/Qt5TextToSpeech \
#    -lD:/CraftRoot/lib/KF5Completion \
#    -lD:/CraftRoot/lib/KF5ConfigWidgets \
#    -lD:/CraftRoot/lib/KF5ConfigGui \
#    -lD:/CraftRoot/lib/Qt5Xml \
#    -lD:/CraftRoot/lib/KF5WidgetsAddons \
#    -lD:/CraftRoot/lib/KF5Codecs \
#    -lD:/CraftRoot/lib/KF5Auth \
#    -lD:/CraftRoot/lib/KF5AuthCore \
#    -lD:/CraftRoot/lib/KF5SonnetUi \
#    -lD:/CraftRoot/lib/KF5I18n \
#    -lD:/CraftRoot/lib/Qt5Widgets \
#    -lD:/CraftRoot/lib/KF5Purpose \
#    -lD:/CraftRoot/lib/KF5CoreAddons \
#    -lD:/CraftRoot/lib/Qt5Gui \
#    -lD:/CraftRoot/lib/KF5ConfigCore \
#    -lD:/CraftRoot/lib/Qt5DBus \
#    -lD:/CraftRoot/lib/Qt5Network \
#    -lD:/CraftRoot/lib/Qt5Core \
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

SDK_INSTALL_PREFIX = D:/CraftRoot/include
SDK_LIB_PREFIX     = D:/CraftRoot/lib/

LIBS +=         -L$${SDK_LIB_PREFIX}    \
                -lOkular5Core           \
                -lphonon4qt5            \
                -lKF5KIOFileWidgets     \
                -lKF5Parts              \
                -lKF5Solid              \
                -lKF5Wallet             \
                -lKF5Bookmarks          \
                -lKF5KIOWidgets         \
                -lKF5KIOGui             \
                -lKF5KIOCore            \
                -lKF5Service            \
                -lQt5Concurrent         \
                -lKF5WindowSystem       \
                -lKF5JobWidgets         \
                -lKF5XmlGui             \
                -lKF5IconThemes         \
                -lQt5Svg                \
                -lKF5Archive            \
                -lKF5ItemViews          \
                -lQt5PrintSupport       \
                -lQt5Network            \
                -lKF5TextWidgets        \
                -lQt5TextToSpeech       \
                -lKF5Completion         \
                -lKF5ConfigWidgets      \
                -lKF5I18n               \
                -lKF5ConfigGui          \
                -lQt5Xml                \
                -lKF5ConfigCore         \
                -lKF5WidgetsAddons      \
                -lKF5Codecs             \
                -lKF5Auth               \
                -lKF5AuthCore           \
                -lKF5CoreAddons         \
                -lQt5DBus               \
                -lKF5SonnetUi           \
                -lQt5Widgets            \
                -lQt5Gui                \
                -lQt5Core               \
                -lkernel32              \
                -luser32                \
                -lgdi32                 \
                -lwinspool              \
                -lshell32               \
                -lole32                 \
                -loleaut32              \
                -luuid                  \
                -lcomdlg32              \
                -ladvapi32


include(okularAll.pri)
include(okularpart.pri)
