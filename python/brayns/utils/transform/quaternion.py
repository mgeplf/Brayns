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

from __future__ import annotations

import math
from collections.abc import Iterator
from dataclasses import dataclass

from ..vector import Vector, Vector3


@dataclass(frozen=True, order=True)
class Quaternion(Vector[float]):
    """Quaternion with XYZW components.

    Provides vector operations (componentwise) and quaternion special operators
    (multiplication, conjugate, etc).

    :param x: X component.
    :type x: float
    :param y: Y component.
    :type y: float
    :param z: Z component.
    :type z: float
    :param w: W component.
    :type w: float
    """

    x: float = 0.0
    y: float = 0.0
    z: float = 0.0
    w: float = 1.0

    @classmethod
    @property
    def identity(cls) -> Quaternion:
        return Quaternion()

    def __iter__(self) -> Iterator[float]:
        yield self.x
        yield self.y
        yield self.z
        yield self.w

    def __mul__(self, value: int | float | Quaternion) -> Quaternion:
        if isinstance(value, (int, float)):
            return self.unpack(i * value for i in self)
        x0, y0, z0, w0 = self
        x1, y1, z1, w1 = value
        return type(self)(
            w0 * x1 + x0 * w1 + y0 * z1 - z0 * y1,
            w0 * y1 - x0 * z1 + y0 * w1 + z0 * x1,
            w0 * z1 + x0 * y1 - y0 * x1 + z0 * w1,
            w0 * w1 - x0 * x1 - y0 * y1 - z0 * z1
        )

    def __rmul__(self, value: int | float | Quaternion) -> Quaternion:
        if isinstance(value, (int, float)):
            return self * value
        return value * self

    def __truediv__(self, value: int | float | Quaternion) -> Quaternion:
        if isinstance(value, (int, float)):
            return self.unpack(i / value for i in self)
        return self * value.inverse

    def __rtruediv__(self, value: int | float | Quaternion) -> Quaternion:
        if isinstance(value, (int, float)):
            return self.unpack(value / i for i in self)
        return value * self.inverse

    @property
    def axis(self) -> Vector3:
        return Vector3(self.x, self.y, self.z)

    @property
    def angle_radians(self) -> float:
        q = self.normalized
        return 2 * math.acos(q.w)

    @property
    def angle_degrees(self) -> float:
        return math.degrees(self.angle_radians)

    @property
    def conjugate(self) -> Quaternion:
        return type(self)(-self.x, -self.y, -self.z, self.w)

    @property
    def inverse(self) -> Quaternion:
        return self.conjugate / self.square_norm