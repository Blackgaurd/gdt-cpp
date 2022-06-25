#include "rng_util.hpp"

#include <iostream>

int main() {
    std::vector<int> choices = {1, 2, 3, 4, 5};
    int i = rng::choice<int>(choices);
    std::cout << i << std::endl;
    return 0;
}