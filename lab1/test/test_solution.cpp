#include <gtest/gtest.h>

#include "../include/solution.hpp"

TEST(change_hour_format_test, pm_test_1) {
    std::string answ = lab1::change_hour_format(5, 45, "pm");
    EXPECT_EQ(answ, "1745");
}

TEST(change_hour_format_test, pm_test_2) {
    std::string answ = lab1::change_hour_format(11, 21, "pm");
    EXPECT_EQ(answ, "2321");
}

TEST(change_hour_format_test, pm_test_3) {
    std::string answ = lab1::change_hour_format(12, 0, "pm");
    EXPECT_EQ(answ, "0000");
}

TEST(change_hour_format_test, am_test_1) {
    std::string answ = lab1::change_hour_format(4, 23, "am");
    EXPECT_EQ(answ, "0423");
}

TEST(change_hour_format_test, am_test_2) {
    std::string answ = lab1::change_hour_format(11, 15, "am");
    EXPECT_EQ(answ, "1115");
}

TEST(change_hour_format_test, am_test_3) {
    std::string answ = lab1::change_hour_format(12, 0, "am");
    EXPECT_EQ(answ, "1200");
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

    return 0;
}
