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

import brayns
from testapi.simple_test_case import SimpleTestCase


class TestCameraView(SimpleTestCase):

    def test_from_instance(self) -> None:
        test = brayns.CameraView.from_instance(self.instance)
        ref = brayns.CameraView(
            target=brayns.Vector3.forward
        )
        self.assertEqual(test, ref)

    def test_use_for_main_camera(self) -> None:
        view = brayns.CameraView(
            position=brayns.Vector3(1, 2, 3),
            target=brayns.Vector3(4, 5, 6),
            up=brayns.Vector3(7, 8, 9)
        )
        view.use_for_main_camera(self.instance)
        ref = brayns.CameraView.from_instance(self.instance)
        self.assertEqual(view, ref)