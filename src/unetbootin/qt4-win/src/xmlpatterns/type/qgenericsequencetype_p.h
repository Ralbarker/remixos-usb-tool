/****************************************************************************
**
** Copyright (C) 2006-2008 Trolltech ASA. All rights reserved.
**
** This file is part of the QtXMLPatterns module of the Qt Toolkit.
**
** This file may be used under the terms of the GNU General Public
** License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file.  Alternatively you may (at
** your option) use any later version of the GNU General Public
** License if such license has been publicly approved by Trolltech ASA
** (or its successors, if any) and the KDE Free Qt Foundation. In
** addition, as a special exception, Trolltech gives you certain
** additional rights. These rights are described in the Trolltech GPL
** Exception version 1.2, which can be found at
** http://www.trolltech.com/products/qt/gplexception/ and in the file
** GPL_EXCEPTION.txt in this package.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/. If
** you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** In addition, as a special exception, Trolltech, as the sole
** copyright holder for Qt Designer, grants users of the Qt/Eclipse
** Integration plug-in the right for the Qt/Eclipse Integration to
** link to functionality provided by Qt Designer and its related
** libraries.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not expressly
** granted herein.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#ifndef Patternist_GenericSequenceType_H
#define Patternist_GenericSequenceType_H

#include "qsequencetype_p.h"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

namespace QPatternist
{
    /**
     * @todo Documentation is missing.
     *
     * @ingroup Patternist_types
     * @author Frans Englich <fenglich@trolltech.com>
     */
    class GenericSequenceType : public SequenceType
    {
    public:
        GenericSequenceType(const ItemType::Ptr &itemType, const Cardinality &card);

        /**
         * Generates a name for the sequence type for display purposes. The
         * prefix used for the QName identifying the schema type is conventional.
         * An example of a display name for a GenericSequenceType is "xs:integer?".
         */
        virtual QString displayName(const NamePool::Ptr &np) const;

        virtual Cardinality cardinality() const;

        virtual ItemType::Ptr itemType() const;

    private:
        const ItemType::Ptr m_itemType;
        const Cardinality m_cardinality;
    };

    /**
     * @short An object generator for GenericSequenceType.
     *
     * makeGenericSequenceType() is a convenience function for avoiding invoking
     * the @c new operator, and wrapping the result in GenericSequenceType::Ptr.
     *
     * @returns a smart pointer to to a GenericSequenceType instaniated from @p itemType and @p cardinality.
     * @relates GenericSequenceType
     */
    static inline SequenceType::Ptr
    makeGenericSequenceType(const ItemType::Ptr &itemType, const Cardinality &cardinality)
    {
        return SequenceType::Ptr(new GenericSequenceType(itemType, cardinality));
    }
}

QT_END_NAMESPACE

QT_END_HEADER

#endif