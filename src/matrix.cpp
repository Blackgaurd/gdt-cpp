#include "matrix.hpp"

#include <cmath>
#include <algorithm>

struct Matrix2D: std::vector<std::vector<float>> {
    Matrix2D(std::pair<int, int> shape) {
        this->assign(shape.first, std::vector<float>(shape.second, 0.0));
    }

    std::pair<int, int> shape() const {
        return {this->size(), this->size() > 0 ? this->front().size() : 0};
    }
    float sum() const {
        float sum = 0;
        for (const auto &row : *this) {
            for (const auto &elem : row) {
                sum += elem;
            }
        }
        return sum;
    }
    Matrix2D operator==(const Matrix2D &other) const {
        Matrix2D result(this->shape());
        for (int i = 0; i < this->size(); i++) {
            for (int j = 0; j < this->front().size(); j++) {
                result[i][j] = abs(this->operator[](i)[j] - other[i][j]) < 1e-6 ? 1 : 0;
            }
        }
        return result;
    }
    vector<float> unique() const {
        // return a vector of unique values in the matrix
        // not optimized, but it works
        vector<float> result;
        for (const auto &row : *this) {
            for (const auto &elem : row) {
                if (std::find(result.begin(), result.end(), elem) == result.end()) {
                    result.push_back(elem);
                }
            }
        }
        return result;
    }
};