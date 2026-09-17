#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

// Dato un array A[0 .. N] e un indice i tale che 0 <= i <= N,
// il selection sort calcola l'indice M dell'elemento minimo di
// A[i .. N] e scambia A[i] con A[M]. 

namespace Algo
{
	template <std::random_access_iterator Iterator, typename Comparator = std::less<>>
	void selectionSort(Iterator begin, Iterator end, Comparator comparator = Comparator())
	{
		if (begin == end)
		{
			return;
		}

		for (Iterator i = begin; i != end; ++i)
		{
			Iterator minimum = i;			
			for (Iterator j = i; j != end; ++j) 
			{
				if (comparator(*j, *minimum)) 
				{
					minimum = j;
				}
			}
			std::swap(*i, *minimum);
		}
	}
};

#endif // SELECTION_SORT_HPP
