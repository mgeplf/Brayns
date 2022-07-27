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

from collections.abc import Iterator
from typing import Any, Optional

from brayns.instance.jsonrpc.json_rpc_id import JsonRpcId
from brayns.instance.jsonrpc.json_rpc_task import JsonRpcTask
from brayns.instance.request_error import RequestError
from brayns.instance.request_progress import RequestProgress


class JsonRpcTasks:

    def __init__(self) -> None:
        self._tasks: dict[JsonRpcId, JsonRpcTask] = {}

    def __len__(self) -> int:
        return len(self._tasks)

    def __iter__(self) -> Iterator[tuple[JsonRpcId, JsonRpcTask]]:
        yield from self._tasks.items()

    def __contains__(self, id: JsonRpcId) -> bool:
        return id in self._tasks

    def find(self, id: JsonRpcId) -> Optional[JsonRpcTask]:
        return self._tasks.get(id)

    def create_task(self, id: Optional[JsonRpcId]) -> JsonRpcTask:
        if id is None:
            return JsonRpcTask.from_result(None)
        if id in self._tasks:
            raise RuntimeError('Request with same ID already running')
        task = JsonRpcTask()
        self._tasks[id] = task
        return task

    def add_result(self, id: JsonRpcId, result: Any) -> None:
        task = self.find(id)
        if task is None:
            return
        task.set_result(result)
        del self._tasks[id]

    def add_error(self, id: Optional[JsonRpcId], error: RequestError) -> None:
        if id is None:
            self.add_global_error(error)
            return
        task = self.find(id)
        if task is None:
            return
        task.set_error(error)
        del self._tasks[id]

    def add_global_error(self, error: RequestError) -> None:
        for task in self._tasks.values():
            task.set_error(error)
        self._tasks.clear()

    def add_progress(self, id: JsonRpcId, progress: RequestProgress) -> None:
        task = self.find(id)
        if task is None:
            return
        task.add_progress(progress)