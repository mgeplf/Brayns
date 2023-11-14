/* Copyright (c) 2015-2023, EPFL/Blue Brain Project
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

#include <brayns/json/Json.h>

namespace brayns
{
struct EmptyLoaderParams
{
};

template<>
struct JsonAdapter<EmptyLoaderParams>
{
    static JsonSchema getSchema()
    {
        auto schema = JsonSchema();
        schema.title = "EmptyLoaderParams";
        schema.type = JsonType::Undefined;
        return schema;
    }

    static void serialize(const EmptyLoaderParams &value, JsonValue &json)
    {
        (void)value;
        JsonFactory::emplaceObject(json);
    }

    static void deserialize(const JsonValue &json, EmptyLoaderParams &value)
    {
        (void)json;
        (void)value;
    }
};
} // namespace brayns
