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
                core/chooseenginedialog_p.h \
                core/document.h \
                core/documentcommands_p.h \
                core/fontinfo.h \
                core/form.h \
                core/generator.h \
                core/generator_p.h \
                core/misc.h \
                core/movie.h \
                core/observer.h \
                core/debug_p.h \
                core/page.h \
                core/pagecontroller_p.h \
                core/pagesize.h \
                core/pagetransition.h \
                core/rotationjob_p.h \
                core/scripter.h \
                core/sound.h \
                core/sourcereference.h \
                core/textdocumentgenerator.h \
                core/textdocumentsettings.h \
                core/textdocumentsettings_p.h \
                core/textpage.h \
                core/tilesmanager_p.h \
                core/utils.h \
                core/view.h \
                core/fileprinter.h \
                core/printoptionswidget.h \
                core/signatureutils.h \
                core/script/event_p.h \
                core/synctex/synctex_parser.h \
                core/synctex/synctex_parser_utils.h \
                core/script/executor_kjs_p.h \
                core/script/kjs_app_p.h \
                core/script/kjs_console_p.h \
                core/script/kjs_data_p.h \
                core/script/kjs_display_p.h \
                core/script/kjs_document_p.h \
                core/script/kjs_field_p.h \
                core/script/kjs_fullscreen_p.h \
                core/script/kjs_spell_p.h \
                core/script/kjs_util_p.h \
                core/script/kjs_event_p.h \
                core/script/kjs_ocg_p.h



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
                core/script/kjs_ocg.cpp \
                conf/settings_core.cpp


FORMS +=  part/textdocumentsettings.ui \
          core/chooseenginewidget.ui

RESOURCES +=  core/script/builtin.qrc
