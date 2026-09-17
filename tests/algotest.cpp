#include <gtest/gtest.h>
#include <iostream>
#include <array>
#include <random>

#include "../src/algo.hpp"

#define ARRAY_LENGTH     5
#define NUMBER_OF_TESTS  10

class SortingTest : public testing::Test 
{
	protected: 
		std::array<std::array<int32_t, ARRAY_LENGTH>, NUMBER_OF_TESTS> arrays;		
		
	SortingTest()
	{	
		std::random_device device;
		std::mt19937 rng(device());
		std::uniform_int_distribution<std::mt19937::result_type> dist(-100, 100); 
		
		for (std::size_t i = 0; i < NUMBER_OF_TESTS; ++i) 
		{
			for (std::size_t j = 0; j < ARRAY_LENGTH; ++j) 
			{
				arrays[i][j] = dist(rng);
			}
		}
	}
};

TEST_F(SortingTest, InsertionSort)
{
	std::array<int32_t, ARRAY_LENGTH> arraySorted;
	for (std::size_t i = 0; i < NUMBER_OF_TESTS; ++i) 
	{	
		// std::partial_sort_copy(arrays[i].begin(), arrays[i].end(), arraySorted.begin(), arraySorted.end());
		arraySorted = arrays[i];
        std::sort(arraySorted.begin(), arraySorted.end());
		
 		Algo::insertionSort(arrays[i].begin(), arrays[i].end());
		EXPECT_EQ(arrays[i], arraySorted);
	}
}

// TEST_F(SortingTest, SelectionSort)
// {
// 	std::array<int32_t, ARRAY_LENGTH> arraySorted;
// 	for (std::size_t i = 0; i < NUMBER_OF_TESTS; ++i) 
// 	{	
// 		// std::partial_sort_copy(arrays[i].begin(), arrays[i].end(), arraySorted.begin(), arraySorted.end());
// 		arraySorted = arrays[i];
//         std::sort(arraySorted.begin(), arraySorted.end());
// 		
//  		Algo::selectionSort(arrays[i]);
// 		EXPECT_EQ(arrays[i], arraySorted);
// 	}
// }

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
