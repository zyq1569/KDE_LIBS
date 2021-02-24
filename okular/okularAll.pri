# ----------------------------------------------------
# 
# ------------------------------------------------------

SDK_INSTALL_PREFIX = D:/KDE/calligra_KDE/include
SDK_LIB_PREFIX     = D:/KDE/calligra_KDE/libs

CONFIG += debug_and_release 

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
                $$SDK_INSTALL_PREFIX/phonon4qt5 \
                $$SDK_INSTALL_PREFIX/phonon4qt5/KDE \
                $$SDK_INSTALL_PREFIX/KChart

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

LIBS += -L$${SDK_LIB_PREFIX} \
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
        -lKF5KrossCore \
        -lKF5KrossUi \
        -lKF5Notifications \
        -lphonon4qt5 \
        -lKF5Bookmarks \
        -lKF5ThreadWeaver \
        -llibKF5JS \
        -llibKF5JSApi \
        -llibKF5PurposeWidgets \
        -llibKF5Purpose \
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
        -lshlwapi



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
