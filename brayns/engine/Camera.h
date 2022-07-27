/* Copyright (c) 2015-2022, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Cyrille Favreau <cyrille.favreau@epfl.ch>
 *                     Jafet Villafranca <jafet.villafrancadiaz@epfl.ch>
 *                     Nadir Roman Guerrero <nadir.romanguerrero@epfl.ch>
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
#include <brayns/common/ModifiedFlag.h>
#include <brayns/json/JsonAdapterMacro.h>

#include <ospray/ospray_cpp/Camera.h>

#include <memory>
#include <string_view>

namespace brayns
{
struct LookAt
{
    Vector3f position{0.f};
    Vector3f target{0.f, 0.f, 1.f};
    Vector3f up{0.f, 1.f, 0.f};
};

BRAYNS_JSON_ADAPTER_BEGIN(LookAt)
BRAYNS_JSON_ADAPTER_ENTRY(position, "Position of the camera")
BRAYNS_JSON_ADAPTER_ENTRY(target, "Target position at which the camera is looking")
BRAYNS_JSON_ADAPTER_ENTRY(up, "Up vector to compute the camera orthonormal basis")
BRAYNS_JSON_ADAPTER_END()

bool operator==(const LookAt &a, const LookAt &b) noexcept;
bool operator!=(const LookAt &a, const LookAt &b) noexcept;

class Camera
{
public:
    Camera(const std::string &handleID);

    Camera(const Camera &) = delete;
    Camera &operator=(const Camera &) = delete;

    Camera(Camera &&) = delete;
    Camera &operator=(Camera &&) = delete;

    virtual ~Camera() = default;

    /**
     * @brief Returns the camera type as a string
     */
    virtual std::string getName() const noexcept = 0;

    /**
     * @brief Creates a copy of the current camera
     *
     * @return std::unique_ptr<Camera>
     */
    virtual std::unique_ptr<Camera> clone() const noexcept = 0;

    /**
     * @brief Commit implementation. Derived camera types must override commitCameraSpecificParams(),
     * which will be called during commit() to perform camera-specific synchronization with Ospray
     * @returns true if there was anything to commit
     */
    bool commit();

    /**
     * @brief Sets the look-at parameters of the camera
     * @param params LookAt
     */
    void setLookAt(const LookAt &params) noexcept;

    /**
     * @brief Returns the look-at parameters of the camera
     * @return const LookAt &
     */
    const LookAt &getLookAt() const noexcept;

    /**
     * @brief Sets the resolution aspect ratio on to which this camera will be generating rays
     */
    void setAspectRatio(const float aspectRatio) noexcept;

    /**
     * @brief Get the Aspect Ratio of the camera
     *
     * @return float
     */
    float getAspectRatio() const noexcept;

    /**
     * @brief Returns the Ospray Object of this camera
     */
    const ospray::cpp::Camera &getOsprayCamera() const noexcept;

protected:
    /**
     * @brief Returns the modified flag status object
     */
    ModifiedFlag &getModifiedFlag() noexcept;

    /**
     * @brief Subclasses of the Camera must implement this method to set camera type specific parameters.
     */
    virtual void commitCameraSpecificParams() = 0;

private:
    LookAt _lookAtParams;
    float _aspectRatio{1.f};
    ospray::cpp::Camera _osprayCamera;
    ModifiedFlag _flag;
};
} // namespace brayns
