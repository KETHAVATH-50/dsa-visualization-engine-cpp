#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "logger.h"
#include "graph.h"
#include "sort.h"

using namespace std;

SpeedMode parseSpeed(const string &s) {
    if (s == "slow") return SpeedMode::SLOW;
    if (s == "fast") return SpeedMode::FAST;
    if (s == "none") return SpeedMode::NONE;
    return SpeedMode::NORMAL;
}

vector<int> readArrayFile(const string &path) {
    ifstream in(path);
    vector<int> a;
    int x;
    while (in >> x) a.push_back(x);
    return a;
}

Graph readGraphFile(const string &path) {
    ifstream in(path);
    vector<pair<int,int>> edges;
    int u, v, maxNode = -1;

    while (in >> u >> v) {
        edges.push_back({u, v});
        maxNode = max(maxNode, max(u, v));
    }

    Graph g(maxNode + 1);
    for (auto &e : edges)
        g.addEdge(e.first, e.second);

    return g;
}

void usage() {
    cerr << "Usage:\n";
    cerr << "  dsa_visualize bfs <graph> <start> [speed]\n";
    cerr << "  dsa_visualize dfs <graph> <start> [speed]\n";
    cerr << "  dsa_visualize dijkstra <graph> <start> [speed]\n";
    cerr << "  dsa_visualize sort <alg> <array> [speed]\n";
    cerr << "  alg: bubble | quick | merge | heap\n";
}

int main(int argc, char **argv) {
    if (argc < 2) { usage(); return 1; }

    string cmd = argv[1];

    if (cmd == "bfs") {
        if (argc < 4) { usage(); return 1; }
        Logger logger(parseSpeed(argc >= 5 ? argv[4] : "normal"));
        Graph g = readGraphFile(argv[2]);
        g.bfs(stoi(argv[3]), logger);

    } else if (cmd == "dfs") {
        if (argc < 4) { usage(); return 1; }
        Logger logger(parseSpeed(argc >= 5 ? argv[4] : "normal"));
        Graph g = readGraphFile(argv[2]);
        g.dfs(stoi(argv[3]), logger);

    } else if (cmd == "dijkstra") {
        if (argc < 4) { usage(); return 1; }
        Logger logger(parseSpeed(argc >= 5 ? argv[4] : "normal"));
        Graph g = readGraphFile(argv[2]);
        g.dijkstra(stoi(argv[3]), logger);

    } else if (cmd == "sort") {
        if (argc < 4) { usage(); return 1; }

        string alg = argv[2];
        vector<int> arr = readArrayFile(argv[3]);
        Logger logger(parseSpeed(argc >= 5 ? argv[4] : "normal"));

        if (alg == "bubble") Sorts::bubbleSort(arr, logger);
        else if (alg == "quick") Sorts::quickSort(arr, logger);
        else if (alg == "merge") Sorts::mergeSort(arr, logger);
        else if (alg == "heap")  Sorts::heapSort(arr, logger);
        else {
            cerr << "Unknown sort algorithm\n";
            return 1;
        }

    } else {
        usage();
        return 1;
    }

    return 0;
}