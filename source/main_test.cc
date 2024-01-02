#ifdef UNIT_TEST_ENABLED

#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    const int status = RUN_ALL_TESTS();
    return status;
}

#endif // UNIT_TEST_ENABLED
