#include <iostream>
#include <chrono>
#include <array>
#include <functional>
#include <cmath>

#include "random.hpp"
#include "sortingAlgorithms.hpp"

void test(std::function<void(std::vector<int>&)> sort, unsigned int repetitions = 1);

int main() {
	unsigned int repetitions;
    std::cout << "How many repetitions per N?" << std::endl;
    std::cin >> repetitions;

    std::cout << "Choose algorithm:" << std::endl;
	auto sortingAlgorithms = sorting::getAllSorts();
	for (auto it = sortingAlgorithms.begin(); it != sortingAlgorithms.end(); it++) {
		std::cout << (*it).first << std::endl;
	}

	int alg;
	std::cin >> alg;

	if (alg >= 0 && alg < sortingAlgorithms.size()) {
		test(sortingAlgorithms[alg].second, repetitions);
	}

	return 0;
}

void test(std::function<void(std::vector<int>&)> sort, unsigned int repetitions) {
	static constexpr long MAX_N = 1000000000;
	Random rand(0);

	for (int arrSize = 10; arrSize <= MAX_N; arrSize*=10) {
		double totalTime = 0;
		bool failedSort = false;

		for (int rep = 0; rep < repetitions; rep++) {
			rand.setSeed(rep);
			std::vector<int> arr = rand.randIntVector(arrSize);

			std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
			sort(arr);
			std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

			double time = std::chrono::duration_cast<std::chrono::duration<double>>(end-start).count(); 
			totalTime+=time;

			if (!sorting::isSorted(arr)) {
				failedSort = true;
				break;
			} 
			else if (rep == 0) {
				std::printf("\nFirst run: %.9f sec\n", time);
			}
		}

		if (failedSort) {
			std::printf("NOT SORTED\n");
			return;
		}
		else if (totalTime > 0) {
			const int gap = log10(MAX_N) - log10(arrSize);
			std::printf("N: %d %*s Avg: %.9f sec\n", arrSize, gap , "", totalTime/repetitions);
		}
		else std::cout << "Something went badly wrong" << std::endl;
	}
}
