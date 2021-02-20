# ----------------------------------------------------
# 
# ------------------------------------------------------



#HEADERS +=  ./ui_textdocumentsettings.h \
#            ./ui_chooseenginewidget.h \
#            ./settings_core.h

HEADERS +=      core/action.h \
                core/annotations.h \
                core/area.h \
                core/audioplayer.h \
                core/bookmarkmanager.h \
                core/chooseenginedialog.h \
                core/document.h \
                core/documentcommands.h \
                core/fontinfo.h \
                core/form.h \
                core/generator.h \
                core/generator_p.h \
                core/misc.h \
                core/movie.h \
                core/observer.h \
                core/debug.h \
                core/page.h \
                core/pagecontroller.h \
                core/pagesize.h \
                core/pagetransition.h \
                core/rotationjob.h \
                core/scripter.h \
                core/sound.h \
                core/sourcereference.h \
                core/textdocumentgenerator.h \
                core/textdocumentsettings.h \
                core/textpage.h \
                core/tilesmanager.h \
                core/utils.h \
                core/view.h \
                core/fileprinter.h \
                core/printoptionswidget.h \
                core/signatureutils.h \
                core/script/event.h \
                core/synctex/synctex_parser.h \
                core/synctex/synctex_parser_utils.h \
#                ./qrc_builtin.h \
#                ./settings_core.h \
                core/script/executor_kjs.h \
                core/script/kjs_app.h \
                core/script/kjs_console.h \
                core/script/kjs_data.h \
                core/script/kjs_display.h \
                core/script/kjs_document.h \
                core/script/kjs_field.h \
                core/script/kjs_fullscreen.h \
                core/script/kjs_spell.h \
                core/script/kjs_util.h \
                core/script/kjs_event.h \
                core/script/kjs_ocg.h


SOURCES +=      core/action.cpp \
                core/annotations.cpp \
                core/area.cpp \
                core/audioplayer.cpp \
                core/bookmarkmanager.cpp \
                core/chooseenginedialog.cpp \
                core/document.cpp \
                core/documentcommands.cpp \
                core/fontinfo.cpp \
                core/form.cpp \
                core/generator.cpp \
                core/generator_p.cpp \
                core/misc.cpp \
                core/movie.cpp \
                core/observer.cpp \
                core/debug.cpp \
                core/page.cpp \
                core/pagecontroller.cpp \
                core/pagesize.cpp \
                core/pagetransition.cpp \
                core/rotationjob.cpp \
                core/scripter.cpp \
                core/sound.cpp \
                core/sourcereference.cpp \
                core/textdocumentgenerator.cpp \
                core/textdocumentsettings.cpp \
                core/textpage.cpp \
                core/tilesmanager.cpp \
                core/utils.cpp \
                core/view.cpp \
                core/fileprinter.cpp \
                core/printoptionswidget.cpp \
                core/signatureutils.cpp \
                core/script/event.cpp \
                core/synctex/synctex_parser.c \
                core/synctex/synctex_parser_utils.c \
#                ./qrc_builtin.cpp \
#                ./settings_core.cpp \
                core/script/executor_kjs.cpp \
                core/script/kjs_app.cpp \
                core/script/kjs_console.cpp \
                core/script/kjs_data.cpp \
                core/script/kjs_display.cpp \
                core/script/kjs_document.cpp \
                core/script/kjs_field.cpp \
                core/script/kjs_fullscreen.cpp \
                core/script/kjs_spell.cpp \
                core/script/kjs_util.cpp \
                core/script/kjs_event.cpp \
                core/script/kjs_ocg.cpp


FORMS +=  part/textdocumentsettings.ui \
          core/chooseenginewidget.ui

RESOURCES +=  core/script/builtin.qrc
