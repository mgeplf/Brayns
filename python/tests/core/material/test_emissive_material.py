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

import unittest

import brayns


class TestEmissiveMaterial(unittest.TestCase):

    def setUp(self) -> None:
        self._material = brayns.EmissiveMaterial(
            intensity=2
        )
        self._message = {
            'intensity': 2
        }

    def test_name(self) -> None:
        self.assertEqual(brayns.EmissiveMaterial.name, 'emissive')

    def test_deserialize(self) -> None:
        test = brayns.EmissiveMaterial.deserialize(self._message)
        self.assertEqual(test, self._material)

    def test_serialize(self) -> None:
        test = self._material.serialize()
        self.assertEqual(test, self._message)


if __name__ == '__main__':
    unittest.main()
