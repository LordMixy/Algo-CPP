#include "algo.hpp"

int main()
{
	std::array<int32_t, 13> array = { 9, 8, 3, 2, 1, 4, 5, 6, 12, 32, 43, 5, 9 };

	Algo::selectionSort(array.begin(), array.end());
	for (const auto& el : array) 
	{
		std::cout << el << std::endl;
	}

	return EXIT_SUCCESS;
}
