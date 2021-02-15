/*  This file is part of the KDE project
    Copyright (C) 2004-2007 Matthias Kretz <kretz@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), Nokia Corporation
    (or its successors, if any) and the KDE Free Qt Foundation, which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef PHONON_FACTORY_P_H
#define PHONON_FACTORY_P_H

#include "phonon_export.h"

#include "factory_p.h"
#include "objectdescription.h"
#include <QObject>
#include <QFileInfo>
#include <QPluginLoader>
#include <QStringList>

class QUrl;
class QIcon;

namespace Phonon
{
    class PlatformPlugin;
    class MediaNodePrivate;
    class AbstractMediaStream;

    /**
     * \internal
     */
    struct Q_DECL_HIDDEN BackendDescriptor {
        explicit BackendDescriptor(const QString &path = QString())
            : isValid(false)
        {
            QFileInfo info(path);
            if (!info.exists()) {
                return;
            }

            QPluginLoader loader(path);

            iid = loader.metaData().value(QLatin1String("IID")).toString();

            const QJsonObject metaData = loader.metaData().value(QLatin1String("MetaData")).toObject();
            name = metaData.value(QLatin1String("Name")).toString();
            icon = metaData.value(QLatin1String("Icon")).toString();
            version = metaData.value(QLatin1String("Version")).toString();
            website = metaData.value(QLatin1String("Website")).toString();
            initialPreference = metaData.value(QLatin1String("InitialPreference")).toInt();

            pluginPath = path;
            pluginName = info.baseName();

            if (name.isEmpty()) {
                name = pluginName;
            }

            if (iid.isEmpty()) {
                return; // Not valid.
            }

            isValid = true;
        }

        bool isValid;

        QString iid;

        QString name;
        QString icon;
        QString version;
        QString website;
        int initialPreference; // Initial preference declared by the backend; larger is better
        int weight = -1; // Weight assinged by user configuration

        QString pluginPath;
        QString pluginName; // basename of the file. "legacy" name used for PHONON_BACKEND

        /** Implemented for sorting */
        bool operator <(const BackendDescriptor &rhs) const
        {
            if (weight >= 0) {
                // If we have a weight the preference doesn't matter.
                // User configured weight always wins against initial preference.
                return (weight < rhs.weight);
            }

            return this->initialPreference < rhs.initialPreference;
        }
    };

/**
 * \internal
 * \brief Factory to access the preferred Backend.
 *
 * This class is used internally to get the backend's implementation.
 * It keeps track of the objects that were created. When a
 * request for a backend change comes, it asks all frontend objects to delete
 * their backend objects and then checks whether they were all deleted. Only
 * then the old backend is unloaded and the new backend is loaded.
 *
 * \author Matthias Kretz <kretz@kde.org>
 */
namespace Factory
{
    /**
     * Emits signals for Phonon::Factory.
     */
    class Sender : public QObject
    {
        Q_OBJECT
        Q_SIGNALS:
            /**
             * Emitted after the backend has successfully been changed.
             */
            void backendChanged();

            /**
             * \copydoc BackendCapabilities::Notifier::availableAudioOutputDevicesChanged
             */
            void availableAudioOutputDevicesChanged();

            /**
             * \copydoc BackendCapabilities::Notifier::availableAudioCaptureDevicesChanged
             */
            void availableAudioCaptureDevicesChanged();

            /**
             * \copydoc BackendCapabilities::Notifier::availableVideoCaptureDevicesChanged
             */
            void availableVideoCaptureDevicesChanged();
    };

    PHONON_EXPORT QList<BackendDescriptor> findBackends();

    /**
     * Returns a pointer to the object emitting the signals.
     *
     * \see Sender::backendChanged()
     */
    PHONON_EXPORT Sender *sender();

