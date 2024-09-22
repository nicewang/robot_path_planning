#include "../include/astar.h"

#ifndef CONFIG_WIDTH
#define CONFIG_WIDTH 5  
#endif
constexpr int WIDTH = CONFIG_WIDTH; 

#ifndef CONFIG_HEIGHT
#define CONFIG_HEIGHT 5  
#endif
constexpr int HEIGHT = CONFIG_HEIGHT;

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

int main() {
    int width = WIDTH, height = HEIGHT;
    std::vector<std::pair<int, int>> path = aStar(START_X, START_Y, GOAL_X, GOAL_Y, width, height);

    if (!path.empty()) {
        std::cout << "Path found: ";
        for (const auto& p : path) {
            std::cout << "(" << p.first << ", " << p.second << ") \n";
        }
    } else {
        std::cout << "No path found!\n";
    }

    return 0;
}
