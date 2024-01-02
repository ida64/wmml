#ifdef UNIT_TEST_ENABLED

#include <Windows.h>

#include <gtest/gtest.h>

#include "process.h"
#include "process_utils.h"

namespace wmml
{
    TEST(Process, OpenProcess)
    {
        std::optional<DWORD> result = GetProcessIdByName(L"explorer.exe");
        ASSERT_TRUE(result.has_value()) << "explorer.exe is required for this unit test";

        DWORD process_id = result.value();

        std::unique_ptr<Process> process = std::make_unique<Process>();
        ASSERT_TRUE(process->OpenProcess(process_id, PROCESS_ALL_ACCESS));
    }

} // namespace wmml

#endif // UNIT_TEST_ENABLED
