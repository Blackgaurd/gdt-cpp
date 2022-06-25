#include <cmath>
#include <functional>

//. TEMPORARY I NEED ASSSITANCE
struct DecisionTree {
};

// math funcs
float linear(int depth, int optimal_depth);
float tanh(int depth, int optimal_depth);
float sigmoid(int depth, int optimal_depth);
float negative_quadratic(int depth, int optimal_depth);

class FitnessEvaluator {
    // no idea what a1 and a2 are :)
    float a1, a2;
    // funciton
    std::function<float(int, int)> f2_func;

    FitnessEvaluator(float a1, float a2, std::function<float(int, int)> f2_func);
    ~FitnessEvaluator();

    void _init();
    float accuracy(const DecisionTree &individual);
    float operator() (const DecisionTree &individual);
};
