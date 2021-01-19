/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 1999 Matthias Ettrich <ettrich@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#include "kconfiggui.h"

#include <QGuiApplication>

#include <kconfig.h>

static QString configName(const QString &id, const QString &key)
{
    return(QLatin1String("session/") + QGuiApplication::applicationName() +
           QLatin1Char('_')          + id                                 +
           QLatin1Char('_')          + key);
}

static KConfig *s_sessionConfig = nullptr;

KConfig *KConfigGui::sessionConfig()
{
#ifdef QT_NO_SESSIONMANAGER
#error QT_NO_SESSIONMANAGER was set, this will not compile. Reconfigure Qt with Session management support.
#endif
    if (!hasSessionConfig() && qApp->isSessionRestored()) {
        // create the default instance specific config object
        // from applications' -session command line parameter
        s_sessionConfig = new KConfig(configName(qApp->sessionId(),
                                                 qApp->sessionKey()),
                                      KConfig::SimpleConfig);
    }

    return s_sessionConfig;
}

void KConfigGui::setSessionConfig(const QString &id, const QString &key)
{
    if (hasSessionConfig()) {
        delete s_sessionConfig;
        s_sessionConfig = nullptr;
    }

    // create a new instance specific config object from supplied id & key
    s_sessionConfig = new KConfig(configName(id, key),
                                  KConfig::SimpleConfig);
}

bool KConfigGui::hasSessionConfig()
{
    return s_sessionConfig != nullptr;
}

#if KCONFIGGUI_BUILD_DEPRECATED_SINCE(5, 11)
QString KConfigGui::sessionConfigName()
{
    if (sessionConfig()) {
        return sessionConfig()->name();
    } else {
        return QString();
    }
}
#endif
