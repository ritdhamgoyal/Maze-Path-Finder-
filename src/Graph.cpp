#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include "Graph.h"

using namespace std;

Graph::Graph(int v)
{
    vertices = v;
    adjacencyList.resize(vertices);

    lastDijkstraCost = 0;
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

bool Graph::DFS(int current, int destination, vector<bool> &visited)
{
    visited[current] = true;

    cout << "Visiting vertex: " << current << endl;

    if (current == destination)
    {
        return true;
    }

    for (int neighbor : adjacencyList[current])
    {
        if (!visited[neighbor])
        {
            if (DFS(neighbor, destination, visited))
            {
                return true;
            }
        }
    }

    return false;
}

void Graph::startDFS(Maze &maze)
{
    int cols = maze.getCols();

    Point source = maze.getSource();
    Point destination = maze.getDestination();

    int start = source.row * cols + source.col;
    int end = destination.row * cols + destination.col;

    vector<bool> visited(vertices, false);

    cout << endl;
    cout << "========== DFS TRAVERSAL ==========" << endl;

    bool found = DFS(start, end, visited);

    cout << endl;

    if (found)
        cout << "Destination found using DFS!" << endl;
    else
        cout << "Destination cannot be reached using DFS." << endl;
}

bool Graph::BFS(int start, int destination,
                vector<bool> &visited,
                vector<int> &parent)
{
    queue<int> q;

    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << "Visiting vertex: " << current << endl;

        if (current == destination)
        {
            return true;
        }

        for (int neighbor : adjacencyList[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    return false;
}

void Graph::displayPath(int start, int destination,
                        vector<int> &parent, Maze &maze)
{
    vector<int> path;

    int current = destination;

    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    lastBFSPath = path;

    cout << endl;
    cout << "========== BFS PATH ==========" << endl;

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    cout << "Number of vertices in path: "
         << path.size() << endl;

    cout << "Number of moves: "
         << path.size() - 1 << endl;

    maze.markPath(path);

    cout << endl;
    cout << "========== MAZE WITH BFS PATH ==========" << endl;

    maze.display();
}

void Graph::startBFS(Maze &maze)
{
    int cols = maze.getCols();

    Point source = maze.getSource();
    Point destination = maze.getDestination();

    int start = source.row * cols + source.col;
    int end = destination.row * cols + destination.col;

    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);

    cout << endl;
    cout << "========== BFS TRAVERSAL ==========" << endl;

    bool found = BFS(start, end, visited, parent);

    cout << endl;

    if (found)
    {
        cout << "Destination found using BFS!" << endl;

        displayPath(start, end, parent, maze);
    }
    else
    {
        cout << "Destination cannot be reached using BFS." << endl;
    }
}

void Graph::dijkstra(Maze &maze)
{
    int cols = maze.getCols();

    Point source = maze.getSource();
    Point destination = maze.getDestination();

    int start = source.row * cols + source.col;
    int end = destination.row * cols + destination.col;

    const int INF = 1000000000;

    vector<int> distance(vertices, INF);
    vector<int> parent(vertices, -1);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    distance[start] = 0;

    pq.push({0, start});

    cout << endl;
    cout << "========== DIJKSTRA ALGORITHM ==========" << endl;

    while (!pq.empty())
    {
        int currentDistance = pq.top().first;
        int current = pq.top().second;

        pq.pop();

        if (currentDistance != distance[current])
            continue;

        cout << "Processing vertex: " << current
             << " | Current Cost: "
             << currentDistance << endl;

        if (current == end)
            break;

        for (int neighbor : adjacencyList[current])
        {
            int row = neighbor / cols;
            int col = neighbor % cols;

            int movementCost = maze.getCellCost(row, col);

            int newDistance =
                currentDistance + movementCost;

            if (newDistance < distance[neighbor])
            {
                distance[neighbor] = newDistance;
                parent[neighbor] = current;

                pq.push({newDistance, neighbor});
            }
        }
    }

    if (distance[end] == INF)
    {
        cout << endl;
        cout << "Destination cannot be reached using Dijkstra."
             << endl;
        return;
    }

    cout << endl;
    cout << "Destination found using Dijkstra!" << endl;

    cout << "Minimum Cost: "
         << distance[end] << endl;

    displayDijkstraPath(start, end, parent, maze);
}

void Graph::displayDijkstraPath(int start, int destination,
                                vector<int> &parent,
                                Maze &maze)
{
    vector<int> path;

    int current = destination;

    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    lastDijkstraPath = path;

    cout << endl;
    cout << "========== DIJKSTRA PATH ==========" << endl;

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    cout << endl;

    cout << "Number of vertices in path: "
         << path.size() << endl;

    cout << "Number of moves: "
         << path.size() - 1 << endl;

    int totalCost = 0;

    for (int i = 1; i < path.size(); i++)
    {
        int row = path[i] / maze.getCols();
        int col = path[i] % maze.getCols();

        totalCost += maze.getCellCost(row, col);
    }

    lastDijkstraCost = totalCost;

    cout << "Total Path Cost: "
         << totalCost << endl;
}

vector<int> Graph::getLastBFSPath()
{
    return lastBFSPath;
}

vector<int> Graph::getLastDijkstraPath()
{
    return lastDijkstraPath;
}

int Graph::getLastDijkstraCost()
{
    return lastDijkstraCost;
}