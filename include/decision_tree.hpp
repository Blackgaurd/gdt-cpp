#include <ostream>
#include <vector>
#include <map>

std::vector<int> features;
std::vector<std::vector<float>> feature_vals;
std::vector<std::string> feature_names;

std::vector<int> labels;
std::map<int, std::string> label_names;

int data_loaded = 0;

struct Node {
    float split_val;
    int feature, label, depth;
    bool is_none;

    Node();
    Node(float split_val, int feature, int label);
    static Node leaf(int label) {
        return Node(0, 0, label);
    };
    static Node split(int feature, float split_val) {
        return Node(split_val, feature, 0);
    };

    bool is_leaf() const {
        return label != -1;
    }
    friend std::ostream &operator<<(std::ostream &os, const Node& node);
};

struct DecisionTree {
    std::vector<Node> nodes;
    int depth, optimal_depth;

    DecisionTree(int optimal_depth);
    static DecisionTree generate_random(int optimal_depth, float split_p);

    int add_node(int node_ind, char node_type);
    void extend_nodes();
};