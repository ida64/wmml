#ifndef MEMORY_ADAPTER_H
#define MEMORY_ADAPTER_H

#include <memory>
#include <Windows.h>

namespace wmml
{
    using MemoryAdapterPtr = std::shared_ptr<class MemoryAdapter>;

    class MemoryAdapter
    {
    public: // Constructors and Destructor
        MemoryAdapter() = default;
        virtual ~MemoryAdapter() = default;

    public: // Public Member Functions 
        virtual SIZE_T Read(const LPCVOID address, LPVOID buffer, SIZE_T size) const = 0;
        virtual SIZE_T Write(const LPVOID address, LPCVOID buffer, SIZE_T size) const = 0;

    public: // Public Template Member Functions
        template<typename T>
        inline T ReadByType(const LPCVOID address);

        template<typename T>
        inline void WriteByType(const LPVOID address, const T& value);

    }; // class MemoryAdapter

} // namespace wmml

#include "memory_adapter.inl"

#endif // MEMORY_ADAPTER_H
