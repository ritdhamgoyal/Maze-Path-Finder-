#include <iostream>
#include "Maze.h"
#include "Graph.h"

using namespace std;

int main()
{
    cout << "====================================" << endl;
    cout << "     MAZE PATH FINDER SYSTEM" << endl;
    cout << "====================================" << endl;

    Maze maze(7, 7);

    maze.createSampleMaze();
    maze.display();

    int totalVertices = maze.getRows() * maze.getCols();

    Graph graph(totalVertices);

    graph.buildGraph(maze);
    graph.displayGraph();

    return 0;
}