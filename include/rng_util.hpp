#include <vector>

namespace rng {
template <typename T>
T choice(std::vector<T> &choices);

void seed(int seed);
}  // namespace rng