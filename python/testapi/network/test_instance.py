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

import brayns
from testapi.simple_test_case import SimpleTestCase


class TestInstance(SimpleTestCase):

    def test_context(self) -> None:
        with self.instance as instance:
            instance.poll(block=False)
        self.assertFalse(instance.connected)

    def test_connected(self) -> None:
        self.assertTrue(self.instance.connected)
        self.instance.disconnect()
        self.assertFalse(self.instance.connected)

    def test_disconnect(self) -> None:
        self.instance.disconnect()
        self.assertFalse(self.instance.connected)
        with self.assertRaises(brayns.WebSocketError):
            self.instance.request('test', 123)

    def test_request(self) -> None:
        test = self.instance.request('schema', {'endpoint': 'get-version'})
        self.assertIsInstance(test, dict)
        self.assertTrue(test)
        with self.assertRaises(brayns.RequestError):
            self.instance.request('invalid')

    def test_task(self) -> None:
        task = self.instance.task('snapshot', {})
        progresses = list(task)
        result = task.wait_for_result()
        self.assertTrue(progresses)
        self.assertIsInstance(result, dict)
        self.assertTrue(result)

    def test_is_running(self) -> None:
        request = brayns.Request(0, 'registry')
        task = self.instance.send(request)
        self.assertTrue(self.instance.is_running(0))
        task.wait_for_result()

    def test_send(self) -> None:
        string = brayns.Request('test', 'registry')
        task = self.instance.send(string)
        task.wait_for_result()
        integer = brayns.Request(0, 'registry')
        task = self.instance.send(integer)
        task.wait_for_result()
        notification = brayns.Request(None, 'registry')
        task = self.instance.send(notification)
        task.wait_for_result()

    def test_poll(self) -> None:
        task = self.instance.task('registry')
        self.instance.poll()
        self.assertTrue(task.is_ready())
        task.wait_for_result()

    def test_cancel(self) -> None:
        request = brayns.Request(0, 'snapshot', {})
        task = self.instance.send(request)
        self.instance.cancel(0)
        with self.assertRaises(brayns.RequestError):
            task.wait_for_result()
