#include <gtest/gtest.h>
#include <iostream>
#include "../include/octagon.h"
#include "../include/hexagon.h"
#include "../include/triangle.h"
#include "../include/array.h"


TEST(HexagonTest, AreaTest)
{
    std::vector<Point<int>> vertices = {
        //0 0 2 -2 4 0 4 4 2 6 0 4
        {0, 0}, {2, -2}, {4, 0}, {4, 4}, {2, 6}, {0, 4}};
    Hexagon<int> hexagon(vertices);
    double area = hexagon;
    EXPECT_DOUBLE_EQ(area, 24.0);
}

TEST(HexagonTest, CenterTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, -2}, {4, 0}, {4, 4}, {2, 6}, {0, 4}};
    Hexagon<int> hexagon(vertices);
    auto center = hexagon.Center();
    EXPECT_DOUBLE_EQ(center->x, 2.0);
    EXPECT_DOUBLE_EQ(center->y, 2.0);
}

TEST(OctagonTest, AreaTest)
{
    std::vector<Point<int>> vertices = {
        //0 0 2 -2 4 -2 6 0 6 4 4 6 2 6 0 4
        {0, 0}, {2, -2}, {4, -2}, {6, 0}, {6, 4}, {4, 6}, {2, 6}, {0, 4}};
    Octagon<int> octagon(vertices);
    double area = octagon;
    EXPECT_DOUBLE_EQ(area, 40.0);
}

TEST(OctagonTest, CenterTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, -2}, {4, -2}, {6, 0}, {6, 4}, {4, 6}, {2, 6}, {0, 4}};
    Octagon<int> octagon(vertices);
    auto center = octagon.Center();
    EXPECT_DOUBLE_EQ(center->x, 3.0);
    EXPECT_DOUBLE_EQ(center->y, 2.0);
}

TEST(TriangleTest, AreaTest)
{
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, 0}, {0, 2}};
    Triangle<int> triang(vertices);
    double area = triang;
    EXPECT_DOUBLE_EQ(area, 2);
}

TEST(TriangleTest, CenterTest)
{
    std::vector<Point<double>> vertices = {
        {0, 0}, {1, 3}, {2, 0} };
    Triangle<double> triang(vertices);
    auto center = triang.Center();
    EXPECT_DOUBLE_EQ(center->x, 1);
    EXPECT_DOUBLE_EQ(center->y, 1);
}

TEST(FigureTest, ComparisonTest)
{
    std::vector<Point<int>> vertices1 = {
        {0, 0}, {1, 0}, {0, 1}};
    Triangle<int> triangle1(vertices1);

    std::vector<Point<int>> vertices2 = {
        {0, 0}, {1, 0}, {0, 1}};
    Triangle<int> triangle2(vertices2);

    EXPECT_TRUE(triangle1 == triangle2);
}

TEST(ArrayTest, PushBackAndAccess)
{
    Array<Figure<int>> figures;
    std::vector<Point<int>> vertices = {
        {0, 0}, {2, 0}, {0, 2}};
    auto triangle = make_shared<Triangle<int>>(vertices);
    figures.push_back(triangle);
    EXPECT_EQ(figures.get_size(), 1);
    double area = *figures[0];
    EXPECT_DOUBLE_EQ(area, 2.0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}