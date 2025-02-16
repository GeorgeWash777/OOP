#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"


using namespace std;

TEST(TriangleTest, AreaTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {0, 3}, {3, 0}};
    Triangle triangle(vertices);
    double area = static_cast<double>(triangle);
    EXPECT_DOUBLE_EQ(area, 4.5);
}

TEST(TriangleTest, CenterTest)
{
    vector<pair<double, double>> vertices = {
        {-2, -2}, {0, 2}, {2, -2}};
    Triangle triangle(vertices);
    auto center = triangle.Center();
    EXPECT_DOUBLE_EQ(center.first, 0);
    EXPECT_DOUBLE_EQ(center.second, 0.6666666666666666);
}

TEST(HexagonTest, AreaTest)
{
    vector<pair<double, double>> vertices = {
        //0 0 2 -2 4 0 4 4 2 6 0 4
        {0, 0}, {2, -2}, {4, 0}, {4, 4}, {2, 6}, {0, 4}};
    Hexagon hexagon(vertices);
    double area = static_cast<double>(hexagon);
    EXPECT_DOUBLE_EQ(area, 24.0);
}

TEST(HexagonTest, CenterTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, -2}, {4, 0}, {4, 4}, {2, 6}, {0, 4}};
    Hexagon hexagon(vertices);
    auto center = hexagon.Center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(OctagonTest, AreaTest)
{
    vector<pair<double, double>> vertices = {
        //0 0 2 -2 4 -2 6 0 6 4 4 6 2 6 0 4
        {0, 0}, {2, -2}, {4, -2}, {6, 0}, {6, 4}, {4, 6}, {2, 6}, {0, 4}};
    Octagon octagon(vertices);
    double area = static_cast<double>(octagon);
    EXPECT_DOUBLE_EQ(area, 40.0);
}

TEST(OctagonTest, CenterTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {2, -2}, {4, -2}, {6, 0}, {6, 4}, {4, 6}, {2, 6}, {0, 4}};
    Octagon octagon(vertices);
    auto center = octagon.Center();
    EXPECT_DOUBLE_EQ(center.first, 3.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(FigureTest, ComparisonTest)
{
    vector<pair<double, double>> vertices1 = {
        {0, 0}, {1, 0}, {0, 1}};
    vector<pair<double, double>> vertices2 = vertices1;
    Triangle triangle1(vertices1);
    Triangle triangle2(vertices2);
    EXPECT_TRUE(triangle1 == triangle2);
}

TEST(FigureTest, CopyAssignmentTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {0, 1}};
    Triangle triangle1(vertices);
    Triangle triangle2;
    triangle2 = triangle1;
    EXPECT_TRUE(triangle1 == triangle2);
}

TEST(FigureTest, MoveAssignmentTest)
{
    vector<pair<double, double>> vertices = {
        {0, 0}, {1, 0}, {0, 1}};
    Triangle triangle1(vertices);
    Triangle triangle2;
    triangle2 = move(triangle1);
    EXPECT_TRUE(triangle2 == Triangle(vertices));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}