#include "random.hpp"
#include <vector>

void Random::reset() {
	gen.seed(seed);
	dist.reset();
}

int Random::getRand() {
	return dist(gen);
}

void Random::setSeed(const unsigned seed) {
	this->seed = seed;
	gen.seed(seed);
	dist.reset();
}
 
unsigned Random::getSeed() const {
	return seed;
}

std::vector<int> Random::randIntVector(const int n) {
	std::vector<int> randVect(n);
	for (int i = 0; i < n; i++) {
		randVect[i] = getRand();
	}
	return randVect;
}
