/*
    KDE Rich Text Editor
    SPDX-FileCopyrightText: 2008 Stephen Kelly <steveire@gmail.com>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#ifndef KRICHTEXTEDITOR_H
#define KRICHTEXTEDITOR_H

#include <krichtextwidget.h>

#include <kxmlguiwindow.h>

//@cond PRIVATE

class QLabel;

/**
 * @internal
 * Test window for testing KRichTextWidget
 */
class KRichTextEditor : public KXmlGuiWindow
{
    Q_OBJECT
public:
    KRichTextEditor();
    ~KRichTextEditor();

    void setupActions();

private Q_SLOTS:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();
    void saveFileAs(const QString &outputFileName);
    void cursorPositionChanged();

private:
    KRichTextWidget *textArea;
    QString fileName;
    QLabel *itemLabel;
};

//@endcond

#endif
