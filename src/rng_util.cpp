#include <rng_util.hpp>
#include <random>

std::mt19937 gen32(69);
std::mt19937_64 gen64(69);

template<typename T>
T rng::choice(std::vector<T> &choices) {
    int i = gen32() % choices.size();
    return choices[i];
}

void rng::seed(int seed) {
    gen32.seed(seed);
    gen64.seed(seed);
}