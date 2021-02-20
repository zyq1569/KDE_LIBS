# ----------------------------------------------------
# 
# ------------------------------------------------------


# .



HEADERS += ./ui_textdocumentsettings.h \
    ./ui_chooseenginewidget.h \
    ./settings_core.h
SOURCES += ./okularcore_autogen/mocs_compilation.cpp \
    ../okular/core/action.cpp \
    ../okular/core/annotations.cpp \
    ../okular/core/area.cpp \
    ../okular/core/audioplayer.cpp \
    ../okular/core/bookmarkmanager.cpp \
    ../okular/core/chooseenginedialog.cpp \
    ../okular/core/document.cpp \
    ../okular/core/documentcommands.cpp \
    ../okular/core/fontinfo.cpp \
    ../okular/core/form.cpp \
    ../okular/core/generator.cpp \
    ../okular/core/generator_p.cpp \
    ../okular/core/misc.cpp \
    ../okular/core/movie.cpp \
    ../okular/core/observer.cpp \
    ../okular/core/debug.cpp \
    ../okular/core/page.cpp \
    ../okular/core/pagecontroller.cpp \
    ../okular/core/pagesize.cpp \
    ../okular/core/pagetransition.cpp \
    ../okular/core/rotationjob.cpp \
    ../okular/core/scripter.cpp \
    ../okular/core/sound.cpp \
    ../okular/core/sourcereference.cpp \
    ../okular/core/textdocumentgenerator.cpp \
    ../okular/core/textdocumentsettings.cpp \
    ../okular/core/textpage.cpp \
    ../okular/core/tilesmanager.cpp \
    ../okular/core/utils.cpp \
    ../okular/core/view.cpp \
    ../okular/core/fileprinter.cpp \
    ../okular/core/printoptionswidget.cpp \
    ../okular/core/signatureutils.cpp \
    ../okular/core/script/event.cpp \
    ../okular/core/synctex/synctex_parser.c \
    ../okular/core/synctex/synctex_parser_utils.c \
    ./qrc_builtin.cpp \
    ./settings_core.cpp \
    ../okular/core/script/executor_kjs.cpp \
    ../okular/core/script/kjs_app.cpp \
    ../okular/core/script/kjs_console.cpp \
    ../okular/core/script/kjs_data.cpp \
    ../okular/core/script/kjs_display.cpp \
    ../okular/core/script/kjs_document.cpp \
    ../okular/core/script/kjs_field.cpp \
    ../okular/core/script/kjs_fullscreen.cpp \
    ../okular/core/script/kjs_spell.cpp \
    ../okular/core/script/kjs_util.cpp \
    ../okular/core/script/kjs_event.cpp \
    ../okular/core/script/kjs_ocg.cpp
FORMS += ../okular/part/textdocumentsettings.ui \
    ../okular/core/chooseenginewidget.ui
RESOURCES += ../okular/core/script/builtin.qrc
