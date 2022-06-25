#include <vector>

namespace rng {
template <typename T>
T choice(std::vector<T> &choices);
void seed(int seed);
bool probability(float p, int precision=100);
}  // namespace rng