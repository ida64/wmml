#include "process_utils.h"

namespace wmml
{
    std::optional<DWORD> GetProcessIdByName(std::wstring process_name)
    {
        PROCESSENTRY32 process_entry;
        process_entry.dwSize = sizeof(PROCESSENTRY32);

        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
        if(Process32First(snapshot, &process_entry) == TRUE)
        {
            while(Process32Next(snapshot, &process_entry) == TRUE)
            {
                if(process_name == process_entry.szExeFile)
                {
                    CloseHandle(snapshot);
                    return process_entry.th32ProcessID;
                }
            }
        }

        CloseHandle(snapshot);
        return std::nullopt;
    }

} // namespace wmml

