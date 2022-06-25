#include "decision_tree.hpp"
#include "rng_util.hpp"

#include <cassert>
#include <deque>
#include <vector>
#include <algorithm>

Node::Node() : split_val(0), feature(0), label(0), depth(0), is_none(true) {}
Node::Node(float split_val, int feature, int label) : split_val(split_val), feature(feature), label(label), depth(0), is_none(false) {}

std::ostream &operator<<(std::ostream &os, const Node& node) {
    if (node.is_leaf()) {
        os << "Label: " << label_names[node.label];
    } else {
        os << "Feature: " << feature_names[node.feature] << ", Split: " << node.split_val;
    }
    return os;
}

DecisionTree::DecisionTree(int optimal_depth) {
    this->optimal_depth = optimal_depth;
    int l = 1 << (optimal_depth + 1);

    nodes.resize(l);

    int root_feature = rng::choice(features);
    nodes[1] = Node::split(root_feature, rng::choice(feature_vals[root_feature]));
    depth = 0;
}
DecisionTree DecisionTree::generate_random(int optimal_depth, float split_p) {
    assert(0 < split_p && split_p <= 1);
    DecisionTree ret(optimal_depth);

    std::deque<int> q = {1};
    while (!q.empty()) {
        int cur = q.front();
        q.pop_front();

        for (int i=2; i--;) {
            if (ret.nodes[cur].depth + 2 <= optimal_depth && rng::probability(split_p)) {
                int next_pos = ret.add_node(cur, 's');
                q.push_back(next_pos);
            } else {
                ret.add_node(cur, 'l');
            }
        }
    }

    return ret;
}
int DecisionTree::add_node(int node_ind, char node_type) {
    assert(node_ind >= 1);
    assert(node_type == 's' || node_type == 'l');

    int next_pos;
    if (nodes[node_ind * 2].is_none) {
        next_pos = node_ind * 2;
    } else {
        next_pos = node_ind * 2 + 1;
    }

    Node &new_node = nodes[node_ind];
    if (node_type == 'l') {
        if ((next_pos % 2 == 1 && nodes[next_pos - 1].is_leaf()) || (next_pos % 2 == 0 && nodes[next_pos].is_leaf())) {
            std::vector<int> filtered_labels;
            std::copy_if(labels.begin(), labels.end(), std::back_inserter(filtered_labels), [&](int label) {
                return label != nodes[node_ind].label;
            });
            new_node = Node::leaf(rng::choice(filtered_labels));
        } else {
            new_node = Node::leaf(rng::choice(labels));
        }
    } else {
        int feature = rng::choice(features);
        float split_val = rng::choice(feature_vals[feature]);
        new_node = Node::split(feature, split_val);
    }

    new_node.depth = nodes[node_ind].depth + 1;
    depth = std::max(depth, new_node.depth);
    return next_pos;
}
void DecisionTree::extend_nodes() {
    nodes.resize(nodes.size() * 2);
}