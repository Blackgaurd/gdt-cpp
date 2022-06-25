#include "rng_util.hpp"

#include <random>

std::mt19937 gen32(69);
std::mt19937_64 gen64(69);

namespace rng {

template<typename T>
T choice(std::vector<T> &choices) {
    int ind = gen32() % choices.size();
    return choices[ind];
}
template int choice<int>(std::vector<int> &choices);
template float choice<float>(std::vector<float> &choices);

void seed(int seed) {
    gen32.seed(seed);
    gen64.seed(seed);
}

bool probability(float p, int precision) {
    return gen32() % precision < p * precision;
}

} // namespace rng