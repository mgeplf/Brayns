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

#pragma once

#include <brayns/common/MathTypes.h>
#include <brayns/engine/Material.h>

namespace brayns
{
class MatteMaterial final : public Material
{
public:
    MatteMaterial();

    std::string getName() const noexcept final;

    /**
     * @brief Sets the opacity of the material. Must be between 0.0 and 1.0, with 0.0 = fully transparent,
     * and 1.0 = fully opaque.
     */
    void setOpacity(const float opacity) noexcept;

    /**
     * @brief Returns the material opacity
     */
    float getOpacity() const noexcept;

protected:
    void commitMaterialSpecificParams() final;

private:
    float _opacity{1.f}; // default opaque
};
}