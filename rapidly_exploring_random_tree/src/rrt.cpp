#include "../include/rrt.h"

Point::Point(double _x, double _y) : x(_x), y(_y) {}

double Point::distance(const Point& other) const {
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

Node::Node(const Point& p, Node* par) : point(p), parent(par) {}

RRT::RRT(const Point& s, const Point& g, double step, double tol, int max_iter, double x_min, double x_max, double y_min, double y_max)
    : start(s), goal(g), step_size(step), goal_tolerance(tol), max_iterations(max_iter), x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max) {
    nodes.push_back(new Node(start));
}

RRT::~RRT() {
    for (Node* node : nodes)
        delete node;
}

Point RRT::randomPoint() {
    double rand_x = x_min + static_cast<double>(rand()) / RAND_MAX * (x_max - x_min);
    double rand_y = y_min + static_cast<double>(rand()) / RAND_MAX * (y_max - y_min);
    return Point(rand_x, rand_y);
}

Node* RRT::nearestNode(const Point& p) {
    Node* nearest = nullptr;
    double min_dist = std::numeric_limits<double>::max();
    for (Node* node : nodes) {
        double dist = node->point.distance(p);
        if (dist < min_dist) {
            min_dist = dist;
            nearest = node;
        }
    }
    return nearest;
}

Point RRT::steer(const Point& from, const Point& to) {
    double dist = from.distance(to);
    if (dist <= step_size) {
        return to;
    } else {
        double theta = std::atan2(to.y - from.y, to.x - from.x);
        return Point(from.x + step_size * std::cos(theta), from.y + step_size * std::sin(theta));
    }
}

bool RRT::reachedGoal(const Point& p) {
    return p.distance(goal) <= goal_tolerance;
}

void RRT::run() {
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < max_iterations; ++i) {
        Point rand_point = randomPoint();
        Node* nearest_node = nearestNode(rand_point);
        Point new_point = steer(nearest_node->point, rand_point);

        Node* new_node = new Node(new_point, nearest_node);
        nodes.push_back(new_node);

        if (reachedGoal(new_point)) {
            std::cout << "Goal reached!" << std::endl;
            printPath(new_node);
            return;
        }
    }
    std::cout << "Max iterations reached, goal not found." << std::endl;
}

void RRT::printPath(Node* node) {
    std::vector<Point> path;
    while (node != nullptr) {
        path.push_back(node->point);
        node = node->parent;
    }

    std::cout << "Path: " << std::endl;
    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        std::cout << "(" << it->x << ", " << it->y << ")" << std::endl;
    }
}
