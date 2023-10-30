/* If not stated otherwise in this file or this component's LICENSE file the
# following copyright and licenses apply:
#
# Copyright 2023 Synamedia
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
*/

#ifndef DOBBYENV_H
#define DOBBYENV_H

#include "IDobbyEnv.h"
#include <IDobbySettings.h>

#include <cstdint>
#include <string>
#include <memory>


class DobbyEnvImpl {
public:
    virtual ~DobbyEnvImpl() = default;
    virtual std::string workspaceMountPath() const = 0;
    virtual std::string flashMountPath() const = 0;
    virtual std::string pluginsWorkspacePath() const = 0;
    virtual uint16_t platformIdent() const = 0;
};

class DobbyEnv {

protected:
    static DobbyEnvImpl* impl;

public:

    DobbyEnv() {}
    ~DobbyEnv() {}

    DobbyEnv(const std::shared_ptr<const IDobbySettings>& settings){}
    
    static void setImpl(DobbyEnvImpl* newImpl)
    {
        impl = newImpl;
    }

    static DobbyEnv* getInstance()
    {
        static DobbyEnv* instance = nullptr;
        if (nullptr != instance)
        {
           instance = new DobbyEnv();
        }
        return instance;
    }

    static std::string workspaceMountPath()
    {
       return impl->workspaceMountPath();
    }

    static std::string flashMountPath()
    {
       return impl->flashMountPath();
    }

    static std::string pluginsWorkspacePath()
    {
       return impl->pluginsWorkspacePath();
    }

    static uint16_t platformIdent()
    {
       return impl->platformIdent();
    }

};

#endif // !defined(DOBBYENV_H)
