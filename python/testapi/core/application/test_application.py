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


class TestApplication(SimpleTestCase):

    def test_from_instance(self) -> None:
        application = brayns.Application.from_instance(self.instance)
        launcher = self.create_launcher()
        self.assertEqual(application.plugins, [
            plugin.value
            for plugin in launcher.plugins
        ])
        self.assertEqual(application.resolution, launcher.resolution)
        self.assertEqual(application.jpeg_quality, launcher.jpeg_quality)

    def test_update(self) -> None:
        brayns.Application.update(
            self.instance,
            resolution=brayns.Resolution.ultra_hd,
            jpeg_quality=60
        )
        test = brayns.Application.from_instance(self.instance)
        self.assertEqual(test.resolution, brayns.Resolution.ultra_hd)
        self.assertEqual(test.jpeg_quality, 60)