#ifndef DEFAULT_ADAPTER_H
#define DEFAULT_ADAPTER_H

#include <Windows.h>

#include "memory_adapter.h"

namespace wmml
{
    struct DefaultAdapter : public MemoryAdapter
    {
        DefaultAdapter() = default;
        ~DefaultAdapter() = default;

        virtual SIZE_T Read(const LPCVOID address, LPVOID buffer, SIZE_T size) const override;
        virtual SIZE_T Write(const LPVOID address, LPCVOID buffer, SIZE_T size) const override;

        HANDLE process_handle_ = nullptr;

    }; // struct DefaultAdapter

} // namespace wmml

#endif // DEFAULT_ADAPTER_H