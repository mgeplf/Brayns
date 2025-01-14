/* Copyright (c) 2015-2023, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Nadir Roman <nadir.romanguerrero@epfl.ch>
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

#include <io/sonataloader/LoadContext.h>
#include <io/util/ProgressUpdater.h>

#include <string_view>

namespace sonataloader
{
/**
 * @brief Interface to implement edge population loader types
 */
class EdgePopulationLoader
{
public:
    virtual ~EdgePopulationLoader() = default;

    /**
     * @brief Returns the population type that the loader handles. The type must match a valid population type
     * in the SONATA specs
     *
     * @return std::string
     */
    virtual std::string_view getPopulationType() const noexcept = 0;

    /**
     * @brief Interface to load an edge population
     *
     * @param ctxt
     */
    virtual void load(EdgeLoadContext &ctxt) const = 0;
};
} // namespace sonataloader
