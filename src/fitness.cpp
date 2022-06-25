#include "fitness.hpp"

float linear(int depth, int optimal_depth) {
    return 1.0 - (float)depth / (float)optimal_depth;
}
float tanh(int depth, int optimal_depth) {
    return tanh(linear(depth, optimal_depth));
}
float sigmoid(int depth, int optimal_depth) {
    return 1.0 / (1.0 + exp(depth - optimal_depth)) - 0.5;
}
float negative_quadratic(int depth, int optimal_depth) {
    return -((depth - optimal_depth) * (depth - optimal_depth));
}

FitnessEvaluator::FitnessEvaluator(float a1, float a2, std::function<float(int, int)> f2_func) : a1(a1), a2(a2), f2_func(f2_func) {
}

FitnessEvaluator::~FitnessEvaluator() {
}

void FitnessEvaluator::_init() {
}

float FitnessEvaluator::accuracy(const DecisionTree &individual) {
}

float FitnessEvaluator::operator()(const DecisionTree &individual) {
}
