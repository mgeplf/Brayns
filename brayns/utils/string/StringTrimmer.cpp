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

#include "StringTrimmer.h"

#include "StringInfo.h"

namespace brayns
{
std::string_view StringTrimmer::trimLeft(std::string_view data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (!StringInfo::isSpace(data[i]))
        {
            return data.substr(i);
        }
    }
    return {};
}

std::string_view StringTrimmer::trimRight(std::string_view data)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        auto index = data.size() - 1 - i;
        if (!StringInfo::isSpace(data[index]))
        {
            return data.substr(0, index + 1);
        }
    }
    return {};
}

std::string_view StringTrimmer::trim(std::string_view data)
{
    data = trimLeft(data);
    return trimRight(data);
}
} // namespace brayns
