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

#include "AtlasExplorerPlugin.h"

#include <brayns/network/entrypoint/EntrypointBuilder.h>
#include <brayns/utils/Log.h>

#include <io/NRRDLoader.h>

#include <network/entrypoints/GetAvailableAtlasUseCasesEntrypoint.h>
#include <network/entrypoints/VisualizeAtlasUseCaseEntrypoint.h>

AtlasExplorerPlugin::AtlasExplorerPlugin(brayns::PluginAPI &api)
{
    auto name = "Atlas Explorer";

    auto &registry = api.getLoaderRegistry();
    auto loaders = brayns::LoaderRegistryBuilder(name, registry);

    loaders.add<NRRDLoader>();

    auto interface = api.getNetworkInterface();
    if (!interface)
    {
        return;
    }

    auto &engine = api.getEngine();
    auto &scene = engine.getScene();
    auto &models = scene.getModels();
    auto entrypoints = brayns::EntrypointBuilder(name, *interface);

    entrypoints.add<GetAvailableAtlasUseCasesEntrypoint>(models);
    entrypoints.add<VisualizeAtlasUseCaseEntrypoint>(models);
}

extern "C" std::unique_ptr<brayns::IPlugin> brayns_create_plugin(brayns::PluginAPI &api)
{
    brayns::Log::info("[AtlasExplorer] Loading Atlas Explorer plugin.");
    return std::make_unique<AtlasExplorerPlugin>(api);
}
