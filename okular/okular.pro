# ----------------------------------------------------
#
# ------------------------------------------------------

CONFIG     +=   ordered
TEMPLATE    =   subdirs
SUBDIRS    +=   okularcore.pro \
                generators/comicbook/okular_comicbook.pro \
                shell/okular.pro \
                generators/comicbook/okularGenerator_comicbook.pro \
                generators/djvu/okularGenerator_djvu.pro \
                generators/dvi/okularGenerator_dvi.pro \
                generators/epub/okularGenerator_epub.pro \
                generators/fax/okularGenerator_fax.pro \
                generators/fictionbook/okularGenerator_fb.pro \
                generators/kimgio/okularGenerator_kimgio.pro \
                generators/markdown/okularGenerator_md.pro \
                generators/mobipocket/okularGenerator_mobi.pro \
                generators/plucker/okularGenerator_plucker.pro \
                generators/poppler/okularGenerator_poppler.pro \
                generators/tiff/okularGenerator_tiff.pro \
                generators/txt/okularGenerator_txt.pro \
                generators/xps/okularGenerator_xps.pro \
                generators/spectre/okularGenerator_ghostview.pro \
                #autotests/parttest.pro \
                okularpart.pro


#https://www.ghostscript.com/download.html
#https://www.exiv2.org/
#https://github.com/ArtifexSoftware
#https://gcompris.net/index-en.html
