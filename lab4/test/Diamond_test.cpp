#include <gtest/gtest.h>

#include "../include/figures/Diamond.hpp"


TEST(constructor_test, valid_points) {
    Point<double> p1(4, 4);
    Point<double> p2(7, 2);
    Point<double> p3(4, 0);
    Point<double> p4(1, 2);

    EXPECT_NO_THROW(Diamond<double>(p1, p2, p3, p4));
}

TEST(constructor_test, invalid_points) {
    Point<double> p1(4, 4);
    Point<double> p2(7, 2);
    Point<double> p3(4, 0);
    Point<double> p4(1, -1);

    EXPECT_THROW(Diamond<double>(p1, p2, p3, p4), std::invalid_argument);
}

TEST(geom_center_test, normal) {
    Point<double> p1(4, 4);
    Point<double> p2(7, 2);
    Point<double> p3(4, 0);
    Point<double> p4(1, 2); 

    Diamond<double> test(p1, p2, p3, p4);

    Point<double> centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 4.0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2.0 < INACCURACY);
}

TEST(operator_double_test, normal) {
    Point<double> p1(4, 4);
    Point<double> p2(7, 2);
    Point<double> p3(4, 0);
    Point<double> p4(1, 2); 

    Diamond<double> test(p1, p2, p3, p4);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 5.0 < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 