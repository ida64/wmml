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

} // namespace wmml
