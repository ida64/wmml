#ifdef UNIT_TEST_ENABLED

#include <Windows.h>

#include <gtest/gtest.h>

#include "process.h"
#include "default_adapter.h"
#include "process_utils.h"

namespace wmml
{
    TEST(Process, OpenProcess)
    {
        std::optional<DWORD> result = GetProcessIdByName(L"explorer.exe");
        ASSERT_TRUE(result.has_value()) << "notepad.exe is required for this unit test";

        DWORD process_id = result.value();

        std::unique_ptr<Process> process = std::make_unique<Process>();
        ASSERT_TRUE(process->OpenProcess(process_id, PROCESS_ALL_ACCESS));
    }

    TEST(Process, MemoryAdapter)
    {
        std::unique_ptr<Process> process = std::make_unique<Process>();

        ASSERT_TRUE(process->OpenProcess(GetCurrentProcessId(), PROCESS_ALL_ACCESS));

        std::shared_ptr<DefaultAdapter> memory_adapter
            = std::make_shared<DefaultAdapter>();
        
        memory_adapter->process_handle_ = process->GetProcessHandle();

        ASSERT_TRUE(process->Update(memory_adapter));

        const int sample_value = 1234;
        const int read_value = memory_adapter->ReadByType<int>(&sample_value);

        ASSERT_EQ(sample_value, read_value);

        int new_value = 4321;
        memory_adapter->WriteByType<int>(&new_value, sample_value);

        const int read_new_value = memory_adapter->ReadByType<int>(&sample_value);

        ASSERT_EQ(new_value, read_new_value);
    }

} // namespace wmml

#endif // UNIT_TEST_ENABLED
