#include "default_adapter.h"

namespace wmml
{
    SIZE_T DefaultAdapter::Read(const LPCVOID address, LPVOID buffer, SIZE_T size) const
    {
        SIZE_T buffer_length = 0;

        BOOL result = ReadProcessMemory(this->process_handle_, 
                                        address,
                                        buffer,
                                        size,
                                        &buffer_length);

        if(result == FALSE)
        {
            return NULL;
        }

        return buffer_length;
    }

    SIZE_T DefaultAdapter::Write(const LPVOID address, LPCVOID buffer, SIZE_T size) const
    {
        SIZE_T buffer_length = 0;

        BOOL result = WriteProcessMemory(this->process_handle_,
                                         address,
                                         buffer,
                                         size,
                                         &buffer_length);

        if(result == FALSE)
        {
            return NULL;
        }

        return buffer_length;
    }

    bool DefaultAdapter::EnumerateModules(std::vector<std::unique_ptr<Module>>& modules) const
    {
        HMODULE module_handles[this->kMaxModuleHandles];
        DWORD module_handles_size = 0;

        BOOL result = EnumProcessModules(this->process_handle_,
                                         module_handles,
                                         sizeof(module_handles),
                                         &module_handles_size);

        if(result == FALSE)
        {
            return false;
        }

        for(DWORD i = 0; i < module_handles_size / sizeof(HMODULE); i++)
        {
            TCHAR module_name[MAX_PATH];
            DWORD module_name_size = GetModuleFileNameEx(this->process_handle_,
                                                         module_handles[i],
                                                         module_name,
                                                         sizeof(module_name));

            if(module_name_size == 0)
            {
                continue;
            }

            MODULEINFO module_info;
            BOOL result = GetModuleInformation(this->process_handle_,
                                               module_handles[i],
                                               &module_info,
                                               sizeof(module_info));

            if(result == FALSE)
            {
                continue;
            }

            std::unique_ptr<Module> new_module = std::make_unique<Module>(module_name,
                                                                          module_info.lpBaseOfDll,
                                                                          module_info.SizeOfImage);

            modules.push_back(std::move(new_module));
        }

        return true;
    }


} // namespace wmml
