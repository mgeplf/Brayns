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

from dataclasses import dataclass

from brayns.core.material.material import Material


@dataclass
class MockMaterial(Material):

    test1: str = ''
    test2: int = 0

    @classmethod
    @property
    def name(cls) -> str:
        return 'test'

    @classmethod
    def deserialize(cls, message: dict) -> 'MockMaterial':
        return cls._from_dict(
            message,
            test1=message['test1'],
            test2=message['test2']
        )

    def serialize(self) -> dict:
        return self._to_dict({
            'test1': self.test1,
            'test2': self.test2
        })