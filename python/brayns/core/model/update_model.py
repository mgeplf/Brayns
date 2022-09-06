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

from brayns.network import Instance
from brayns.utils import Transform

from .model import Model


def update_model(
    instance: Instance,
    model_id: int,
    visible: bool | None = None,
    transform: Transform | None = None,
) -> Model:
    """Modify the properties of a given model and return its updated version.

    All unspecified values will be remain to their current state.

    :param instance: Instance.
    :type instance: Instance
    :param model_id: ID of the model to update.
    :type model_id: int
    :param visible: Model visibility, defaults to None
    :type visible: bool | None, optional
    :param transform: Model transformation, defaults to None
    :type transform: Transform | None, optional
    :return: Updated model.
    :rtype: Model
    """
    properties = {}
    if visible is not None:
        properties['is_visible'] = visible
    if transform is not None:
        properties['transform'] = transform.serialize()
    params = {
        'model_id': model_id,
        'model': properties,
    }
    result = instance.request('update-model', params)
    return Model.deserialize(result)