/* Copyright (c) 2015-2021 EPFL/Blue Brain Project
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

#include "ConnectionRef.h"

#include <brayns/common/Log.h>

namespace brayns
{
ConnectionRef::ConnectionRef(ConnectionHandle handle, ConnectionManager &connections)
    : _handle(std::move(handle))
    , _connections(&connections)
{
}

const ConnectionHandle &ConnectionRef::getHandle() const
{
    return _handle;
}

void ConnectionRef::send(const OutputPacket &packet) const
{
    if (!_connections)
    {
        return;
    }
    try
    {
        _connections->send(_handle, packet);
    }
    catch (...)
    {
        Log::error("Unexpected error during sending request.");
    }
}

void ConnectionRef::broadcast(const OutputPacket &packet) const
{
    if (!_connections)
    {
        return;
    }
    try
    {
        _connections->broadcast(packet);
    }
    catch (...)
    {
        Log::error("Unexpected error during broadcast.");
    }
}

void ConnectionRef::broadcastToOtherClients(const OutputPacket &packet) const
{
    if (!_connections)
    {
        return;
    }
    try
    {
        _connections->broadcast(_handle, packet);
    }
    catch (...)
    {
        Log::error("Unexpected error during broadcast to others.");
    }
}
} // namespace brayns
