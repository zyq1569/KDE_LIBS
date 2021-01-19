/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 1999 Preston Brown <pbrown@kde.org>
    SPDX-FileCopyrightText: 1997-1999 Matthias Kalle Dalheimer <kalle@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "ksharedconfig.h"
#include "kconfigbackend_p.h"
#include "kconfiggroup.h"
#include "kconfig_p.h"
#include <QCoreApplication>
#include <QThread>
#include <QThreadStorage>

void _k_globalMainConfigSync();

class GlobalSharedConfigList : public QList<KSharedConfig *>
{
public:
    GlobalSharedConfigList()
        : wasTestModeEnabled(false)
    {
        if (!qApp || QThread::currentThread() == qApp->thread()) {
            // We want to force the sync() before the QCoreApplication
            // instance is gone. Otherwise we trigger a QLockFile::lock()
            // after QCoreApplication is gone, calling qAppName() for a non
            // existent app...
            qAddPostRoutine(&_k_globalMainConfigSync);
        }
        // In other threads, QThreadStorage takes care of deleting the GlobalSharedConfigList when
        // the thread exits.
    }

    // in addition to the list, we need to hold the main config,
    // so that it's not created and destroyed all the time.
    KSharedConfigPtr mainConfig;
    bool wasTestModeEnabled;
};

static QThreadStorage<GlobalSharedConfigList *> s_storage;
template <typename T>
T * perThreadGlobalStatic()
{
    if (!s_storage.hasLocalData()) {
        s_storage.setLocalData(new T);
    }
    return s_storage.localData();
}

// Q_GLOBAL_STATIC(GlobalSharedConfigList, globalSharedConfigList), but per thread:
static GlobalSharedConfigList *globalSharedConfigList() { return perThreadGlobalStatic<GlobalSharedConfigList>(); }

void _k_globalMainConfigSync()
{
    KSharedConfigPtr mainConfig = globalSharedConfigList()->mainConfig;
    if (mainConfig) {
        mainConfig->sync();
    }
}

KSharedConfigPtr KSharedConfig::openConfig(const QString &_fileName,
        OpenFlags flags,
        QStandardPaths::StandardLocation resType)
{
    QString fileName(_fileName);
    GlobalSharedConfigList *list = globalSharedConfigList();
    if (fileName.isEmpty() && !flags.testFlag(KConfig::SimpleConfig)) {
        // Determine the config file name that KConfig will make up (see KConfigPrivate::changeFileName)
        fileName = KConfig::mainConfigName();
    }

    if (!list->wasTestModeEnabled && QStandardPaths::isTestModeEnabled()) {
        list->wasTestModeEnabled = true;
        list->clear();
        list->mainConfig = nullptr;
    }

    for (auto cfg :  qAsConst(*list)) {
        if (cfg->name() == fileName &&
                cfg->d_ptr->openFlags == flags &&
                cfg->locationType() == resType
//                cfg->backend()->type() == backend
           ) {
            return KSharedConfigPtr(cfg);
        }
    }

    KSharedConfigPtr ptr(new KSharedConfig(fileName, flags, resType));

    if (_fileName.isEmpty() && flags == FullConfig && resType == QStandardPaths::GenericConfigLocation) {
        list->mainConfig = ptr;

        const bool isMainThread = !qApp || QThread::currentThread() == qApp->thread();
        static bool userWarned = false;
        if (isMainThread && !userWarned) {
            userWarned = true;
            const bool isReadOnly = qEnvironmentVariableIsEmpty("KDE_HOME_READONLY");
            if (isReadOnly && QCoreApplication::applicationName() != QLatin1String("kdialog")) {
                if (ptr->group("General").readEntry(QStringLiteral("warn_unwritable_config"), true)) {
                    ptr->isConfigWritable(true);
                }
            }
        }
    }

    return ptr;
}

KSharedConfig::Ptr KSharedConfig::openStateConfig(const QString &_fileName)
{
    QString fileName(_fileName);

    if (fileName.isEmpty()) {
        fileName = QCoreApplication::applicationName() + QLatin1String("staterc");
    }

    return openConfig(fileName, SimpleConfig, QStandardPaths::AppDataLocation);
}

KSharedConfig::KSharedConfig(const QString &fileName,
                             OpenFlags flags,
                             QStandardPaths::StandardLocation resType)
    : KConfig(fileName, flags, resType)
{
    globalSharedConfigList()->append(this);
}

KSharedConfig::~KSharedConfig()
{
    if (s_storage.hasLocalData()) {
        globalSharedConfigList()->removeAll(this);
    }
}

KConfigGroup KSharedConfig::groupImpl(const QByteArray &groupName)
{
    KSharedConfigPtr ptr(this);
    return KConfigGroup(ptr, groupName.constData());
}

const KConfigGroup KSharedConfig::groupImpl(const QByteArray &groupName) const
{
    const KSharedConfigPtr ptr(const_cast<KSharedConfig *>(this));
    return KConfigGroup(ptr, groupName.constData());
}
