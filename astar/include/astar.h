#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

class Node {
public:
    int x, y;
    double f, g, h;
    bool operator>(const Node& other) const;
};

class AStar {
public:
    double heuristic(int x1, int y1, int x2, int y2);
    std::vector<std::pair<int, int>> getNeighbors(int x, int y, int width, int height);
    std::vector<std::pair<int, int>> aStar(int startX, int startY, int goalX, int goalY, int width, int height);

private:
    void printOpenSet(priority_queue<Node, vector<Node>, greater<Node>> openSet);
};

#endif // ASTAR_H
