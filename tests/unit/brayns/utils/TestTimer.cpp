/* Copyright (c) 2015-2023, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
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

#include <brayns/utils/Timer.h>

#include <doctest/doctest.h>

#include <thread>

TEST_CASE("Timer")
{
    auto timer = brayns::Timer();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    CHECK(timer.seconds() == 1);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    CHECK(timer.seconds() == 2);

    timer.reset();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    CHECK(timer.seconds() == 1);
}
