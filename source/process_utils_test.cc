#ifdef UNIT_TEST_ENABLED

#include "process_utils.h"

#include <gtest/gtest.h>

namespace wmml
{
    TEST(ProcessUtils, GetProcessIdByName)
    {
        EXPECT_TRUE(GetProcessIdByName(L"explorer.exe").has_value());
    }

} // namespace wmml

#endif // UNIT_TEST_ENABLED
