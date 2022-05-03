#include <gtest/gtest.h>
#include <MyMap.cpp>
#include <iostream>
#include <vector>
#include <string>

TEST(initialization, empty)
{
    MyMap<int, int> map;

    std::vector<int> expectedKeysList = {};
    EXPECT_EQ(expectedKeysList, map.get_keys());

    std::vector<int> expectedValuesList = {};
    EXPECT_EQ(expectedValuesList, map.get_values());
}

TEST(initialization, withList)
{
    MyMap<int, int> map = {{55, 1}, {65, 2}, {60, 3}, {75, 4}};

    std::vector<int> expectedKeysList = {55, 75, 65, 60};
    EXPECT_EQ(expectedKeysList, map.get_keys());

    std::vector<int> expectedValuesList = {1, 4, 2, 3};
    EXPECT_EQ(expectedValuesList, map.get_values());
}

TEST(initialization, withDuplicates)
{
    try {
        MyMap<int, int> map = {{55, 1}, {55, 2}, {60, 3}, {75, 4}};
    } catch(const std::invalid_argument& error) {
        EXPECT_STREQ(error.what(), "No duplicates allowed");
    }
}

TEST(insert, inEmpty) 
{
    MyMap<int, int> map;

    map.insert(55, 1);

    std::vector<int> expectedKeysList = {55};
    EXPECT_EQ(expectedKeysList, map.get_keys());

    std::vector<int> expectedValuesList = {1};
    EXPECT_EQ(expectedValuesList, map.get_values());
}

TEST(insert, sequantially)
{
    MyMap<int, int> map;
    map.insert(2, 1);
    map.insert(1, 2);
    map.insert(4, 3);
    map.insert(5, 4);
    map.insert(9, 5);
    map.insert(3, 6);

    std::vector<int> expectedKeysList = {1, 3, 4, 9, 5, 2};
    EXPECT_EQ(expectedKeysList, map.get_keys());

    std::vector<int> expectedValuesList = {2, 6, 3, 5, 4, 1};
    EXPECT_EQ(expectedValuesList, map.get_values());
}

TEST(insert, duplicate)
{
    MyMap<int, int> map = {{2, 1}, {1, 2}, {4, 3}, {5, 4}, {9, 5}, {3, 6}};
    EXPECT_THROW(map.insert(1, 1), std::invalid_argument);
}

TEST(remove, single)
{
    MyMap<int, int> map = {{55, 1}, {40, 2}, {65, 3}, {60, 4}, {75, 5}, {57, 6}};
    map.remove(40);

    std::vector<int> expectedKeysList = {55, 60, 57, 75, 65};
    EXPECT_EQ(expectedKeysList, map.get_keys());

    std::vector<int> expectedValuesList = {1, 4, 6, 5, 3};
    EXPECT_EQ(expectedValuesList, map.get_values());
}

TEST(remove, sequentially)
{
    MyMap<int, int> map = {{55, 1}, {40, 2}, {65, 3}, {60, 4}, {75, 5}, {57, 6}};
    map.remove(55); // root
    map.remove(60);
    map.remove(75);

    std::vector<int> expectedKeysList = {40, 65, 57};
    EXPECT_EQ(expectedKeysList, map.get_keys());

    std::vector<int> expectedValuesList = {2, 3, 6};
    EXPECT_EQ(expectedValuesList, map.get_values());
}

TEST(remove, fromEmpty)
{
    MyMap<int, int> map;
    EXPECT_THROW(map.remove(29), std::invalid_argument);
}

TEST(remove, invalidKey)
{
    MyMap<int, int> map = {{55, 1}, {40, 2}, {65, 3}, {60, 4}, {75, 5}, {57, 6}};
    EXPECT_THROW(map.remove(66), std::invalid_argument);
}

TEST(find, inEmpty)
{
    MyMap<int, int> map;
    EXPECT_THROW(map.find(30), std::invalid_argument);
}

TEST(find, invalidKey)
{
    MyMap<int, int> map = {{55, 1}, {40, 2}, {65, 3}, {60, 4}, {75, 5}, {57, 6}};
    EXPECT_THROW(map.find(66), std::invalid_argument);
}

TEST(find, validKey)
{
    MyMap<int, int> map = {{55, 1}, {40, 2}, {65, 3}, {60, 4}, {75, 5}, {57, 6}};
    EXPECT_EQ(map.find(40), 2);
}

