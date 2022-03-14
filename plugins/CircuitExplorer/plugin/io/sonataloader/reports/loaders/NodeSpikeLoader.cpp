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

#include "NodeSpikeLoader.h"

// libsonata uses nonstd::optional which, if available, becomes std::optional
// however, libsonata is compiled enforcing c++14, so their type is always nonstd::optional
// then, symbol lookup errors happen
#define optional_CONFIG_SELECT_OPTIONAL optional_OPTIONAL_NONSTD
#include <bbp/sonata/report_reader.h>

namespace sonataloader
{
std::vector<NodeReportMapping> NodeSpikeLoader::loadMapping(
    const std::string &reportPath,
    const std::string &population,
    const bbp::sonata::Selection &s) const
{
    (void)reportPath;
    (void)population;

    std::vector<NodeReportMapping> mapping(s.flatSize());
    for (size_t i = 0; i < mapping.size(); ++i)
        mapping[i].globalOffset = i;
    return mapping;
}
} // namespace sonataloader
