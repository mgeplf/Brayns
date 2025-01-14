/* Copyright (c) 2015-2023, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Nadir Roman Guerrero <nadir.romanguerrero@epfl.ch>
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#pragma once

#include <brayns/engine/model/systemtypes/BoundsSystem.h>

namespace brayns
{
template<typename Type>
class GenericBoundsSystem : public BoundsSystem
{
public:
    Bounds compute(const TransformMatrix &matrix, Components &components) override
    {
        auto &component = components.get<Type>();
        auto &elements = component.elements;

        Bounds result;
#pragma omp parallel
        {
            Bounds local;

#pragma omp for
            for (size_t i = 0; i < elements.size(); ++i)
            {
                auto &element = elements[i];
                local.expand(element.computeBounds(matrix));
            }

#pragma omp critical(local_bounds_merge_section)
            result.expand(local);
        }

        return result;
    }
};
}
