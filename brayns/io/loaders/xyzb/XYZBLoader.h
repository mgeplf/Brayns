/* Copyright (c) 2015-2022, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Cyrille Favreau <cyrille.favreau@epfl.ch>
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

#include <brayns/io/Loader.h>

namespace brayns
{
class XYZBLoader : public NoInputLoader
{
public:
    std::vector<std::string> getSupportedExtensions() const final;

    std::string getName() const final;

    std::vector<std::unique_ptr<Model>> importFromBlob(Blob &&blob, const LoaderProgress &callback) const final;

    std::vector<std::unique_ptr<Model>> importFromFile(const std::string &filename, const LoaderProgress &callback)
        const final;
};
} // namespace brayns