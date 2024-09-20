#include "../include/rrt.h"

int main() {
    Point start(0, 0);
    Point goal(10, 10);
    double step_size = 0.5;
    double goal_tolerance = 0.5;
    int max_iterations = 1000;
    double x_min = -10, x_max = 20, y_min = -10, y_max = 20;

    RRT rrt(start, goal, step_size, goal_tolerance, max_iterations, x_min, x_max, y_min, y_max);
    rrt.run();

    return 0;
}
