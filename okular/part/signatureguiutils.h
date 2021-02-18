/***************************************************************************
 *   Copyright (C) 2018 by Chinmoy Ranjan Pradhan <chinmoyrp65@gmail.com>  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef OKULAR_SIGNATUREGUIUTILS_H
#define OKULAR_SIGNATUREGUIUTILS_H

#include <QString>

#include "core/signatureutils.h"

namespace Okular
{
class Document;
class FormFieldSignature;
}

namespace SignatureGuiUtils
{
/**
 * Returns a vector containing signature form fields. If @p allPages is true then all signature form fields in the
 * document are returned otherwise the fields in page number @p pageNum are returned.
 */
QVector<const Okular::FormFieldSignature *> getSignatureFormFields(Okular::Document *doc, bool allPages, int pageNum);
QString getReadableSignatureStatus(Okular::SignatureInfo::SignatureStatus sigStatus);
QString getReadableCertStatus(Okular::SignatureInfo::CertificateStatus certStatus);
QString getReadableHashAlgorithm(Okular::SignatureInfo::HashAlgorithm hashAlg);
QString getReadablePublicKeyType(Okular::CertificateInfo::PublicKeyType type);
QString getReadableKeyUsageCommaSeparated(Okular::CertificateInfo::KeyUsageExtensions kuExtensions);
QString getReadableKeyUsageNewLineSeparated(Okular::CertificateInfo::KeyUsageExtensions kuExtensions);

}

#endif
