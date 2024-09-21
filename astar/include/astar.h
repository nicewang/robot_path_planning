#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <utility>

struct Node {
    int x, y;
    double f, g, h;
    bool operator>(const Node& other) const;
};

double heuristic(int x1, int y1, int x2, int y2);
std::vector<std::pair<int, int>> getNeighbors(int x, int y, int width, int height);
std::vector<std::pair<int, int>> aStar(int startX, int startY, int goalX, int goalY, int width, int height);

#endif // ASTAR_H
