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

import unittest

from brayns.network.jsonrpc import (
    serialize_request,
    serialize_request_to_binary,
    serialize_request_to_text,
)

from .mock_messages import (
    mock_request,
    mock_request_binary,
    mock_request_message,
    mock_request_text,
)


class TestJsonRpcRequest(unittest.TestCase):
    def test_serialize_request(self) -> None:
        test = serialize_request(mock_request())
        self.assertEqual(test, mock_request_message())

    def test_serialize_request_notification(self) -> None:
        notification = mock_request()
        notification.id = None
        test = serialize_request(notification)
        ref = mock_request_message()
        del ref["id"]
        self.assertEqual(test, ref)

    def test_serialize_request_to_text(self) -> None:
        test = serialize_request_to_text(mock_request())
        self.assertEqual(test, mock_request_text())

    def test_serialize_request_to_binary(self) -> None:
        test = serialize_request_to_binary(mock_request(binary=True))
        self.assertEqual(test, mock_request_binary())

    def test_serialize_request_to_binary_no_binary(self) -> None:
        request = mock_request(binary=True)
        test = serialize_request_to_binary(request)
        self.assertEqual(test, mock_request_binary())
