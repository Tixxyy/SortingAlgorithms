#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <utility>
#include <string>
#include <functional>

namespace sorting {
	void bubbleSort(std::vector<int>& arr);
	void insertionSort(std::vector<int>& arr); 
	void insertionSortExpensive(std::vector<int> & arr);
	void nativeSort(std::vector<int>& arr);
	std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> getAllSorts(); 

	// utilities
	bool isSorted(std::vector<int>& arr);
	void printArr(std::vector<int>& arr);
} // namespace sorting

#endif
