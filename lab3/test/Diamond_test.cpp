#include <gtest/gtest.h>

#include "../include/figures/Diamond.hpp"
#include "../src/figures/Diamond.cpp"

#define INACCURACY 1e-5

TEST(constructor_test, valid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2);

    EXPECT_NO_THROW(Diamond(p1, p2, p3, p4));
}

TEST(constructor_test, invalid_points) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, -1);

    EXPECT_THROW(Diamond(p1, p2, p3, p4), std::invalid_argument);
}

TEST(geom_center_test, normal) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2); 

    Diamond test(p1, p2, p3, p4);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 4.0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2.0 < INACCURACY);
}

TEST(operator_double_test, normal) {
    Point p1(4, 4);
    Point p2(7, 2);
    Point p3(4, 0);
    Point p4(1, 2); 

    Diamond test(p1, p2, p3, p4);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 5.0 < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 