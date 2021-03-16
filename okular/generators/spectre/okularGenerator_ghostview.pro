# ----------------------------------------------------
# 
# ------------------------------------------------------

TEMPLATE = lib
TARGET   = okularGenerator_ghostview
LIBDIR   = ../.././bin/
DESTDIR  = ../.././bin/okular/generators
QT      += core xml gui widgets printsupport dbus

DEFINES     += okular_ghostview
INCLUDEPATH += ../ \
            ../../ \
            ../../core/synctex \
            ../../core \
            conf/    \
            ../../../../../inst/zlib-1.2.11


LIBS  +=    -L$${LIBDIR} \
             -lOkularCore

UI_DIR       = DESTDIR/tmp/ui
MOC_DIR      = DESTDIR/tmp/moc
RCC_DIR      = DESTDIR/tmp/rcc
OBJECTS_DIR += DESTDIR/tmp/obj

include(../../okularAll.pri)
include(okularGenerator_ghostview.pri)


