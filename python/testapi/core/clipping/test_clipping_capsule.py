# Copyright (c) 2015-2023 EPFL/Blue Brain Project
# All rights reserved. Do not distribute without permission.
# Responsible Author: Nadir Roman Guerrero <nadir.romanguerrero@epfl.ch>
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

import brayns

from .clipping_test_case import ClippingTestCase


class TestClippingCapsule(ClippingTestCase):
    def test_all(self) -> None:
        rotation = brayns.Rotation.from_euler(brayns.Vector3(0, 45, 0), True)
        start = rotation.apply(brayns.Vector3(0, 0, 9))
        end = rotation.apply(brayns.Vector3(0, 10, 9))
        capsule = brayns.ClippingCapsule(start, 7, end, 3)
        self.run_list_tests(capsule)
