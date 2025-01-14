/* Copyright (c) 2015-2023 EPFL/Blue Brain Project
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

#pragma once

#include <brayns/network/entrypoint/EntrypointRef.h>
#include <brayns/network/jsonrpc/JsonRpcRequest.h>

#include "ITask.h"

namespace brayns
{
class JsonRpcTask : public ITask
{
public:
    /**
     * @brief Construct a task to process the given JSON-RPC request.
     *
     * @param request JSON-RPC request to process.
     * @param entrypoint Entrypoint used to process request.
     */
    explicit JsonRpcTask(JsonRpcRequest request, EntrypointRef &entrypoint);

    /**
     * @brief Get the client who sent the request.
     *
     * @return const ClientRef& Client ref.
     */
    const ClientRef &getClient() const override;

    /**
     * @brief Get the request ID.
     *
     * @return const RequestId& JSON-RPC request ID.
     */
    const RequestId &getId() const override;

    /**
     * @brief Get the method.
     *
     * @return const std::string& JSON-RPC method.
     */
    const std::string &getMethod() const override;

    /**
     * @brief Check if entrypoint has priority.
     *
     * @return true High priority.
     * @return false Normal priority.
     */
    bool hasPriority() const override;

    /**
     * @brief Process request using entrypoint.
     *
     */
    void run() override;

    /**
     * @brief Notify running entrypoint of cancellation.
     *
     */
    void cancel() override;

    /**
     * @brief Notify running entrypoint of disconnection.
     *
     */
    void disconnect() override;

private:
    JsonRpcRequest _request;
    EntrypointRef &_entrypoint;
    bool _running = false;
    bool _cancelled = false;
    bool _disconnected = false;
};
} // namespace brayns