    /**
     * Create a new backend object for a MediaObject.
     *
     * \return a pointer to the MediaObject the backend provides.
     */
    QObject *createMediaObject(QObject *parent = 0);
    /**
     * Create a new backend object for a Effect.
     *
     * \return a pointer to the Effect the backend provides.
     */
#ifndef QT_NO_PHONON_EFFECT
    QObject *createEffect(int effectId, QObject *parent = 0);
#endif //QT_NO_PHONON_EFFECT
    /**
     * Create a new backend object for a VolumeFaderEffect.
     *
     * \return a pointer to the VolumeFaderEffect the backend provides.
     */
#ifndef QT_NO_PHONON_VOLUMEFADEREFFECT
    QObject *createVolumeFaderEffect(QObject *parent = 0);
#endif //QT_NO_PHONON_VOLUMEFADEREFFECT
    /**
     * Create a new backend object for a AudioOutput.
     *
     * \return a pointer to the AudioOutput the backend provides.
     */
    QObject *createAudioOutput(QObject *parent = 0);
    /**
     * Create a new backend object for a VideoWidget.
     *
     * \return a pointer to the VideoWidget the backend provides.
     */
#ifndef QT_NO_PHONON_VIDEO
    QObject *createVideoWidget(QObject *parent = 0);
    QObject *createVideoGraphicsObject(QObject *parent = 0);
#endif //QT_NO_PHONON_VIDEO

    /**
    * Create a new backend object for a AudioDataOutput.
    *
    * \return a pointer to the AudioDataOutput the backend provides.
    */
    PHONON_EXPORT QObject *createAudioDataOutput(QObject *parent = 0);

    /**
     * \return a pointer to the backend interface.
     */
    PHONON_EXPORT QObject *backend(bool createWhenNull = true);

    /**
     * Unique identifier for the Backend. Can be used in configuration files
     * for example.
     */
    QString identifier();

    /**
     * Get the name of the Backend. It's the name from the .desktop file.
     */
    PHONON_EXPORT QString backendName();

    /**
     * Get the comment of the Backend. It's the comment from the .desktop file.
     */
    QString backendComment();

    /**
     * Get the version of the Backend. It's the version from the .desktop file.
     *
     * The version is especially interesting if there are several versions
     * available for binary incompatible versions of the backend's media
     * framework.
     */
    QString backendVersion();

    /**
     * Get the icon (name) of the Backend. It's the icon from the .desktop file.
     */
    QString backendIcon();

    /**
     * Get the website of the Backend. It's the website from the .desktop file.
     */
    QString backendWebsite();

    /**
     * registers the backend object
     */
    PHONON_EXPORT QObject *registerQObject(QObject *o);

    bool isMimeTypeAvailable(const QString &mimeType);

    PHONON_EXPORT void registerFrontendObject(MediaNodePrivate *);
    PHONON_EXPORT void deregisterFrontendObject(MediaNodePrivate *);

    PHONON_EXPORT void setBackend(QObject *);
    //PHONON_EXPORT void createBackend(const QString &library, const QString &version = QString());

    PHONON_EXPORT PlatformPlugin *platformPlugin();

//X    It is probably better if we can get away with internal handling of
//X    freeing the soundcard device when it's not needed anymore and
//X    providing an IPC method to stop all MediaObjects -> free all
//X    devices
//X    /**
//X     * \internal
//X     * This is called when the application needs to free the soundcard
//X     * device(s).
//X     */
//X    void freeSoundcardDevices();
} // namespace Factory


class PlatformPlugin;
class FactoryPrivate : public Phonon::Factory::Sender
{
    friend QObject *Factory::backend(bool);
    Q_OBJECT
    public:
        FactoryPrivate();
        ~FactoryPrivate();
        bool tryCreateBackend(const QString &path);
        bool createBackend();
#ifndef QT_NO_PHONON_PLATFORMPLUGIN
        PlatformPlugin *platformPlugin();

        PlatformPlugin *m_platformPlugin;
        bool m_noPlatformPlugin;
#endif //QT_NO_PHONON_PLATFORMPLUGIN
        QPointer<QObject> m_backendObject;

        QList<QObject *> objects;
        QList<MediaNodePrivate *> mediaNodePrivateList;

    private Q_SLOTS:
        /**
         * unregisters the backend object
        */
        void objectDestroyed(QObject *);

        void objectDescriptionChanged(ObjectDescriptionType);
};

} // namespace Phonon


#endif // PHONON_FACTORY_P_H
// vim: sw=4 ts=4
