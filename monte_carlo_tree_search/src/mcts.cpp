#include "../include/mcts.h"

// Realize corresponding methods of Class MCTSNode
MCTSNode::MCTSNode(const State& state, MCTSNode* parent)
    : state(state), parent(parent), visits(0), wins(0.0) {
    visited_states.insert(state.get_position());
}

MCTSNode::~MCTSNode() {
    for (MCTSNode* child : children) {
        delete child;
    }
}

bool MCTSNode::is_fully_expanded() const {
    return children.size() == state.get_legal_actions().size();
}

MCTSNode* MCTS::search(const State& root_state, int iterations) {
    root = new MCTSNode(root_state);

    for (int i = 0; i < iterations; ++i) {
        MCTSNode* node = tree_policy(root);
        double wins = simulate(node->state);
        backpropagate(node, wins);
    }

    // MCTSNode* best_node = root->select();
    MCTSNode* best_node = select(root);
    for (MCTSNode* child : root->children) {
        if (child != best_node) {
            delete child;
        }
    }

    return best_node;
}

MCTSNode* MCTS::tree_policy(MCTSNode* node) {
    while (!node->state.is_terminal()) {
        if (!node->is_fully_expanded()) {
            return expand(node);
        } else {
            // node = node->select();
            node = select(node);
        }
    }
    return node;
}

MCTSNode* MCTS::select(MCTSNode* node) const {
    double best_value = -std::numeric_limits<double>::infinity();
    MCTSNode* best_node = nullptr;
    for (MCTSNode* child : node->children) {
        // double ucb1 = child->wins / child->visits + std::sqrt(2 * std::log(visits) / child->visits);
        double ucb1 = child->wins / child->visits + C * std::sqrt(std::log(root->visits) / child->visits);
        if (ucb1 > best_value) {
            best_value = ucb1;
            best_node = child;
        }
    }
    return best_node;
}

MCTSNode* MCTS::expand(MCTSNode* node) {
    std::vector<Action> legal_actions = node->state.get_legal_actions();
    for (Action action : legal_actions) {
        State next_state = node->state.perform_action(action);
        if (node->visited_states.count(next_state.get_position()) == 0) {
            MCTSNode* child_node = new MCTSNode(next_state, node);
            node->children.push_back(child_node);
            node->visited_states.insert(next_state.get_position());
            return child_node;
        }
    }
    return nullptr;
}

double MCTS::simulate(const State& state) {
    State current_state = state;
    int steps = 0;
    while (!current_state.is_terminal() && steps < MAX_SIMULATION_STEPS) {
        std::vector<Action> legal_actions = current_state.get_legal_actions();
        Action random_action = legal_actions[rand() % legal_actions.size()];
        current_state = current_state.perform_action(random_action);
        steps++;
    }
    return current_state.get_wins();
}

void MCTS::backpropagate(MCTSNode* node, double wins) {
    while (node != nullptr) {
        node->visits++;
        node->wins += wins;
        node = node->parent;
    }
}
