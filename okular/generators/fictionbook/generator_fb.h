/***************************************************************************
 *   Copyright (C) 2007 by Tobias Koenig <tokoe@kde.org>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef _OKULAR_GENERATOR_FB_H_
#define _OKULAR_GENERATOR_FB_H_

#include <core/textdocumentgenerator.h>

class FictionBookGenerator : public Okular::TextDocumentGenerator
{
    Q_OBJECT
    Q_INTERFACES(Okular::Generator)

public:
    FictionBookGenerator(QObject *parent, const QVariantList &args);

    // [INHERITED] reparse configuration
    void addPages(KConfigDialog *dlg) override;
};


class FictionBookGeneratorFactory : public KPluginFactory
{
  Q_OBJECT
  Q_INTERFACES(KPluginFactory)
  Q_PLUGIN_METADATA(IID KPluginFactory_iid FILE  "libokularGenerator_fb.json")
public:
  explicit FictionBookGeneratorFactory();
  ~FictionBookGeneratorFactory();
};
#endif
