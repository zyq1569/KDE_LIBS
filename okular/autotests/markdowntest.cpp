/***************************************************************************
 *   Copyright (C) 2020 by Markus Brenneis <support.gulp21+kde@gmail.com>  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include <QtTest>

#include "../settings_core.h"
#include "core/document.h"
#include "generators/markdown/converter.h"
#include <QMimeDatabase>
#include <QMimeType>
#include <QTextDocument>

class MarkdownTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();

    void testFancyPantsEnabled();
    void testFancyPantsDisabled();
    void testImageSizes();

private:
    void findImages(QTextFrame *parent, QVector<QTextImageFormat> &images);
    void findImages(const QTextBlock &parent, QVector<QTextImageFormat> &images);
};

void MarkdownTest::initTestCase()
{
    Okular::SettingsCore::instance(QStringLiteral("markdowntest"));
}

void MarkdownTest::testFancyPantsEnabled()
{
    Markdown::Converter converter;
    converter.setFancyPantsEnabled(true);
    QTextDocument *document = converter.convert(QStringLiteral(KDESRCDIR "data/imageSizes.md"));

    QTextFrame::iterator secondFrame = ++(document->rootFrame()->begin());
    QVERIFY(secondFrame.currentBlock().text().startsWith(QStringLiteral("©")));
}

void MarkdownTest::testFancyPantsDisabled()
{
    Markdown::Converter converter;
    converter.setFancyPantsEnabled(false);
    QTextDocument *document = converter.convert(QStringLiteral(KDESRCDIR "data/imageSizes.md"));

    QTextFrame::iterator secondFrame = ++(document->rootFrame()->begin());
    QVERIFY(secondFrame.currentBlock().text().startsWith(QStringLiteral("(c)")));
}

void MarkdownTest::testImageSizes()
{
    Markdown::Converter converter;
    QTextDocument *document = converter.convert(QStringLiteral(KDESRCDIR "data/imageSizes.md"));

    QTextFrame *parent = document->rootFrame();

    QVector<QTextImageFormat> images;
    findImages(parent, images);

    QCOMPARE(images.size(), 17);

    qreal expectedSizes[][2] = {// width, height
                                // small image
                                {412, 349},
                                {100, 84.70873786407767},
                                {118.0515759312321, 100},
                                {100, 100},
                                {890, 753.9077669902913},
                                {890, 890},
                                // wide image
                                {890, 178},
                                {100, 20},
                                {500, 100},
                                {100, 100},
                                {890, 178},
                                {890, 890},
                                // tall image
                                {300, 1500},
                                {100, 500},
                                {20, 100},
                                {100, 100},
                                {890, 890}};

    for (int i = 0; i < images.size(); i++) {
        QCOMPARE(images[i].width(), expectedSizes[i][0]);
        QCOMPARE(images[i].height(), expectedSizes[i][1]);
    }
}

void MarkdownTest::findImages(QTextFrame *parent, QVector<QTextImageFormat> &images)
{
    for (QTextFrame::iterator it = parent->begin(); !it.atEnd(); ++it) {
        QTextFrame *textFrame = it.currentFrame();
        const QTextBlock textBlock = it.currentBlock();

        if (textFrame) {
            findImages(textFrame, images);
        } else if (textBlock.isValid()) {
            findImages(textBlock, images);
        }
    }
}

void MarkdownTest::findImages(const QTextBlock &parent, QVector<QTextImageFormat> &images)
{
    for (QTextBlock::iterator it = parent.begin(); !it.atEnd(); ++it) {
        const QTextFragment textFragment = it.fragment();
        if (textFragment.isValid()) {
            const QTextCharFormat textCharFormat = textFragment.charFormat();
            if (textCharFormat.isImageFormat()) {
                images.append(textCharFormat.toImageFormat());
            }
        }
    }
}

QTEST_MAIN(MarkdownTest)
#include "markdowntest.moc"
