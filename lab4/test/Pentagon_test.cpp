#include <gtest/gtest.h>

#include "../include/figures/Pentagon.hpp"


TEST(constructor_test, valid_points) {
    Point<double> p1(0, 100); 
    Point<double> p2(std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));
    Point<double> p3(25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p4(-25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p5(-std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));

    EXPECT_NO_THROW(Pentagon<double>(p1, p2, p3, p4, p5));
}

TEST(constructor_test, invalid_points) {
    Point<double> p1(0, 100); 
    Point<double> p2(std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));
    Point<double> p3(20 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p4(-25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p5(-std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));

    EXPECT_THROW(Pentagon<double>(p1, p2, p3, p4, p5), std::invalid_argument);
}

TEST(geom_center_test, normal) {
    Point<double> p1(0, 100); 
    Point<double> p2(std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));
    Point<double> p3(25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p4(-25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p5(-std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));

    Pentagon<double> test(p1, p2, p3, p4, p5);

    Point<double> centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2.84217e-5 < INACCURACY);
}

TEST(operator_double_test, normal) {
    Point<double> p1(0, 100); 
    Point<double> p2(std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));
    Point<double> p3(25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p4(-25 * (-std::sqrt(2) + std::sqrt(10)) * std::sqrt(5 + std::sqrt(5)) / 2.0, -25 - 25 * std::sqrt(5));
    Point<double> p5(-std::sqrt(6250 + 1250 * std::sqrt(5)), -25 + 25 * std::sqrt(5));

    Pentagon<double> test(p1, p2, p3, p4, p5);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 23776.4 < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 