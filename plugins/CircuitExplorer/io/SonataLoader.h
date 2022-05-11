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

#include <brayns/io/Loader.h>

#include <io/SonataLoaderParameters.h>

/**
 * @brief Imports one or multiple node and edge SONATA populations into Brayns
 */
class SonataLoader : public brayns::Loader<SonataLoaderParameters>
{
public:
    std::vector<std::string> getSupportedExtensions() const final;

    std::string getName() const final;

    std::vector<std::unique_ptr<brayns::Model>> importFromBlob(
        brayns::Blob &&blob,
        const brayns::LoaderProgress &cb,
        const SonataLoaderParameters &params) const final;

    std::vector<std::unique_ptr<brayns::Model>> importFromFile(
        const std::string &path,
        const brayns::LoaderProgress &callback,
        const SonataLoaderParameters &input) const final;
};