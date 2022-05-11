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

#include "CommonEdgeColorData.h"

#include <io/sonataloader/colordata/ColorDataExtractor.h>

#include <set>

namespace sonataloader
{
CommonEdgeColorData::CommonEdgeColorData(bbp::sonata::NodePopulation connectedNodes)
    : _nodes(std::move(connectedNodes))
{
}

std::vector<std::string> CommonEdgeColorData::getMethods() const noexcept
{
    return CellNodeColorMethods::get(_nodes);
}

std::vector<std::string> CommonEdgeColorData::getMethodVariables(const std::string &method) const
{
    const auto values = CellNodeColorValues::getAll(_nodes, method);
    const std::set<std::string> unique(values.begin(), values.end());
    return std::vector<std::string>(unique.begin(), unique.end());
}

std::vector<std::string> CommonEdgeColorData::getMethodValuesForIDs(
    const std::string &method,
    const std::vector<uint64_t> &ids) const
{
    return CellNodeColorValues::get(_nodes, method, ids);
}
} // namespace sonataloader