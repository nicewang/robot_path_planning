#include "../include/astar.h"
#include <queue>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

bool Node::operator>(const Node& other) const {
    return f > other.f;
}

double heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2); // Manhattan distance
}

vector<pair<int, int>> getNeighbors(int x, int y, int width, int height) {
    vector<pair<int, int>> neighbors;
    if (x > 0) neighbors.emplace_back(x - 1, y);
    if (x < width - 1) neighbors.emplace_back(x + 1, y);
    if (y > 0) neighbors.emplace_back(x, y - 1);
    if (y < height - 1) neighbors.emplace_back(x, y + 1);
    return neighbors;
}

void printOpenSet(priority_queue<Node, vector<Node>, greater<Node>> openSet) {
    cout << "Open set (nodes in queue):" << endl;
    while (!openSet.empty()) {
        Node node = openSet.top();
        cout << "Node(" << node.x << ", " << node.y << ") - f: " << node.f << ", g: " << node.g << ", h: " << node.h << endl;
        openSet.pop();
    }
}

vector<pair<int, int>> aStar(int startX, int startY, int goalX, int goalY, int width, int height) {
    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_map<int, Node> allNodes;
    vector<vector<bool>> closedSet(height, vector<bool>(width, false));

    Node start{startX, startY, 0, 0, heuristic(startX, startY, goalX, goalY)};
    openSet.push(start);
    allNodes[startY * width + startX] = start;

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        cout << "Current node: (" << current.x << ", " << current.y << ") - f: " << current.f << ", g: " << current.g << ", h: " << current.h << endl;

        if (current.x == goalX && current.y == goalY) {
            vector<pair<int, int>> path;
            path.emplace_back(current.x, current.y);
            return path; // Return path (only the target node is returned here, and the actual application needs to track the path)
        }

        closedSet[current.y][current.x] = true;

        for (const auto& neighbor : getNeighbors(current.x, current.y, width, height)) {
            int neighborX = neighbor.first;
            int neighborY = neighbor.second;

            if (closedSet[neighborY][neighborX]) continue;

            double tentative_g = current.g + 1; // 假设移动成本为1
            Node neighborNode{neighborX, neighborY, 0, tentative_g, heuristic(neighborX, neighborY, goalX, goalY)};

            if (allNodes.find(neighborY * width + neighborX) == allNodes.end() || tentative_g < allNodes[neighborY * width + neighborX].g) {
                neighborNode.f = neighborNode.g + neighborNode.h;
                allNodes[neighborY * width + neighborX] = neighborNode;
                openSet.push(neighborNode);
            }
        }

        // 打印当前优先队列中的节点
        printOpenSet(openSet);
        cout << "-------------------------------" << endl;
    }

    return {}; // No path found
}
