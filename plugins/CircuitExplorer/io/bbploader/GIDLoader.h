/* Copyright (c) 2015-2022, EPFL/Blue Brain Project
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

#include <io/BBPLoaderParameters.h>

#include <brain/circuit.h>
#include <brion/blueConfig.h>

namespace bbploader
{
class GIDLoader
{
public:
    static brain::GIDSet
        compute(const brion::BlueConfig &config, const brain::Circuit &circuit, const BBPLoaderParameters &input);

private:
    static brain::GIDSet _fromParameters(
        const brion::BlueConfig &config,
        const brain::Circuit &circuit,
        const BBPLoaderParameters &input);

    static brain::GIDSet
        _fromSimulation(const brion::BlueConfig &config, const BBPLoaderParameters &input, const brain::GIDSet &src);

    static brain::GIDSet _fromPercentage(const brain::GIDSet &src, const float percentage);
};
}