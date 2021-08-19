

CONFIG            +=   debug_and_release
CONFIG            +=   C++ 14



#if(contains(DEFINES,win32-msvc*)){
win32 {

msvc: DEFINES += MSVC

}


contains(DEFINES, MSVC) {

                SDK_INSTALL_PREFIX = D:/Dev/KDE_SDK/MSC/RelWithDebInfo-vc2017/include
                SDK_LIB_PREFIX     = D:/Dev/KDE_SDK/MSC/RelWithDebInfo-vc2017/lib

INCLUDEPATH +=  $$SDK_INSTALL_PREFIX \
                $$SDK_INSTALL_PREFIX/KF5 \
                $$SDK_INSTALL_PREFIX/KF5/KrossUi \
                $$SDK_INSTALL_PREFIX/KF5/KrossCore \
                $$SDK_INSTALL_PREFIX/KF5/KAuth \
                $$SDK_INSTALL_PREFIX/KF5/KArchive \
                $$SDK_INSTALL_PREFIX/KF5/KActivities \
                $$SDK_INSTALL_PREFIX/KF5/KIOCore \
                $$SDK_INSTALL_PREFIX/KF5/ki18n \
                $$SDK_INSTALL_PREFIX/KF5/kdecore \
                $$SDK_INSTALL_PREFIX/KF5/KDBusAddons \
                $$SDK_INSTALL_PREFIX/KF5/KGuiAddons \
                $$SDK_INSTALL_PREFIX/KF5/KService \
                $$SDK_INSTALL_PREFIX/KF5/KXmlGui \
                $$SDK_INSTALL_PREFIX/KF5/KConfigWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KCodecs \
                $$SDK_INSTALL_PREFIX/KF5/KConfigGui \
                $$SDK_INSTALL_PREFIX/KF5/KConfigCore \
                $$SDK_INSTALL_PREFIX/KF5/KCoreAddons \
                $$SDK_INSTALL_PREFIX/KF5/KCompletion \
                $$SDK_INSTALL_PREFIX/KF5/KTextWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KIOWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KIOGui \
                $$SDK_INSTALL_PREFIX/KF5/KItemViews \
                $$SDK_INSTALL_PREFIX/KF5/KIOFileWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KIconThemes \
                $$SDK_INSTALL_PREFIX/KF5/KWindowSystem \
                $$SDK_INSTALL_PREFIX/KF5/KWidgetsAddons \
                $$SDK_INSTALL_PREFIX/KF5/KJobWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KNotifications \
                $$SDK_INSTALL_PREFIX/KF5/KBookmarks \
                $$SDK_INSTALL_PREFIX/KF5/SonnetUi \
                $$SDK_INSTALL_PREFIX/KF5/Solid \
                $$SDK_INSTALL_PREFIX/KF5/kcrash \
                $$SDK_INSTALL_PREFIX/KF5/kparts \
                $$SDK_INSTALL_PREFIX/KF5/ThreadWeaver \
                $$SDK_INSTALL_PREFIX/KF5/purpose \
                $$SDK_INSTALL_PREFIX/KF5/purposewidgets \
                $$SDK_INSTALL_PREFIX/KF5/KWallet \
                $$SDK_INSTALL_PREFIX/KF5/KExiv2 \
                $$SDK_INSTALL_PREFIX/poppler\qt5 \
                $$SDK_INSTALL_PREFIX/poppler \
                $$SDK_INSTALL_PREFIX/openjpeg-2.3 \
                $$SDK_INSTALL_PREFIX/zlib \
                $$SDK_INSTALL_PREFIX/phonon4qt5 \
                $$SDK_INSTALL_PREFIX/phonon4qt5/KDE \
                $$SDK_INSTALL_PREFIX/KChart

LIBS     += -L$${SDK_LIB_PREFIX} \
            -lKF5Parts \
            -lKF5KIOWidgets \
            -lKF5KIOGui \
            -lKF5KIOCore \
            -lKF5Crash \
            -lKF5WindowSystem \
            -lKF5JobWidgets \
            -lKF5Service \
            -lQt5Concurrent \
            -lKF5XmlGui \
            -lQt5Network \
            -lKF5TextWidgets \
            -lKF5Completion \
            -lKF5SonnetUi \
            -lKF5ConfigWidgets \
            -lKF5WidgetsAddons \
            -lKF5Codecs \
            -lKF5ConfigGui \
            -lQt5Xml \
            -lKF5ConfigCore \
            -lKF5Auth \
            -lKF5AuthCore \
            -lQt5DBus \
            -lKF5I18n \
            -lKF5CoreAddons \
            -lKF5Bookmarks \
            -lKF5JS \
            -lKF5JSApi \
            -lzlib \
            -lKF5I18n \
            -lKF5Purpose \
            -lKF5PurposeWidgets \
            -lKF5I18n \
            -lKF5WidgetsAddons \
            -lKF5KIOCore \
            -lKF5Service \
            -lKF5Crash \
            -lKF5DBusAddons \
            -lKF5XmlGui \
            -lKF5KIOFileWidgets \
            -lKF5IconThemes \
            -lKF5ConfigWidgets \
            -lKF5Codecs \
            -lKF5ConfigGui \
            -lKF5ConfigCore \
            -lKF5Auth \
            -lKF5AuthCore \
            -lKF5Activities \
            -lKF5Archive \
            -lKF5AuthCore \
            -lKF5CoreAddons \
            -lKF5JobWidgets \
            -lKF5Parts \
            -lKF5SonnetUi \
            -lKF5Crash \
            -lKF5Solid \
            -lKF5Completion \
            -lKF5GuiAddons \
            -lKF5TextWidgets \
            -lKF5WindowSystem \
            -lKF5ItemViews \
            -lKF5KIOWidgets \
            -lKF5Notifications \
            -lphonon4qt5 \
            -lKF5Bookmarks \
            -lKF5ThreadWeaver \
            -lKF5Wallet \
            -lKF5KExiv2 \
            -lepub \
            -lqmobipocket \
            -lmarkdown \
            -ljpeg-static \
            -lzlibstatic \
            -lpoppler \
            -lpoppler-qt5 \
            -ltiff \
            -lphonon4qt5 \
            -ldjvulibre \
            -lQt5Widgets \
            -lQt5Gui \
            -lQt5Core \
            -lspectre \
            -lqtmain \
            -lkernel32 \
            -luser32 \
            -lgdi32 \
            -lwinspool \
            -lshell32 \
            -lole32 \
            -loleaut32 \
            -luuid \
            -lcomdlg32 \
            -lshlwapi \
            -ladvapi32
}else {
#for to do : MinGW
                SDK_INSTALL_PREFIX = D:/Dev/KDE_SDK/include
                SDK_LIB_PREFIX     = D:/Dev/KDE_SDK/libs

INCLUDEPATH +=  $$SDK_INSTALL_PREFIX \
                $$SDK_INSTALL_PREFIX/KF5 \
                $$SDK_INSTALL_PREFIX/KF5/KrossUi \
                $$SDK_INSTALL_PREFIX/KF5/KrossCore \
                $$SDK_INSTALL_PREFIX/KF5/KAuth \
                $$SDK_INSTALL_PREFIX/KF5/KArchive \
                $$SDK_INSTALL_PREFIX/KF5/KActivities \
                $$SDK_INSTALL_PREFIX/KF5/KIOCore \
                $$SDK_INSTALL_PREFIX/KF5/ki18n \
                $$SDK_INSTALL_PREFIX/KF5/kdecore \
                $$SDK_INSTALL_PREFIX/KF5/KDBusAddons \
                $$SDK_INSTALL_PREFIX/KF5/KGuiAddons \
                $$SDK_INSTALL_PREFIX/KF5/KService \
                $$SDK_INSTALL_PREFIX/KF5/KXmlGui \
                $$SDK_INSTALL_PREFIX/KF5/KConfigWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KCodecs \
                $$SDK_INSTALL_PREFIX/KF5/KConfigGui \
                $$SDK_INSTALL_PREFIX/KF5/KConfigCore \
                $$SDK_INSTALL_PREFIX/KF5/KCoreAddons \
                $$SDK_INSTALL_PREFIX/KF5/KCompletion \
                $$SDK_INSTALL_PREFIX/KF5/KTextWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KIOWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KIOGui \
                $$SDK_INSTALL_PREFIX/KF5/KItemViews \
                $$SDK_INSTALL_PREFIX/KF5/KIOFileWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KIconThemes \
                $$SDK_INSTALL_PREFIX/KF5/KWindowSystem \
                $$SDK_INSTALL_PREFIX/KF5/KWidgetsAddons \
                $$SDK_INSTALL_PREFIX/KF5/KJobWidgets \
                $$SDK_INSTALL_PREFIX/KF5/KNotifications \
                $$SDK_INSTALL_PREFIX/KF5/KBookmarks \
                $$SDK_INSTALL_PREFIX/KF5/SonnetUi \
                $$SDK_INSTALL_PREFIX/KF5/Solid \
                $$SDK_INSTALL_PREFIX/KF5/kcrash \
                $$SDK_INSTALL_PREFIX/KF5/kparts \
                $$SDK_INSTALL_PREFIX/KF5/ThreadWeaver \
                $$SDK_INSTALL_PREFIX/KF5/purpose \
                $$SDK_INSTALL_PREFIX/KF5/purposewidgets \
                $$SDK_INSTALL_PREFIX/KF5/KWallet \
                $$SDK_INSTALL_PREFIX/KF5/KExiv2 \
                $$SDK_INSTALL_PREFIX/poppler\qt5 \
                $$SDK_INSTALL_PREFIX/poppler \
                $$SDK_INSTALL_PREFIX/openjpeg-2.3 \
                $$SDK_INSTALL_PREFIX/zlib \
                $$SDK_INSTALL_PREFIX/phonon4qt5 \
                $$SDK_INSTALL_PREFIX/phonon4qt5/KDE \
                $$SDK_INSTALL_PREFIX/KChart

LIBS        += -L$${SDK_LIB_PREFIX} \
               -lKF5I18n \
               -lKF5WidgetsAddons \
               -lKF5KIOCore \
               -lKF5Service \
               -lKF5Crash \
               -lKF5DBusAddons \
               -lKF5XmlGui \
               -lKF5KIOFileWidgets \
               -lKF5IconThemes \
               -lKF5ConfigWidgets \
               -lKF5Codecs \
               -lKF5ConfigGui \
               -lKF5ConfigCore \
               -lKF5NotifyConfig \
               -lKF5Auth \
               -lKF5AuthCore \
               -lKF5Activities \
               -lKF5Archive \
               -lKF5AuthCore \
               -lKF5CoreAddons \
               -lKF5JobWidgets \
               -lKF5Parts \
               -lKF5SonnetUi \
               -lKF5Crash \
               -lKF5Solid \
               -lKF5Completion \
               -lKF5GuiAddons \
               -lKF5TextWidgets \
               -lKF5WindowSystem \
               -lKF5ItemViews \
               -lKF5KIOWidgets \
               -lKF5KrossCore \
               -lKF5KrossUi \
               -lKF5Notifications \
               -llibpoppler \
               -llibpoppler-cpp \
               -llibpoppler-qt5 \
               -llibphonon4qt5 \
               -lphonon4qt5 \
               -lKF5Bookmarks \
               -lKF5ThreadWeaver \
               -lKF5Wallet \
       #        -llibzstd \
               -llibz \
               -llibKF5JS \
               -llibKF5JSApi \
               -llibKF5PurposeWidgets \
               -llibKF5Purpose \
               -llibtiff \
               -llibtiffxx \
               -llibfxstiff \
               -llibjpeg \
               -llibdjvulibre \
               -llibfreetype \
               -llibturbojpeg \
               -llibpcre \
               -lws2_32 \
               -lnetapi32 \
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
               -lshlwapi \
               -llibdjvulibre

}

