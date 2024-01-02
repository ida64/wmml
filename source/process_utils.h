#ifndef PROCESS_UTILS_H
#define PROCESS_UTILS_H

#include <string>
#include <optional>

#include <Windows.h>
#include <TlHelp32.h>

namespace wmml
{
    std::optional<DWORD> GetProcessIdByName(std::wstring process_name);

} // namespace wmml

#endif // PROCESS_UTILS_H
