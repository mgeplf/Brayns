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

#include "PointNeuronPopulationLoader.h"

#include <io/sonataloader/colordata/node/PointNeuronColorData.h>
#include <io/sonataloader/populations/nodes/common/ColorDataFactory.h>
#include <io/sonataloader/populations/nodes/common/SomaImporter.h>

namespace sonataloader
{
std::string PointNeuronPopulationLoader::getPopulationType() const noexcept
{
    return "point_neuron";
}

void PointNeuronPopulationLoader::load(NodeLoadContext &context) const
{
    auto colorData = NodeColorDataFactory::create<PointNeuronColorData>(context);
    SomaImporter::import(context, std::move(colorData));
}
} // namespace sonataloader