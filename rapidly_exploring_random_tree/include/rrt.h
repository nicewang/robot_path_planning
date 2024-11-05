#ifndef RRT_H
#define RRT_H

#include <iostream>
#include <vector>
#include <cmath>  // for std::sqrt and std::log
#include <limits> // for std::numeric_limits

class Point {
public:
    double x, y;
    Point(double _x = 0, double _y = 0);
    double distance(const Point& other) const;
};

class Node {
public:
    Point point;
    Node* parent;
    Node(const Point& p, Node* par = nullptr);
};

class RRT {
private:
    Point start, goal;
    double step_size;
    double goal_tolerance;
    int max_iterations;
    double x_min, x_max, y_min, y_max;
    std::vector<Node*> nodes;

public:
    RRT(const Point& s, const Point& g, double step, double tol, int max_iter, double x_min, double x_max, double y_min, double y_max);
    ~RRT();

    Point randomPoint();
    Node* nearestNode(const Point& p);
    Point steer(const Point& from, const Point& to);
    bool reachedGoal(const Point& p);
    void run();
    void printPath(Node* node);
};

#endif
