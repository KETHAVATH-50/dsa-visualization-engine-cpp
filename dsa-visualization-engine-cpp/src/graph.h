#pragma once
#include <vector>
#include "logger.h"

class Graph {
public:
    Graph(int n);
    void addEdge(int u, int v);
    void bfs(int start, Logger &logger);
    void dfs(int start, Logger &logger);
    void dijkstra(int start, Logger &logger);
    int size() const;
private:
    std::vector<std::vector<int>> adj;
    void dfsUtil(int u, std::vector<bool> &visited, Logger &logger);
};