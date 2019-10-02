#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <functional>

#include "sortingAlgorithms.hpp"

namespace sorting {

	void bubbleSort(std::vector<int>& arr) {
		const int length = arr.size();

		for (int i = 0; i < length - 1; i++) {
			bool isSorted = true;
			for (int j = 0; j < length - 1 - i; j++) {
				if (arr[j] > arr[j+1]) {
					std::swap(arr[j], arr[j+1]);
					isSorted = false;
				}
			}
			if (isSorted) return;
		}
	}

	void bubbleSortData(std::vector<int>& arr) {
		const int length = arr.size();
		long compares, assigments = 0;

		for (int i = 0; i < length - 1 && compares++; i++) {
			bool isSorted = true;
			for (int j = 0; j < length - 1 - i && compares++; j++) {
				if (arr[j] > arr[j+1]) {
					std::swap(arr[j], arr[j+1]);
					isSorted = false;
				}
			}
			if (isSorted) return;
		}
	}

	void insertionSort(std::vector<int> & arr) {
		const int length = arr.size();
		for (int i = 1; i < length; i++) {
			const int current = arr[i];
			int j = i - 1;
			for ( ; j >= 0 && arr[j] > current; j--) {
				arr[j+1] = arr[j];
			}
			arr[j+1] = current;
		}
	}

	void insertionSortData(std::vector<int> & arr) {
		const int length = arr.size();
		long compares, assigments = 0;

		for (int i = 1; i < length; i++) {
			const int current = arr[i];
			int j = i - 1;
			for ( ; j >= 0 && arr[j] > current; j--) {
				arr[j+1] = arr[j];
			}
			arr[j+1] = current;
		}
	}

	void insertionSortExpensive(std::vector<int>& arr) {
		const int length = arr.size();
		for (int i = 1; i < length; i++) {
			for (int j = i; j > 0 && arr[j-1] > arr[j]; --j) {
				std::swap(arr[j-1], arr[j]);
			}
		}
	}

	void nativeSort(std::vector<int>& arr) {
		std::sort(arr.begin(), arr.end());
	}

	std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> getAllSorts() {
		std::vector<std::pair<std::string, std::function<void(std::vector<int>&)>>> container = {
			{"Bubble sort", bubbleSort},
			{"Insertion sort", insertionSort},
			{"Crappy insertion sort", insertionSortExpensive},
			{"Native", nativeSort}
		};

		for (int i = 0; i < container.size(); i++) {
			const std::string temp = container[i].first;
			container[i].first = std::to_string(i) +  " : " + temp;
		}
		return container;
	} 

	// utilities
	bool isSorted(std::vector<int>& arr) {
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i-1] > arr[i]) return false;
		}
		return true;
	}

	void printArr(std::vector<int>& arr) {
		const int length = arr.size();

		for (int i = 0; i < length; i++) {
			if (i >= length - 1) std::cout << arr[i];
			else std::cout << arr[i] << ' ';
		}
		std::cout << std::endl; 
	}
} // namespace sorting
