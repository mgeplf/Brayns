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

#include "BiophysicalPopulationLoader.h"

#include <io/sonataloader/colordata/node/BiophysicalColorData.h>
#include <io/sonataloader/data/Cells.h>
#include <io/sonataloader/data/Names.h>
#include <io/sonataloader/populations/nodes/common/ColorDataFactory.h>
#include <io/sonataloader/populations/nodes/common/MorphologyImporter.h>
#include <io/sonataloader/populations/nodes/common/NeuronReportFactory.h>
#include <io/sonataloader/populations/nodes/common/SomaImporter.h>

namespace sonataloader
{
std::string_view BiophysicalPopulationLoader::getPopulationType() const noexcept
{
    return NodeNames::biophysical;
}

void BiophysicalPopulationLoader::load(NodeLoadContext &context) const
{
    auto colorData = NodeColorDataFactory::create<BiophysicalColorData>(context);

    auto &loadParams = context.params;
    auto &morphParams = loadParams.neuron_morphology_parameters;
    auto soma = morphParams.load_soma;
    auto axon = morphParams.load_axon;
    auto dend = morphParams.load_dendrites;

    if (soma && !axon && !dend)
    {
        SomaImporter::import(context, std::move(colorData));
        return;
    }

    auto &population = context.population;
    auto &selection = context.selection;
    auto rotations = Cells::getRotations(population, selection);
    MorphologyImporter::import(context, rotations, std::move(colorData));
}
} // namespace sonataloader
