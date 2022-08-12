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

from dataclasses import dataclass
from typing import Any


@dataclass(frozen=True)
class BbpCells:
    """BlueConfig cells selection.

    Use one of the factory methods to create this object.
    """

    density: float | None = None
    targets: list[str] | None = None
    gids: list[int] | None = None

    @staticmethod
    def all() -> BbpCells:
        """Select all cells from a circuit."""
        return BbpCells.from_density(1.0)

    @staticmethod
    def from_density(density: float) -> BbpCells:
        """Select only a proportion of cells (0 = None, 1 = all)."""
        return BbpCells(density=density)

    @staticmethod
    def from_targets(targets: list[str], density: float = 1.0) -> BbpCells:
        """Select only the cells from a given target.

        The density of cells to load per target can also be specified.
        """
        return BbpCells(density=density, targets=targets)

    @staticmethod
    def from_gids(gids: list[int]) -> BbpCells:
        """Select cells using their GIDs."""
        return BbpCells(gids=gids)

    def serialize(self) -> dict[str, Any]:
        """Low level API to serialize to JSON."""
        message = {}
        if self.density is not None:
            message['percentage'] = self.density
        if self.targets is not None:
            message['targets'] = self.targets
        if self.gids is not None:
            message['gids'] = self.gids
        return message
