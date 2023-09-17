#include <gtest/gtest.h>

TEST(MyTestSuite, MyTestCase) {
    // 테스트 코드 작성
    EXPECT_EQ(2 + 2, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
