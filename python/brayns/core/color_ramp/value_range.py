# Copyright (c) 2015-2022 EPFL/Blue Brain Project
# All rights reserved. Do not distribute without permission.
#
# Responsible Author: adrien.fleury@epfl.ch
#
# This file is part of Brayns <https://github.com/BlueBrain/Brayns>
#
# This library is free software; you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License version 3.0 as published
# by the Free Software Foundation.
#
# This library is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this library; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

from collections.abc import Iterator
from dataclasses import dataclass

from brayns.utils import Vector


@dataclass(frozen=True, order=True)
class ValueRange(Vector):
    """Specify color ramp value range.

    Usually the simulation values are voltages but it can be anything.

    :param min: Minimal simulation value.
    :type min: float
    :param max: Maximal simulation value.
    :type max: float
    """

    min: float
    max: float

    def __iter__(self) -> Iterator[float]:
        """Iterate over min and max.

        :yield: Value range.
        :rtype: Iterator[float]
        """
        yield self.min
        yield self.max

    @property
    def size(self) -> float:
        """Get the difference between min and max.

        :return: Value range.
        :rtype: float
        """
        return self.max - self.min

    def normalize(self, value: float) -> float:
        """Normalize given value between min and max.

        Result is not clamped between min and max.

        For example a value of 5 with min = 0 and max = 10 gives 0.5.

        :param value: Simulation value.
        :type value: float
        :return: Normalized simulation value.
        :rtype: float
        """
        return (value - self.min) / self.size