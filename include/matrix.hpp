#include <utility>
#include <vector>

struct Matrix2D : std::vector<std::vector<float>> {
    Matrix2D(std::pair<int, int> shape);

    std::pair<int, int> shape() const;
    float sum() const;
    Matrix2D operator==(const Matrix2D &other) const;
    vector<float> unique() const;
};
