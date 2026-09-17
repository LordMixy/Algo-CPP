#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <iostream>
#include <array>
#include <algorithm>
#include <functional>

// Dato un array A[0 .. N] e un indice i tale che 1 <= i <= N,  
// l'insertion sort inserisce l'elemento A[i] nella sequenza gia'
// ordinata A[0 .. (i - 1)]. 
 
// Bisogna dimostrare che A[0 .. (i - 1)] e' una sequenza gia' ordinata: 
// 
// All'inizio, quando j = 1, l'array in cui inserire A[j] e' A[0 .. (i - 1)] = A[0],
// e' un singolo elemento, dunque A[0 .. (i - 1)] e' ordinato.
//
// Durante il ciclo, quando i > 1 e i <= N, l'insertion sort inserisce A[i] in A[0 .. (i - 1)] mantendendo
// l'ordine, dunque A[0 .. i] e' ordinato.
//
// Alla fine del ciclo, quando i = N + 1, abbiamo l'array ordinato A[1 .. (i - 1)] = A[1 .. (N + 1 - 1)] 
// = A[0 .. N].

namespace Algo
{
	template <std::random_access_iterator Iterator, typename Comparator = std::less<>>
	void merge(Iterator begin, Iterator end, Comparator comparator = Comparator())
	{
		
	}
	
	template <std::random_access_iterator Iterator, typename Comparator = std::less<>>
	void mergeSort(Iterator begin, Iterator end, Comparator comparator = Comparator())
	{
		if (begin == end) 
		{
			return;
		}
		
		for (Iterator i = begin + 1; i != end; ++i) 
		{
		 	auto key = *i;

			Iterator j = i - 1;
			for (j = i - 1; j >= begin && comparator(key, *j); --j) 
			{
				*(j + 1) = *j;
			}
			*(j + 1) = key;
		}
	}
};

#endif // MERGE_SORT_HPP
