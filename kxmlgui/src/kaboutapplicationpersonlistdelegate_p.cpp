/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 2010 Teo Mrnjavac <teo@kde.org>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "kaboutapplicationpersonlistdelegate_p.h"

#include "kaboutapplicationpersonmodel_p.h"
#include "kaboutapplicationpersonlistview_p.h"
#include "ktoolbar.h"

#include <klocalizedstring.h>

#include <QAction>
#include <QApplication>
#include <QDesktopServices>
#include <QPainter>
#include <QStandardPaths>
#include <QLabel>

namespace KDEPrivate
{

enum {
    AVATAR_HEIGHT = 50,
    AVATAR_WIDTH = 50,
    MAIN_LINKS_HEIGHT = 32,
    SOCIAL_LINKS_HEIGHT = 26,
    MAX_SOCIAL_LINKS = 9
};

KAboutApplicationPersonListDelegate::KAboutApplicationPersonListDelegate(
    QAbstractItemView *itemView,
    QObject *parent)
    : KWidgetItemDelegate(itemView, parent)
{
}

QList< QWidget *> KAboutApplicationPersonListDelegate::createItemWidgets(const QModelIndex &index) const
{
    Q_UNUSED(index);
    QList< QWidget *> list;

    QLabel *textLabel = new QLabel(itemView());
    list.append(textLabel);

    KToolBar *mainLinks = new KToolBar(itemView(), false, false);

    QAction *emailAction = new QAction(QIcon::fromTheme(QStringLiteral("mail-send")),
                                       i18nc("Action to send an email to a contributor", "Email contributor"),
                                       mainLinks);
    emailAction->setVisible(false);
    mainLinks->addAction(emailAction);
    QAction *homepageAction = new QAction(QIcon::fromTheme(QStringLiteral("internet-services")),
                                          i18n("Visit contributor's homepage"),
                                          mainLinks);
    homepageAction->setVisible(false);
    mainLinks->addAction(homepageAction);
    QAction *visitProfileAction = new QAction(QIcon::fromTheme(QStringLiteral("get-hot-new-stuff")), QString(), mainLinks);
    visitProfileAction->setVisible(false);
    mainLinks->addAction(visitProfileAction);

    list.append(mainLinks);

    KToolBar *socialLinks = new KToolBar(itemView(), false, false);
    for (int i = 0; i < MAX_SOCIAL_LINKS; ++i) {
        QAction *action = new QAction(QIcon::fromTheme(QStringLiteral("applications-internet")), QString(), socialLinks);
        action->setVisible(false);
        socialLinks->addAction(action);
    }

    list.append(socialLinks);

    connect(mainLinks, &QToolBar::actionTriggered,
            this, &KAboutApplicationPersonListDelegate::launchUrl);
    connect(socialLinks, &QToolBar::actionTriggered,
            this, &KAboutApplicationPersonListDelegate::launchUrl);

    return list;
}

void KAboutApplicationPersonListDelegate::updateItemWidgets(const QList<QWidget *> widgets,
        const QStyleOptionViewItem &option,
        const QPersistentModelIndex &index) const
{
    const int margin = option.fontMetrics.height() / 2;

    KAboutApplicationPersonProfile profile = index.data().value< KAboutApplicationPersonProfile >();

    QRect wRect = widgetsRect(option, index);

    //Let's fill in the text first...
    QLabel *label = qobject_cast< QLabel * >(widgets.at(TextLabel));
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QString text = buildTextForProfile(profile);

    label->move(wRect.left(), wRect.top());
    label->resize(wRect.width(), heightForString(text, wRect.width() - margin, option) + margin);
    label->setWordWrap(true);
    label->setContentsMargins(0, 0, 0, 0);
    label->setAlignment(Qt::AlignBottom | Qt::AlignLeft);
    label->setForegroundRole(QPalette::WindowText);

    label->setText(text);

    //And now we fill in the main links (email + homepage + OCS profile)...
    KToolBar *mainLinks = qobject_cast< KToolBar * >(widgets.at(MainLinks));
    mainLinks->setIconSize(QSize(22, 22));
    mainLinks->setContentsMargins(0, 0, 0, 0);
    mainLinks->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QAction *action;
    if (!profile.email().isEmpty()) {
        action = mainLinks->actions().at(EmailAction);
        action->setToolTip(i18nc("@info:tooltip Action to send an email to a contributor",
                                 "Email contributor\n%1", profile.email()));
        action->setData(QString(QLatin1String("mailto:") + profile.email()));
        action->setVisible(true);
    }
    if (!profile.homepage().isEmpty()) {
        action = mainLinks->actions().at(HomepageAction);
        action->setToolTip(i18nc("@info:tooltip", "Visit contributor's homepage\n%1", profile.homepage().toString()));
        action->setData(profile.homepage().toString());
        action->setVisible(true);
    }
    if (!profile.ocsProfileUrl().isEmpty()) {
        action = mainLinks->actions().at(VisitProfileAction);
        KAboutApplicationPersonModel *model = qobject_cast< KAboutApplicationPersonModel * >(itemView()->model());
        action->setToolTip(i18nc("@info:tooltip", "Visit contributor's profile on %1\n%2",
                                 model->providerName(),
                                 profile.ocsProfileUrl()));
        action->setData(profile.ocsProfileUrl());
        action->setVisible(true);
    }
    mainLinks->resize(QSize(mainLinks->sizeHint().width(), MAIN_LINKS_HEIGHT));
    mainLinks->move(wRect.left(), wRect.top() + label->height());

    //Finally, the social links...
    KToolBar *socialLinks = qobject_cast< KToolBar * >(widgets.at(SocialLinks));
    socialLinks->setIconSize(QSize(16, 16));
    socialLinks->setContentsMargins(0, 0, 0, 0);
    socialLinks->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    int currentSocialLinkAction = 0;
    const auto links = profile.ocsLinks();
    for (const KAboutApplicationPersonProfileOcsLink &link : links) {
        if (!profile.homepage().isEmpty() && profile.homepage() == link.url()) {
            continue;    //We skip it if it's the same as the homepage from KAboutData
        }

        action = socialLinks->actions().at(currentSocialLinkAction);
        if (link.type() == KAboutApplicationPersonProfileOcsLink::Other) {
            action->setToolTip(i18nc("@info:tooltip", "Visit contributor's page\n%1",
                                     link.url().toString()));
        } else if (link.type() == KAboutApplicationPersonProfileOcsLink::Blog) {
            action->setToolTip(i18nc("@info:tooltip", "Visit contributor's blog\n%1",
                                     link.url().toString()));
        } else if (link.type() == KAboutApplicationPersonProfileOcsLink::Homepage) {
            action->setToolTip(i18nc("@info:tooltip", "Visit contributor's homepage\n%1",
                                     link.url().toString()));
        } else {
            action->setToolTip(i18nc("@info:tooltip", "Visit contributor's profile on %1\n%2",
                                     link.prettyType(),
                                     link.url().toString()));
        }
        action->setIcon(link.icon());
        action->setData(link.url().toString());
        action->setVisible(true);

        ++currentSocialLinkAction;
        if (currentSocialLinkAction > MAX_SOCIAL_LINKS - 1) {
            break;
        }
    }

    socialLinks->resize(QSize(socialLinks->sizeHint().width(), SOCIAL_LINKS_HEIGHT));
    socialLinks->move(wRect.left() + mainLinks->width(),
                      wRect.top() + label->height() +
                      (MAIN_LINKS_HEIGHT - SOCIAL_LINKS_HEIGHT) / 2);

    itemView()->reset();
}

QSize KAboutApplicationPersonListDelegate::sizeHint(const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    KAboutApplicationPersonProfile profile = index.data().value< KAboutApplicationPersonProfile >();
    bool hasAvatar = !profile.avatar().isNull();

    int margin = option.fontMetrics.height() / 2;

    int height = hasAvatar ? qMax(widgetsRect(option, index).height(),
                                  AVATAR_HEIGHT + 2 * margin)
                 : widgetsRect(option, index).height();

    QSize metrics(option.fontMetrics.height() * 7, height);
    return metrics;
}

void KAboutApplicationPersonListDelegate::paint(QPainter *painter,
        const QStyleOptionViewItem &option,
        const QModelIndex &index) const
{
    int margin = option.fontMetrics.height() / 2;

    QStyle *style = QApplication::style();
    style->drawPrimitive(QStyle::PE_Widget, &option, painter, nullptr);

    const KAboutApplicationPersonModel *model = qobject_cast< const KAboutApplicationPersonModel * >(index.model());

    if (model->hasAvatarPixmaps()) {
        int height = qMax(widgetsRect(option, index).height(), AVATAR_HEIGHT + 2 * margin);
        QPoint point(option.rect.left() + 2 * margin,
                     option.rect.top() + ((height - AVATAR_HEIGHT) / 2));

        KAboutApplicationPersonProfile profile = index.data().value< KAboutApplicationPersonProfile >();

        if (!profile.avatar().isNull()) {
            QPixmap pixmap = profile.avatar();

            point.setX((AVATAR_WIDTH - pixmap.width()) / 2 + 5);
            point.setY(option.rect.top() + ((height - pixmap.height()) / 2));
            painter->drawPixmap(point, pixmap);

            QPoint framePoint(point.x() - 5, point.y() - 5);
            QPixmap framePixmap(QStringLiteral(":/kxmlgui5/thumb_frame.png"));
            painter->drawPixmap(framePoint, framePixmap.scaled(pixmap.width() + 10, pixmap.height() + 10));
        }
    }
}

void KAboutApplicationPersonListDelegate::launchUrl(QAction *action) const
{
    QString url = action->data().toString();
    if (!url.isEmpty()) {
        QDesktopServices::openUrl(QUrl(url));
    }
}

int KAboutApplicationPersonListDelegate::heightForString(const QString &string,
        int lineWidth,
        const QStyleOptionViewItem &option) const
{
    QFontMetrics fm = option.fontMetrics;
    QRect boundingRect = fm.boundingRect(0, 0, lineWidth, 9999, Qt::AlignLeft |
                                         Qt::AlignBottom | Qt::TextWordWrap, string);
    return boundingRect.height();
}

QString KAboutApplicationPersonListDelegate::buildTextForProfile(const KAboutApplicationPersonProfile &profile) const
{
    QString text =
        QLatin1String("<b>") +
        i18nc("@item Contributor name in about dialog.", "%1", profile.name()) +
        QLatin1String("</b>");

    if (!profile.task().isEmpty()) {
        text += QLatin1String("\n<br><i>") +
                profile.task() +
                QLatin1String("</i>");
    }

    if (!profile.location().isEmpty()) {
        text += QLatin1String("\n<br>") +
                profile.location();
    }
    return text;
}

QRect KAboutApplicationPersonListDelegate::widgetsRect(const QStyleOptionViewItem &option,
        const QPersistentModelIndex &index) const
{
    KAboutApplicationPersonProfile profile = index.data().value< KAboutApplicationPersonProfile >();
    int margin = option.fontMetrics.height() / 2;

    QRect widgetsRect;
    if (qobject_cast< const KAboutApplicationPersonModel * >(index.model())->hasAvatarPixmaps()) {
        widgetsRect = QRect(option.rect.left() + AVATAR_WIDTH + 3 * margin,
                            margin / 2,
                            option.rect.width() - AVATAR_WIDTH - 4 * margin,
                            0);
    } else {
        widgetsRect = QRect(option.rect.left() + margin,
                            margin / 2,
                            option.rect.width() - 2 * margin,
                            0);
    }

    int textHeight = heightForString(buildTextForProfile(profile), widgetsRect.width() - margin, option);
    widgetsRect.setHeight(textHeight + MAIN_LINKS_HEIGHT + 1.5 * margin);

    return widgetsRect;
}

} //namespace KDEPrivate
