#ifndef MCTS_H
#define MCTS_H

#include "state.h"
#include <unordered_set>

#ifndef CONFIG_C
#define CONFIG_C 2  
#endif

constexpr int C = CONFIG_C; // Constant C for UCB1 calculation

// MCTS Node Class
class MCTSNode {
public:
    State state;
    MCTSNode* parent;
    std::vector<MCTSNode*> children;
    int visits;
    // The number of wins for the node
    double wins;
    std::unordered_set<std::pair<int, int>, StateHash> visited_states;

    MCTSNode(const State& state, MCTSNode* parent = nullptr);
    ~MCTSNode();
    bool is_fully_expanded() const;
};

// MCTS Class
class MCTS {
public:
    MCTSNode* root;
    MCTSNode* search(const State& root_state, int iterations);

private:
    MCTSNode* tree_policy(MCTSNode* node);
    // 1: Selection
    MCTSNode* select(MCTSNode* node) const;
    // 2: Expansion
    MCTSNode* expand(MCTSNode* node);
    // 3: Simulation / Rollout
    double simulate(const State& state);
    // 4: Backpropagation
    void backpropagate(MCTSNode* node, double reward);
};

#endif  // MCTS_H