#for pdf print
#https://www.ghostscript.com/download.html
#https://www.exiv2.org/
#https://github.com/ArtifexSoftware
#https://gcompris.net/index-en.html

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


#//OKULAR_EXPORT_PLUGIN(ComicBookGenerator, "libokularGenerator_comicbook.json")

#//static_assert(json[0] != '\0', "arg2 must be a string literal");                                                                                                                                                                           \
#//    K_PLUGIN_CLASS_WITH_JSON(classname, json)

#//#define K_PLUGIN_CLASS_WITH_JSON(classname, jsonFile) K_PLUGIN_FACTORY_WITH_JSON(classname ## Factory, jsonFile, registerPlugin<classname >();)

#//#define K_PLUGIN_FACTORY_WITH_JSON(name, jsonFile, pluginRegistrations)  K_PLUGIN_FACTORY_WITH_BASEFACTORY_JSON(name, KPluginFactory, jsonFile, pluginRegistrations)

#//#define K_PLUGIN_FACTORY_WITH_BASEFACTORY_JSON(name, baseFactory, jsonFile, pluginRegistrations) \
#//    K_PLUGIN_FACTORY_DECLARATION_WITH_BASEFACTORY_JSON(name, baseFactory, jsonFile) \
#//    K_PLUGIN_FACTORY_DEFINITION_WITH_BASEFACTORY(name, baseFactory, pluginRegistrations)

