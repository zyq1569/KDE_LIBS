

CONFIG     +=   ordered

TEMPLATE    =   subdirs

SUBDIRS    +=   src/KF5I18n.pro \
                src/ktranscriptt.pro \
                autotests/ki18n-ktranscripttest.pro \
                autotests/ki18n-ktranscriptcleantest.pro

#ERROR_LOG(QString("Error reading file [ %1]\n Possible cause: %2 ").arg(filename).arg(status.text()))
