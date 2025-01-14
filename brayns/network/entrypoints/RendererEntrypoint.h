/* Copyright (c) 2015-2023 EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 *
 * Responsible Author: adrien.fleury@epfl.ch
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

#include <brayns/engine/core/Engine.h>
#include <brayns/engine/json/adapters/RendererAdapters.h>

#include <brayns/network/entrypoint/Entrypoint.h>

namespace brayns
{
class GetRendererTypeEntrypoint final : public Entrypoint<EmptyJson, std::string>
{
public:
    explicit GetRendererTypeEntrypoint(Engine &engine);

    std::string getMethod() const override;
    std::string getDescription() const override;

    void onRequest(const Request &request) override;

private:
    Engine &_engine;
};

template<typename T>
class SetRendererEntrypoint : public Entrypoint<T, EmptyJson>
{
public:
    using Request = typename Entrypoint<T, EmptyJson>::Request;

    explicit SetRendererEntrypoint(Engine &engine):
        _engine(engine)
    {
    }

    virtual void onRequest(const Request &request) override
    {
        auto &renderer = _engine.getRenderer();
        T data;
        if (auto cast = renderer.as<T>())
        {
            data = *cast;
        }
        request.getParams(data);
        renderer.set(data);
        request.reply(EmptyJson());
    }

private:
    Engine &_engine;
};

class SetRendererInteractiveEntrypoint final : public SetRendererEntrypoint<Interactive>
{
public:
    explicit SetRendererInteractiveEntrypoint(Engine &engine);

    std::string getMethod() const override;
    std::string getDescription() const override;
};

class SetRendererProductionEntrypoint final : public SetRendererEntrypoint<Production>
{
public:
    explicit SetRendererProductionEntrypoint(Engine &engine);

    std::string getMethod() const override;
    std::string getDescription() const override;
};

template<typename T>
class GetRendererEntrypoint : public Entrypoint<EmptyJson, T>
{
public:
    using Request = typename Entrypoint<EmptyJson, T>::Request;

    explicit GetRendererEntrypoint(Engine &engine):
        _engine(engine)
    {
    }

    void onRequest(const Request &request) override
    {
        auto &renderer = _engine.getRenderer();
        if (auto cast = renderer.as<T>())
        {
            request.reply(*cast);
            return;
        }

        throw InvalidRequestException("Invalid renderer type (should be '" + renderer.getName() + "')");
    }

private:
    Engine &_engine;
};

class GetRendererInteractiveEntrypoint final : public GetRendererEntrypoint<Interactive>
{
public:
    explicit GetRendererInteractiveEntrypoint(Engine &engine);

    std::string getMethod() const override;
    std::string getDescription() const override;
};

class GetRendererProductionEntrypoint final : public GetRendererEntrypoint<Production>
{
public:
    explicit GetRendererProductionEntrypoint(Engine &engine);

    std::string getMethod() const override;
    std::string getDescription() const override;
};
} // namespace brayns
