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

import unittest

import brayns


class TestBbpCellsCli(unittest.TestCase):

    def test_parse(self) -> None:
        test = brayns.BbpCellsCli(
            density=0.5,
            targets=['1', '2'],
            gids=[1, 2],
        )
        args = [
            '--density',
            '0.6',
            '--targets',
            '3',
            '4',
            '--gids',
            '3',
            '4',
        ]
        test.parse(args)
        self.assertEqual(test.density, 0.6)
        self.assertEqual(test.targets, ['3', '4'])
        self.assertEqual(test.gids, [3, 4])

    def test_create_cells(self) -> None:
        cli = brayns.BbpCellsCli(density=1)
        test = cli.create_cells()
        ref = brayns.BbpCells.from_density(1)
        self.assertEqual(test, ref)


if __name__ == '__main__':
    unittest.main()