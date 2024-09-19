#include "../include/mcts.h"

int main() {
    srand(static_cast<unsigned>(time(0)));  // 随机种子

    State start_state(START_X, START_Y);
    MCTS mcts;

    State current_state = start_state;
    while (!current_state.is_terminal()) {
        std::cout << "Current Status:\n";
        current_state.print();

        MCTSNode* best_node = mcts.search(current_state, 1000);  // 1000 iterations

        if (best_node != nullptr) {
            current_state = best_node->state;
            delete best_node;
        }

        if (current_state.is_terminal()) {
            std::cout << "Goal Achieved! \n";
            break;
        }
    }

    std::cout << "Final Status:\n";
    current_state.print();
    return 0;
}
