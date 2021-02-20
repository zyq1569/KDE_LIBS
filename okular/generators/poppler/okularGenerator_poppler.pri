# ----------------------------------------------------
# 
# ------------------------------------------------------


# .



HEADERS += ./ui_pdfsettingswidget.h \
    ./pdfsettings.h
SOURCES += ./okularGenerator_poppler_autogen/mocs_compilation.cpp \
    ../../../okular/generators/poppler/generator_pdf.cpp \
    ../../../okular/generators/poppler/formfields.cpp \
    ../../../okular/generators/poppler/annots.cpp \
    ../../../okular/generators/poppler/pdfsignatureutils.cpp \
    ./pdfsettings.cpp
FORMS += ../../../okular/generators/poppler/conf/pdfsettingswidget.ui
