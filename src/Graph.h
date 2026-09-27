#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "Maze.h"

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adjacencyList;

    vector<int> lastBFSPath;
    vector<int> lastDijkstraPath;
    int lastDijkstraCost;

public:
    Graph(int v);

    void buildGraph(Maze &maze);
    void displayGraph();

    int getVertices();

    bool DFS(int current, int destination, vector<bool> &visited);
    void startDFS(Maze &maze);

    bool BFS(int start, int destination, vector<bool> &visited, vector<int> &parent);
    void startBFS(Maze &maze);

    void dijkstra(Maze &maze);
    void displayDijkstraPath(int start, int destination, vector<int> &parent, Maze &maze);

    void displayPath(int start, int destination, vector<int> &parent, Maze &maze);

    vector<int> getLastBFSPath();
    vector<int> getLastDijkstraPath();
    int getLastDijkstraCost();
};

#endif