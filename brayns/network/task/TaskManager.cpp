/* Copyright (c) 2015-2022 EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 *
 * Responsible Author: adrien.fleury@epfl.ch
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "TaskManager.h"

#include <brayns/common/Log.h>

#include <brayns/network/jsonrpc/JsonRpcException.h>

namespace brayns
{
void TaskManager::add(std::unique_ptr<ITask> task)
{
    auto &method = task->getMethod();
    if (task->hasPriority())
    {
        Log::debug("Task '{}' has priority.", method);
        task->run();
        return;
    }
    Log::debug("Task '{}' queued for execution.", method);
    _tasks.push_back(std::move(task));
}

void TaskManager::runAllTasks()
{
    while (!_tasks.empty())
    {
        auto count = _tasks.size();
        Log::debug("Flushing task queue, {} remaining.", count);
        auto &task = *_tasks.front();
        task.run();
        _tasks.pop_front();
    }
}

void TaskManager::cancel(const ClientRef &client, const RequestId &id)
{
    if (id.isEmpty())
    {
        throw brayns::InvalidParamsException("Empty task ID");
    }
    bool found = false;
    for (const auto &task : _tasks)
    {
        if (task->getClient() != client || task->getId() != id)
        {
            continue;
        }
        task->cancel();
        found = true;
    }
    if (!found)
    {
        auto text = id.getDisplayText();
        throw brayns::TaskNotFoundException(text);
    }
}
} // namespace brayns