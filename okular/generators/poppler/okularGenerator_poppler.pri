# ----------------------------------------------------
# 
# ------------------------------------------------------




#HEADERS += ./ui_pdfsettingswidget.h \
#    ./pdfsettings.h

HEADERS +=  generator_pdf.h \
            formfields.h \
            annots.h \
            pdfsignatureutils.h\
            conf/pdfsettings.h


SOURCES +=  generator_pdf.cpp \
            formfields.cpp \
            annots.cpp \
            pdfsignatureutils.cpp\
            conf/pdfsettings.cpp

FORMS  +=  conf/pdfsettingswidget.ui
