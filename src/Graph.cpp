#include <iostream>
#include "Graph.h"

using namespace std;

Graph::Graph(int v)
{
    vertices = v;
    adjacencyList.resize(vertices);
}

void Graph::buildGraph(Maze &maze)
{
    int rows = maze.getRows();
    int cols = maze.getCols();

    int directions[4][2] =
    {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze.getCell(i, j) == 1)
                continue;

            int current = i * cols + j;

            for (int d = 0; d < 4; d++)
            {
                int newRow = i + directions[d][0];
                int newCol = j + directions[d][1];

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols)
                {
                    if (maze.getCell(newRow, newCol) != 1)
                    {
                        int neighbor = newRow * cols + newCol;
                        adjacencyList[current].push_back(neighbor);
                    }
                }
            }
        }
    }
}

void Graph::displayGraph()
{
    cout << endl;
    cout << "========== GRAPH ADJACENCY LIST ==========" << endl;

    for (int i = 0; i < vertices; i++)
    {
        if (!adjacencyList[i].empty())
        {
            cout << "Vertex " << i << " -> ";

            for (int neighbor : adjacencyList[i])
            {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }
}

int Graph::getVertices()
{
    return vertices;
}