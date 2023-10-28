#include <gtest/gtest.h>

#include "../include/figures/Hexagon.hpp"
#include "../src/figures/Hexagon.cpp"

#define INACCURACY 1e-4

TEST(constructor_test, valid_points) {
    Point p1(1, 4);
    Point p2(-3, 0);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    EXPECT_NO_THROW(Hexagon(p1, p2, p3, p4, p5, p6));
}

TEST(constructor_test, invalid_points) {
    Point p1(1, 4);
    Point p2(-3, 7);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    EXPECT_THROW(Hexagon(p1, p2, p3, p4, p5, p6), std::invalid_argument);
}

TEST(geom_center_test, normal) {
    Point p1(1, 4);
    Point p2(-3, 0);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    Hexagon test(p1, p2, p3, p4, p5, p6);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - (-1.0) < INACCURACY);
    EXPECT_TRUE(centre.get_y() - 2 < INACCURACY);
}

TEST(operator_double_test, normal) {
    Point p1(1, 4);
    Point p2(-3, 0);
    Point p3(std::sqrt(3), 3 - std::sqrt(3));
    Point p4(-std::sqrt(3), 3 + std::sqrt(3));
    Point p5(-2 - std::sqrt(3), 1 + std::sqrt(3));
    Point p6(-2 + std::sqrt(3), 1 - std::sqrt(3));

    Hexagon test(p1, p2, p3, p4, p5, p6);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 83.1384 < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 