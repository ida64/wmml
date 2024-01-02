#include "memory_adapter.h"

namespace wmml
{
    template<typename T>
    inline T MemoryAdapter::ReadByType(const LPCVOID address)
    {
        T value{};

        SIZE_T bytes_read = 0;
        bytes_read = this->Read(address, &value, sizeof(T));
        
        if(bytes_read != sizeof(T))
        {
            DebugBreak();
        }

        return value;
    }

    template<typename T>
    inline void MemoryAdapter::WriteByType(const LPVOID address, const T& value)
    {
        SIZE_T bytes_written = 0;
        bytes_written = this->Write(address, &value, sizeof(T));

        if(bytes_written != sizeof(T))
        {
            DebugBreak();
        }
    }

} // namespace wmml
