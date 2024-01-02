#ifndef DEFAULT_ADAPTER_H
#define DEFAULT_ADAPTER_H

#include <string>
#include <vector>

#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

#include "memory_adapter.h"

namespace wmml
{
    /**
     * @brief DefaultAdapter is a default implementation of MemoryAdapter.
     *        It uses ReadProcessMemory and WriteProcessMemory to read and write memory.
     */
    struct DefaultAdapter : public MemoryAdapter
    {
        DefaultAdapter() = default;
        ~DefaultAdapter() = default;

        virtual SIZE_T Read(const LPCVOID address, LPVOID buffer, SIZE_T size) const override;
        virtual SIZE_T Write(const LPVOID address, LPCVOID buffer, SIZE_T size) const override;

        virtual bool EnumerateModules(std::vector<std::unique_ptr<Module>>& modules) const override;

        HANDLE process_handle_ = nullptr;
        static constexpr int kMaxModuleHandles = 1024;

    }; // struct DefaultAdapter

} // namespace wmml

#endif // DEFAULT_ADAPTER_H