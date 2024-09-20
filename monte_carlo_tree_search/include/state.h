#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>

#ifndef CONFIG_GRID_SIZE
#define CONFIG_GRID_SIZE 5  
#endif
constexpr int GRID_SIZE = CONFIG_GRID_SIZE;  // CONFIG_GRID_SIZExCONFIG_GRID_SIZE grid map

#ifndef CONFIG_START_X
#define CONFIG_START_X 0
#endif
constexpr int START_X = CONFIG_START_X;

#ifndef CONFIG_START_Y
#define CONFIG_START_Y 0
#endif
constexpr int START_Y = CONFIG_START_Y;

#ifndef CONFIG_GOAL_X
#define CONFIG_GOAL_X 4
#endif
constexpr int GOAL_X = CONFIG_GOAL_X;

#ifndef CONFIG_GOAL_Y
#define CONFIG_GOAL_Y 4
#endif
constexpr int GOAL_Y = CONFIG_GOAL_Y;

#ifndef CONFIG_MAX_SIM_STEPS
#define CONFIG_MAX_SIM_STEPS 100
#endif
constexpr int MAX_SIMULATION_STEPS = CONFIG_MAX_SIM_STEPS;  // the max steps of random-simulation

enum Action {
    UP, DOWN, LEFT, RIGHT
};

// Hash function for status marking
struct StateHash {
    std::size_t operator()(const std::pair<int, int>& s) const {
        return std::hash<int>()(s.first) ^ std::hash<int>()(s.second);
    }
};

// Robot State
class State {
public:
    int x, y;

    State(int x, int y);
    bool is_terminal() const;
    double get_wins() const;
    std::vector<Action> get_legal_actions() const;
    State perform_action(Action action) const;
    bool operator==(const State& other) const;
    std::pair<int, int> get_position() const;
    void print() const;
};

#endif  // STATE_H
