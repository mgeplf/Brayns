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

from typing import Any

from brayns.network import Instance
from brayns.utils import Resolution

from .application import Application


def get_application(instance: Instance) -> Application:
    """Retreive the application parameters from an instance.

    :param instance: Instance.
    :type instance: Instance
    :return: Current application parameters.
    :rtype: Application
    """
    result = instance.request("get-application-parameters")
    return _deserialize_application(result)


def _deserialize_application(message: dict[str, Any]) -> Application:
    return Application(
        plugins=message["plugins"],
        resolution=Resolution(*message["viewport"]),
    )
