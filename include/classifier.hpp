#pragma once

#include <algorithm>
#include <string>

#include "fitness.hpp"
#include "selection.hpp"

int DATA_LOADED = 0;

std::string __slots__[4] = {"split_val", "feature", "label", "depth"};

void load_features();

// node classmethods
class Node {
   private:
   public:
    Node();
    ~Node();

    bool is_leaf();
    const char* to_string();

    Node leaf() const;
    Node split(int feature, float split_val) const;
};

class DecisionTree {
   private:
   public:
};
