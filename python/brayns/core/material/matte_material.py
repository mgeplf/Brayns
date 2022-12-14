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
from typing import Any

from .material import Material


@dataclass
class MatteMaterial(Material):
    """Matte material.

    :param opacity: Opacity (0-1), defaults to fully opaque.
    :type opacity: float, optional
    """

    opacity: float = 1.0

    @classmethod
    @property
    def name(cls) -> str:
        """Get the material name.

        :return: Material name
        :rtype: str
        """
        return "matte"

    def get_properties(self) -> dict[str, Any]:
        """Low level API to serialize to JSON."""
        return {"opacity": self.opacity}

    def update_properties(self, message: dict[str, Any]) -> None:
        """Low level API to deserialize from JSON."""
        self.opacity = message["opacity"]
