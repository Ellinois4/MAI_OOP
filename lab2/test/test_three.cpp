#include <gtest/gtest.h>
#include "../include/Three.hpp"

TEST(string_constructor_test, exception_test) {
  ASSERT_THROW(Three{"199"}, std::invalid_argument);
}

TEST(string_constructor_test, without_exception_test_0) {
  ASSERT_NO_THROW(Three{"122"});
}

TEST(string_constructor_test, without_exception_test_1) {
  ASSERT_NO_THROW(Three{"0"});
}

TEST(constructor_test, exception_test_overflow) {
  ASSERT_THROW(Three{199}, std::invalid_argument);
}

TEST(constructor_test, exception_test_without_0) {
  ASSERT_NO_THROW(Three{0});
}

TEST(constructor_test, exception_test_without_1) {
  ASSERT_NO_THROW(Three{121212121212});
}

TEST(print_test, test1) {
  Three test{122};
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "122\n");
}

TEST(print_test, test2) {
  Three test{0};
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "0\n");
}

TEST(comparison_operator_test, zero_true_test) {
  Three first{0};
  Three second{0};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, true_return_1) {
  Three first{12};
  Three second{12};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, true_return_2) {
  Three first{222};
  Three second{222};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, false_return_1) {
  Three first{2222};
  Three second{2221};

  ASSERT_FALSE(first == second);
}

TEST(comparison_operator_test, false_return_2) {
  Three first{22};
  Three second{122};

  ASSERT_FALSE(first == second);
}

TEST(false_comparison_operator_test, true_return) {
  Three first{1};
  Three second{0};

  ASSERT_TRUE(first != second);
}

TEST(false_comparison_operator_test, false_return) {
  Three first{1222};
  Three second{1222};

  ASSERT_FALSE(first != second);
}

TEST(more_operator_test, true_return_1) {
  Three first{121};
  Three second{212};

  EXPECT_TRUE(second > first);
}

TEST(more_operator_test, true_return_2) {
  Three first{12121};
  Three second{210};

  EXPECT_TRUE(first > second);
}

TEST(more_operator_test, equals_args) {
  Three first{2112};
  Three second{2112};

  EXPECT_FALSE(first > second);
}

TEST(less_operator_test, false_return) {
  Three first{21121};
  Three second{211};

  EXPECT_FALSE(first < second);
}

TEST(less_operator_test, true_return) {
  Three first{212};
  Three second{221};

  EXPECT_TRUE(first < second);
}

TEST(less_operator_test, equals_args) {
  Three first{212};
  Three second{212};

  EXPECT_FALSE(first < second);
}

TEST(operator_preinc_test, test1) {
  Three test{222};
  ++test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1000\n");
}

TEST(operator_preinc_test, test2) {
  Three test{121};
  ++test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "122\n");
}

TEST(operator_postinc_test, test1) {
  Three test{121};
  test++;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "122\n");
}

TEST(operator_predec_test, test1) {
  Three test{222};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "221\n");
}

TEST(operator_predec_test, test2) {
  Three test{1000};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "222\n");
}

TEST(operator_postdec_test, test1) {
  Three test{122};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "121\n");
}

TEST(operator_postdec_test, test2) {
  Three test{1000};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "222\n");
}

TEST(subtraction_test, test1) {
  Three test1{"12"};
  Three test2{12};
  Three expected_result{0};
  Three result{test1 - test2};

  ASSERT_EQ(result, expected_result);
}

TEST(subtraction_test, exception_test) {
  Three test1{"12"};
  Three test2{122};
  Three result{"0"};

  ASSERT_THROW(test1 - test2, std::runtime_error);
}

TEST(subtraction_test, test2) {
  Three test1{"22"};
  Three test2{11};
  Three result{11};

  ASSERT_TRUE(test1 - test2 == result);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}