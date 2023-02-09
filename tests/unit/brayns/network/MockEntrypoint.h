/* Copyright (c) 2015-2023, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
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

#include <brayns/network/entrypoint/Entrypoint.h>

class MockEntrypoint : public brayns::Entrypoint<int, int>
{
public:
    MockEntrypoint(std::string method = "test", int reply = 0)
        : _method(std::move(method))
        , _reply(reply)
    {
    }

    bool hasBeenCalled() const
    {
        return _called;
    }

    virtual std::string getMethod() const override
    {
        return _method;
    }

    virtual std::string getDescription() const override
    {
        return "description";
    }

    virtual void onRequest(const Request &request) override
    {
        _called = true;
        request.reply(_reply);
    }

private:
    std::string _method;
    int _reply;
    bool _called = false;
};