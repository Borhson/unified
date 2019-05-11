#pragma once

#include "Plugin.hpp"
#include "Services/Events/Events.hpp"
#include "API/Types.hpp"
#include "Services/Hooks/Hooks.hpp"

using ArgumentStack = NWNXLib::Services::Events::ArgumentStack;

namespace Layonara {

class Layonara : public NWNXLib::Plugin
{
public:
    Layonara(const Plugin::CreateParams& params);
    virtual ~Layonara();

private:
    static NWNXLib::API::CNWSItem *GetItemInSlotHook(NWNXLib::API::CNWSInventory*, uint32_t);
    NWNXLib::Hooking::FunctionHook* m_GetItemInSlotHook;

    ArgumentStack SetEquippableSlots      (ArgumentStack&& args);
    ArgumentStack SetHostileFeat          (ArgumentStack&& args);
};

}
