#include "graph.h"
#include <queue>
#include <limits>

using namespace std;

Graph::Graph(int n) : adj(n) {}

void Graph::addEdge(int u, int v) {
    if (u >= 0 && u < adj.size() && v >= 0 && v < adj.size())
        adj[u].push_back(v);
}

int Graph::size() const { return adj.size(); }

void Graph::bfs(int start, Logger &logger) {
    vector<bool> visited(size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);
    logger.logStep("Push start", {start});

    while (!q.empty()) {
        int u = q.front(); q.pop();
        logger.logStep("Pop", {u});

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                logger.logStep("Push neighbor", {u, v});
            } else {
                logger.logStep("Neighbor visited", {u, v});
            }
        }
    }
}

void Graph::dfsUtil(int u, vector<bool> &visited, Logger &logger) {
    visited[u] = true;
    logger.logStep("Visit", {u});

    for (int v : adj[u]) {
        if (!visited[v]) {
            logger.logStep("Go deeper", {u, v});
            dfsUtil(v, visited, logger);
            logger.logStep("Return to", {u});
        } else {
            logger.logStep("Already visited", {u, v});
        }
    }
}

void Graph::dfs(int start, Logger &logger) {
    vector<bool> visited(size(), false);
    dfsUtil(start, visited, logger);
}

void Graph::dijkstra(int start, Logger &logger) {
    int n = size();
    const int INF = numeric_limits<int>::max();
    vector<int> dist(n, INF);
    dist[start] = 0;

    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    logger.logStep("Push start (dist=0)", {start, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        logger.logStep("Pop node with dist", {u, d});

        if (d != dist[u]) {
            logger.logStep("Skip outdated entry", {u, d});
            continue;
        }

        for (int v : adj[u]) {
            int newDist = d + 1; 
            logger.logStep("Relax edge", {u, v});

            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
                logger.logStep("Updated dist + pushed", {v, newDist});
            } else {
                logger.logStep("No update", {v});
            }
        }
    }

    logger.logMsg("Dijkstra Finished. Final distances:");
    logger.logStep("dist array", dist);
}