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

from brayns.core.view.view import View


@dataclass
class KeyFrame:

    index: int
    view: View | None = None

    @staticmethod
    def from_indices(indices: list[int], view: View | None = None) -> list[KeyFrame]:
        return [
            KeyFrame(index, view)
            for index in indices
        ]

    def serialize(self) -> dict[str, Any]:
        message: dict[str, Any] = {
            'frame_index': self.index,
        }
        if self.view is not None:
            message['camera_view'] = self.view.serialize()
        return message
