#include <stdexcept>
#include <gtest/gtest.h>

#include "../functions/functions.hpp"

TEST(testWork, testFunction)
{
    std::stringstream testStream("two two one 3 3 3 car");
    std::map<std::string, size_t> test;

    readWords(testStream, test);
    EXPECT_EQ(test["two"], 2);
    EXPECT_EQ(test["3"], 3);
    EXPECT_EQ(test["car"], 1);
    EXPECT_EQ(test["one"], 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
