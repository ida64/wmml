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
        /**
        * @brief Read the memory from the process.
        * @param address The address to read from.
        * @param buffer The buffer to store the read data.
        * @param size The size of the buffer.
        * @return The number of bytes read.
        */
        virtual SIZE_T Read(const LPCVOID address, LPVOID buffer, SIZE_T size) const = 0;

        /**
        * @brief Write the memory to the process.
        * @param address The address to write to.
        * @param buffer The buffer to write.
        * @param size The size of the buffer.
        * @return The number of bytes written.
        */
        virtual SIZE_T Write(const LPVOID address, LPCVOID buffer, SIZE_T size) const = 0;

    public: // Public Template Member Functions
        /**
        * @brief Read the memory from the process.
        * @param address The address to read from.
        * @return The value read.
        */
        template<typename T>
        inline T ReadByType(const LPCVOID address);

        /**
        * @brief Write the memory to the process.
        * @param address The address to write to.
        * @param value The value to write.
        * @return The number of bytes written.
        */
        template<typename T>
        inline void WriteByType(const LPVOID address, const T& value);

    }; // class MemoryAdapter

} // namespace wmml

#include "memory_adapter.inl"

#endif // MEMORY_ADAPTER_H
