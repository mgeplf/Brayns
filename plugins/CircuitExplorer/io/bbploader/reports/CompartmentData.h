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

#include <api/reports/IReportData.h>
#include <api/reports/ReportMapping.h>

#include <brion/compartmentReport.h>

namespace bbploader
{
class CompartmentData : public IReportData
{
public:
    CompartmentData(std::unique_ptr<brion::CompartmentReport> report);

    size_t getFrameSize() const noexcept override;

    float getStartTime() const noexcept override;

    float getEndTime() const noexcept override;

    float getTimeStep() const noexcept override;

    std::string getTimeUnit() const noexcept override;

    std::vector<float> getFrame(const uint32_t frameIndex) const override;

    /**
     * @brief Computes and returns the report mapping
     *
     * @return std::vector<CellReportMapping>
     */
    std::vector<CellReportMapping> computeMapping() const noexcept;

private:
    const std::unique_ptr<brion::CompartmentReport> _report;
};
}