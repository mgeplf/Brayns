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

from typing import TypeVar

from brayns.network import Instance

from ..model import Model
from .geometry import Geometry

T = TypeVar('T', bound=Geometry)


def add_geometries(instance: Instance, geometries: list[T]) -> Model:
    """Add a list of geometries to an instance as a single model.

    All geometries must have the same type.

    Empty models (no geometries) are not supported.

    :param instance: Instance.
    :type instance: Instance
    :param geometries: Geometries to add (boxes, capsules, etc...).
    :type geometries: list[T]
    :raises ValueError: List is empty.
    :return: Model created from the geometries.
    :rtype: Model
    """
    if not geometries:
        raise ValueError('Creation of an empty model is not supported')
    method = geometries[0].method
    params = [
        {
            'geometry': geometry.serialize(),
            'color': list(geometry.color),
        }
        for geometry in geometries
    ]
    result = instance.request(method, params)
    return Model.deserialize(result)