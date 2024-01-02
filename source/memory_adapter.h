#ifndef MEMORY_ADAPTER_H
#define MEMORY_ADAPTER_H

#include <Windows.h>

namespace wmml
{
    class MemoryAdapter
    {
    public: // Constructors and Destructor
        MemoryAdapter() = default;
        virtual ~MemoryAdapter() = default;

    public: // Public member 
        virtual bool Read(const LPCVOID address, LPVOID buffer, SIZE_T size) const = 0;
        virtual bool Write(const LPVOID address, LPCVOID buffer, SIZE_T size) const = 0;

    }; // class MemoryAdapter

} // namespace wmml

#endif // MEMORY_ADAPTER_H