#//#define K_PLUGIN_FACTORY_DECLARATION_WITH_BASEFACTORY_SKEL(name, baseFactory, ...) \
#//    class name : public KPluginFactory \
#//    { \
#//        Q_OBJECT \
#//        Q_INTERFACES(KPluginFactory) \
#//        __VA_ARGS__ \
#//    public: \
#//        explicit name(); \
#//        ~name(); \
#//    };

#//#define K_PLUGIN_FACTORY_DEFINITION_WITH_BASEFACTORY(name, baseFactory, pluginRegistrations) \
#//    name::name() \
#//    { \
#//        pluginRegistrations \
#//    } \
#//    name::~name() {}

#    //static_assert(json[0] != '\0', "arg2 must be a string literal");
#class ComicBookGeneratorFactory : public KPluginFactory
#{
#    Q_OBJECT
#    Q_INTERFACES(KPluginFactory)
#    Q_PLUGIN_METADATA(IID KPluginFactory_iid FILE  "libokularGenerator_comicbook.json")
#public:
#    explicit ComicBookGeneratorFactory();
#    ~ComicBookGeneratorFactory();
#};

#ComicBookGeneratorFactory::ComicBookGeneratorFactory()
#{
#    registerPlugin<ComicBookGenerator >();
#}
#ComicBookGeneratorFactory::~ComicBookGeneratorFactory()
#{
#}



