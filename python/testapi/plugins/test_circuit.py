# Copyright (c) 2015-2023 EPFL/Blue Brain Project
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

import brayns
from testapi.loading import load_circuit, load_neurons
from testapi.render import render_and_validate
from testapi.simple_test_case import SimpleTestCase


class TestGetCircuitIds(SimpleTestCase):
    def test_get_circuit_ids(self) -> None:
        model = load_circuit(self)
        ids = brayns.get_circuit_ids(self.instance, model.id)
        self.assertEqual(ids, list(range(1, 1001)))

    def test_set_circuit_thickness(self) -> None:
        model = load_neurons(self, [1])
        brayns.set_circuit_thickness(self.instance, model.id, 5)
        render_and_validate(self, "set_circuit_thickness")
