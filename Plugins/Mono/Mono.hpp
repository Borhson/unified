#pragma once

#include "Plugin.hpp"
#include "API/Constants.hpp"
#include "API/Types.hpp"
#include <mono/jit/jit.h>

namespace Mono {

class Mono : public NWNXLib::Plugin
{
public:
    Mono(const Plugin::CreateParams& params);
    virtual ~Mono();

private:
    MonoDomain* m_Domain;
    MonoAssembly* m_Assembly;

    MonoMethod* m_PushScriptContext;
    MonoMethod* m_PopScriptContext;

    std::unordered_map<std::string, MonoMethod*> m_ScriptMap;

    bool RunMonoScript(const char* scriptName,
        NWNXLib::API::Types::ObjectID objId = NWNXLib::API::Constants::OBJECT_INVALID,
        bool valid = true);

    MonoMethod* GetScriptEntryFromClass(const char* className);
    MonoMethod* GetInternalHandler(const char* handler, int paramCount);
};

}
