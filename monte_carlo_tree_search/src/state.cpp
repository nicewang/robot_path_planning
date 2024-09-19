#include "../include/state.h"

// Realize the corresponding methods of Class RobotState
State::State(int x, int y) : x(x), y(y) {}

bool State::is_terminal() const {
    return (x == GOAL_X && y == GOAL_Y);
}

double State::get_reward() const {
    return is_terminal() ? 1.0 : 0.0;
}

std::vector<Action> State::get_legal_actions() const {
    std::vector<Action> actions;
    if (x > 0) actions.push_back(LEFT);
    if (x < GRID_SIZE - 1) actions.push_back(RIGHT);
    if (y > 0) actions.push_back(UP);
    if (y < GRID_SIZE - 1) actions.push_back(DOWN);
    return actions;
}

State State::perform_action(Action action) const {
    State new_state = *this;
    switch (action) {
        case UP:    
            new_state.y -= 1; 
            break;
        case DOWN:  
            new_state.y += 1; 
            break;
        case LEFT:  
            new_state.x -= 1; 
            break;
        case RIGHT: 
            new_state.x += 1; 
            break;
    }
    return new_state;
}

bool State::operator==(const State& other) const {
    return x == other.x && y == other.y;
}

std::pair<int, int> State::get_position() const {
    return std::make_pair(x, y);
}

void State::print() const {
    std::cout << "Robot at: (" << x << ", " << y << ")\n";
}
