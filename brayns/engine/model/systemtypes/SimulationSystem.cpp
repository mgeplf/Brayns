/* Copyright (c) 2015-2022, EPFL/Blue Brain Project
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

#include "SimulationSystem.h"

namespace
{
class SimulationChecks
{
public:
    static bool shouldExecute(const brayns::SimulationParameters &simulation, uint32_t lastFrame)
    {
        return simulation.isModified() && simulation.getFrame() != lastFrame;
    }
};
}

namespace brayns
{
void SimulationSystem::execute(const ParametersManager &parameters, Components &components)
{
    auto &simulation = parameters.getSimulationParameters();
    auto simulationChanged = SimulationChecks::shouldExecute(simulation, _lastFrame);
    auto stateChanged = shouldExecute(components);
    if (!simulationChanged && !stateChanged)
    {
        return;
    }

    std::exchange(_lastFrame, simulation.getFrame());
    execute(components, _lastFrame);
}
}