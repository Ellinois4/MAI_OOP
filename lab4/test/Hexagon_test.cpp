#include <gtest/gtest.h>

#include "../include/figures/Hexagon.hpp"


TEST(constructor_test, valid_points) {
    Point<double> p1(1, 4);
    Point<double> p2(-3, 0);
    Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
    Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    EXPECT_NO_THROW(Hexagon<double>(p2, p5, p4, p1, p3, p6));
}

TEST(constructor_test, invalid_points) {
    Point<double> p1(1, 4);
    Point<double> p2(-3, 7);
    Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
    Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    EXPECT_THROW(Hexagon<double>(p1, p2, p3, p4, p5, p6), std::invalid_argument);
}

TEST(geom_center_test, normal) {
    Point<double> p1(1, 4);
    Point<double> p2(-3, 0);
    Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
    Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    Hexagon<double> test(p2, p5, p4, p1, p3, p6);

    Point<double> centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 1 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2 < INACCURACY);
}

TEST(operator_double_test, normal) {
    Point<double> p1(1, 4);
    Point<double> p2(-3, 0);
    Point<double> p3(std::sqrt(3), 3 - std::sqrt(3));
    Point<double> p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point<double> p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point<double> p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    Hexagon<double> test(p2, p5, p4, p1, p3, p6);

    double square = static_cast<double>(test);
    EXPECT_TRUE(std::abs(square - 20.784) < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 