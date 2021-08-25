/********************************************************************************
** Form generated from reading UI file 'kshortcutwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSHORTCUTWIDGET_H
#define UI_KSHORTCUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "kkeysequencewidget.h"

QT_BEGIN_NAMESPACE

class Ui_KShortcutWidget
{
public:
    QHBoxLayout *hboxLayout;
    QLabel *priLabel;
    KKeySequenceWidget *priEditor;
    QSpacerItem *spacerItem;
    QLabel *altLabel;
    KKeySequenceWidget *altEditor;

    void setupUi(QWidget *KShortcutWidget)
    {
        if (KShortcutWidget->objectName().isEmpty())
            KShortcutWidget->setObjectName(QString::fromUtf8("KShortcutWidget"));
        KShortcutWidget->resize(180, 49);
        hboxLayout = new QHBoxLayout(KShortcutWidget);
#ifndef Q_OS_MAC
        hboxLayout->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        hboxLayout->setContentsMargins(9, 9, 9, 9);
#endif
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        priLabel = new QLabel(KShortcutWidget);
        priLabel->setObjectName(QString::fromUtf8("priLabel"));

        hboxLayout->addWidget(priLabel);

        priEditor = new KKeySequenceWidget(KShortcutWidget);
        priEditor->setObjectName(QString::fromUtf8("priEditor"));
        priEditor->setMinimumSize(QSize(0, 0));

        hboxLayout->addWidget(priEditor);

        spacerItem = new QSpacerItem(50, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        altLabel = new QLabel(KShortcutWidget);
        altLabel->setObjectName(QString::fromUtf8("altLabel"));

        hboxLayout->addWidget(altLabel);

        altEditor = new KKeySequenceWidget(KShortcutWidget);
        altEditor->setObjectName(QString::fromUtf8("altEditor"));
        altEditor->setMinimumSize(QSize(0, 0));

        hboxLayout->addWidget(altEditor);


        retranslateUi(KShortcutWidget);

        QMetaObject::connectSlotsByName(KShortcutWidget);
    } // setupUi

    void retranslateUi(QWidget *KShortcutWidget)
    {
        priLabel->setText(QCoreApplication::translate("KShortcutWidget", "Main:", nullptr));
        altLabel->setText(QCoreApplication::translate("KShortcutWidget", "Alternate:", nullptr));
        (void)KShortcutWidget;
    } // retranslateUi

};

namespace Ui {
    class KShortcutWidget: public Ui_KShortcutWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSHORTCUTWIDGET_H
