#include "process.h"

namespace wmml
{
    inline std::string Process::GetFullImageName() const
    {
        return this->full_image_name_;
    }

    inline HANDLE Process::GetProcessHandle() const
    {
        return this->process_handle_;
    }

    inline MemoryAdapterPtr Process::GetMemoryAdapter() const
    {
        return this->memory_adapter_;
    }

} // namespace wmml
