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

public:
    Graph(int v);

    void buildGraph(Maze &maze);
    void displayGraph();

    int getVertices();
};

#endif