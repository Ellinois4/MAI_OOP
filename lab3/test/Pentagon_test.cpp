#include <gtest/gtest.h>

#include "../include/figures/Pentagon.hpp"
#include "../src/figures/Pentagon.cpp"

#define INACCURACY 1e-5

TEST(constructor_test, valid_points) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(28.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 2.01);

    EXPECT_NO_THROW(Pentagon(p1, p2, p3, p4, p5));
}

TEST(constructor_test, invalid_points) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(18.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 3.01);

    EXPECT_THROW(Pentagon(p1, p2, p3, p4, p5), std::invalid_argument);
}

TEST(geom_center_test, normal) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(28.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 2.01);

    Pentagon test(p1, p2, p3, p4, p5);

    Point centre = test.geom_center();

    EXPECT_TRUE(centre.get_x() - 30.0 < INACCURACY);
    EXPECT_TRUE(centre.get_y() - (-0.01) < INACCURACY);
}

TEST(operator_double_test, normal) {
    Point p1(31.91, 0.62);
    Point p2(31.18, -1.63);
    Point p3(28.82, -1.63);
    Point p4(28.09, 0.62);
    Point p5(30, 2.01); 

    Pentagon test(p1, p2, p3, p4, p5);

    double square = static_cast<double>(test);
    EXPECT_TRUE(square - 9.62676 < INACCURACY);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 