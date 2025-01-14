# Copyright (c) 2015-2023 EPFL/Blue Brain Project
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

import unittest
from pathlib import Path

import brayns


class TestImage(unittest.TestCase):
    def test_jpeg(self) -> None:
        path = "test/stuff/image.jpg"
        test = brayns.parse_image_format(path)
        self.assertIs(test, brayns.ImageFormat.JPEG)

    def test_png(self) -> None:
        path = "test/stuff/image.png"
        test = brayns.parse_image_format(path)
        self.assertIs(test, brayns.ImageFormat.PNG)

    def test_upper(self) -> None:
        path = "test/stuff/image.PNG"
        test = brayns.parse_image_format(path)
        self.assertIs(test, brayns.ImageFormat.PNG)

    def test_path(self) -> None:
        path = Path("test/stuff/image.png")
        test = brayns.parse_image_format(path)
        self.assertIs(test, brayns.ImageFormat.PNG)
