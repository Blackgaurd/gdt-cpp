#include <math.h>

//. TEMPORARY I NEED ASSSITANCE
struct DecisionTree
{
};

// math funcs
float linear(int depth, int optimal_depth);
float tanh(int depth, int optimal_depth);
float sigmoid(int depth, int optimal_depth);
float negative_quadratic(int depth, int optimal_depth);

struct _2D_Array_i
{
    int first, second;
};

class FitnessEvaluator
{
private:
    // no idea what a1 and a2 are :)
    float a1, a2;
    // float arrays
    float *x, *y;
    // float array size value
    int x_size, y_size;
    // idk how to add funcs
    void (*func)(_2D_Array_i, float);

public:
    FitnessEvaluator();
    ~FitnessEvaluator();

    void init();
    float accuracy(DecisionTree);
    float call(DecisionTree);
};
