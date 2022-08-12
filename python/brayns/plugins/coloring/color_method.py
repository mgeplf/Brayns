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

from enum import Enum


class ColorMethod(Enum):
    """Methods to color a circuit.

    Not all methods are available for all circuits, see `get_color_methods`.
    """

    ETYPE = 'etype'
    MTYPE = 'mtype'
    LAYER = 'layer'
    REGION = 'region'
    HEMISPHERE = 'hemisphere'
    MORPHOLOGY = 'morphology'
    MORPHOLOGY_CLASS = 'morphology class'
    MORPHOLOGY_SECTION = 'morphology section'
    SYNAPSE_CLASS = 'synapse class'