#define K_PLUGIN_FACTORY_WITH_JSON(name, jsonFile, pluginRegistrations)
#class nameFactory : public KPluginFactory
#{
#    Q_OBJECT
#    Q_INTERFACES(KPluginFactory)
#    Q_PLUGIN_METADATA(IID KPluginFactory_iid FILE jsonFile)
#public:
#    explicit nameFactory();
#    ~nameFactory();
#};

#nameFactory::nameFactory()
#{
#    registerPlugin<name >();
#}
#nameFactory::~nameFactory()
#{}
#############################################
# Custom command for settings_core.h

#build settings_core.h settings_core.cpp: CUSTOM_COMMAND D$:\CraftRoot\build\_\b43af741\okular-20.12.2\conf\okular_core.kcfg D$:\CraftRoot\bin\kconfig_compiler_kf5.exe D$:\CraftRoot\build\_\b43af741\okular-20.12.2\conf\settings_core.kcfgc || okularcore_autogen okularcore_autogen_timestamp_deps
#  COMMAND = cmd.exe /C "cd /D D:\CraftRoot\build\_\b43af741\build && D:\CraftRoot\bin\kconfig_compiler_kf5.exe D:/CraftRoot/build/_/b43af741/okular-20.12.2/conf/okular_core.kcfg D:/CraftRoot/build/_/b43af741/okular-20.12.2/conf/settings_core.kcfgc -d D:/CraftRoot/build/_/b43af741/build/"
#  DESC = Generating settings_core.h, settings_core.cpp
#  restat = 1
