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

from brayns.core.camera.perspective_camera import PerspectiveCamera
from brayns.core.image.resolution import Resolution
from brayns.core.renderer.production_renderer import ProductionRenderer
from brayns.core.snapshot.frame_exporter import FrameExporter
from brayns.core.image.image_format import ImageFormat
from brayns.core.snapshot.key_frame import KeyFrame
from brayns.core.view.view import View
from tests.instance.mock_instance import MockInstance


class TestFrameExporter(unittest.TestCase):

    def test_export_frames(self) -> None:
        instance = MockInstance()
        path = 'test'
        frames = KeyFrame.from_indices([0, 1])
        exporter = FrameExporter(frames)
        ref = exporter.serialize(path)
        exporter.export_frames(instance, path)
        self.assertEqual(instance.method, 'export-frames')
        self.assertEqual(instance.params, ref)

    def test_serialize(self) -> None:
        exporter = FrameExporter(
            frames=KeyFrame.from_indices([0, 1], View()),
            format=ImageFormat.JPEG,
            jpeg_quality=50,
            resolution=Resolution(600, 900),
            camera=PerspectiveCamera(),
            renderer=ProductionRenderer()
        )
        path = 'test'
        ref = {
            'path': path,
            'key_frames': [
                {
                    'frame_index': 0,
                    'camera_view': View().serialize()
                },
                {
                    'frame_index': 1,
                    'camera_view': View().serialize()
                }
            ],
            'image_settings': {
                'format': 'jpg',
                'quality': 50,
                'size': [600, 900]
            },
            'camera': PerspectiveCamera().serialize_with_name(),
            'renderer': ProductionRenderer().serialize_with_name()
        }
        test = exporter.serialize(path)
        self.assertEqual(test, ref)


if __name__ == '__main__':
    unittest.main()
