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

from brayns.utils import Error


@dataclass
class RequestError(Error):
    """Error raised by an instance when a request fails.

    :param code: Error code.
    :type code: int
    :param message: Error description.
    :type message: str
    :param data: Optional additional error information.
    :type data: Any, optional
    """

    code: int
    message: str
    data: Any = None

    def __str__(self) -> str:
        description = f'{self.message} (code={self.code})'
        if self.data is None:
            return description
        return f'{description} (data={self.data})'