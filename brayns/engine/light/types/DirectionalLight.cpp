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

#include "DirectionalLight.h"

#include <ospray/ospray_cpp/ext/rkcommon.h>

namespace
{
struct DirectionalLightParameters
{
    static inline const std::string color = "color";
    static inline const std::string intensity = "intensity";
    static inline const std::string direction = "direction";
    static inline const std::string angularDiameter = "angularDiameter";
    static inline const std::string cameraVisibility = "visible";
};
}

namespace brayns
{
void LightTraits<DirectionalLight>::updateData(ospray::cpp::Light &handle, DirectionalLight &data)
{
    data.direction = math::normalize(data.direction);
    handle.setParam(DirectionalLightParameters::color, data.color);
    handle.setParam(DirectionalLightParameters::intensity, data.intensity);
    handle.setParam(DirectionalLightParameters::direction, data.direction);
    handle.setParam(DirectionalLightParameters::angularDiameter, 0.53f);
    handle.setParam(DirectionalLightParameters::cameraVisibility, false);
}
}
