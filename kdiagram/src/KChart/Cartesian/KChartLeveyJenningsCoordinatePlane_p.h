/*
 * Copyright (C) 2001-2015 Klaralvdalens Datakonsult AB.  All rights reserved.
 *
 * This file is part of the KD Chart library.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef KCHARTLEVEYJENNINGSCOORDINATEPLANE_P_H
#define KCHARTLEVEYJENNINGSCOORDINATEPLANE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the KD Chart API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QRectF>

#include "KChartLeveyJenningsCoordinatePlane.h"
#include "KChartLeveyJenningsGrid.h"
#include "KChartCartesianCoordinatePlane_p.h"
#include "KChartMath_p.h"

namespace KChart {

    class CartesianAxis;

    /**
     * \internal
     */

    class Q_DECL_HIDDEN LeveyJenningsCoordinatePlane::Private : public CartesianCoordinatePlane::Private
    {
        friend class LeveyJenningsCoordinatePlane;

    public:
        explicit Private();

        virtual ~Private() {
            // grid is delete in base class dtor
        }

        void initialize() override
        {
            grid = new LeveyJenningsGrid();
        }

        LeveyJenningsGridAttributes gridAttributes;
    };

    KCHART_IMPL_DERIVED_PLANE(LeveyJenningsCoordinatePlane, CartesianCoordinatePlane)
}

#endif /* KCHARTTERNARYCOORDINATEPLANE_P_H */
