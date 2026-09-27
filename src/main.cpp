#include <iostream>
#include <vector>
#include <limits>

#include "Maze.h"
#include "Graph.h"
#include "RouteHistory.h"
#include "RouteHash.h"
#include "RouteBST.h"
#include "RouteSorter.h"

using namespace std;

int calculatePathCost(vector<int> path, Maze &maze)
{
    int cost = 0;

    for (int i = 1; i < path.size(); i++)
    {
        int row = path[i] / maze.getCols();
        int col = path[i] % maze.getCols();

        cost += maze.getCellCost(row, col);
    }

    return cost;
}

int main()
{
    cout << "========================================" << endl;
    cout << "      MAZE PATH FINDER SYSTEM" << endl;
    cout << "========================================" << endl;

    Maze maze(7, 7);

    maze.createSampleMaze();

    int totalVertices = maze.getRows() * maze.getCols();

    Graph graph(totalVertices);

    graph.buildGraph(maze);

    RouteHistory history;
    RouteHash hashTable;
    RouteBST bst;
    RouteSorter sorter;

    vector<RouteRecord> routes;

    int routeId = 0;
    int choice;

    int bfsMoves = -1;
    int bfsCost = -1;

    int dijkstraMoves = -1;
    int dijkstraCost = -1;

    do
    {
        cout << endl;
        cout << "========================================" << endl;
        cout << "              MAIN MENU" << endl;
        cout << "========================================" << endl;

        cout << "1. Display Maze" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. Run DFS" << endl;
        cout << "4. Run BFS" << endl;
        cout << "5. Run Dijkstra" << endl;
        cout << "6. Display Route History" << endl;
        cout << "7. Display Hash Table" << endl;
        cout << "8. Search Route using Hashing" << endl;
        cout << "9. Display BST" << endl;
        cout << "10. Search Route using BST" << endl;
        cout << "11. Sort Routes by Cost" << endl;
        cout << "12. Sort Routes by Moves" << endl;
        cout << "13. Display Project Statistics" << endl;
        cout << "14. Compare BFS and Dijkstra" << endl;
        cout << "0. Exit" << endl;

        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
            {
                maze.display();
                break;
            }

            case 2:
            {
                graph.displayGraph();
                break;
            }

            case 3:
            {
                graph.startDFS(maze);
                break;
            }

            case 4:
            {
                graph.startBFS(maze);

                vector<int> path = graph.getLastBFSPath();

                if (!path.empty())
                {
                    int moves = path.size() - 1;
                    int cost = calculatePathCost(path, maze);

                    bfsMoves = moves;
                    bfsCost = cost;

                    routeId++;

                    history.addRoute(
                        routeId,
                        path,
                        moves,
                        cost,
                        "BFS"
                    );

                    hashTable.insert(
                        routeId,
                        "BFS",
                        cost
                    );

                    bst.insert(
                        routeId,
                        cost,
                        "BFS"
                    );

                    RouteRecord record;

                    record.routeId = routeId;
                    record.algorithm = "BFS";
                    record.moves = moves;
                    record.cost = cost;

                    routes.push_back(record);

                    cout << endl;
                    cout << "BFS route saved successfully!" << endl;
                }

                break;
            }

            case 5:
            {
                graph.dijkstra(maze);

                vector<int> path =
                    graph.getLastDijkstraPath();

                if (!path.empty())
                {
                    int moves = path.size() - 1;
                    int cost =
                        graph.getLastDijkstraCost();

                    dijkstraMoves = moves;
                    dijkstraCost = cost;

                    routeId++;

                    history.addRoute(
                        routeId,
                        path,
                        moves,
                        cost,
                        "Dijkstra"
                    );

                    hashTable.insert(
                        routeId,
                        "Dijkstra",
                        cost
                    );

                    bst.insert(
                        routeId,
                        cost,
                        "Dijkstra"
                    );

                    RouteRecord record;

                    record.routeId = routeId;
                    record.algorithm = "Dijkstra";
                    record.moves = moves;
                    record.cost = cost;

                    routes.push_back(record);

                    cout << endl;
                    cout << "Dijkstra route saved successfully!"
                         << endl;
                }

                break;
            }

            case 6:
            {
                history.displayHistory();

                cout << endl;
                cout << "Total Routes Stored: "
                     << history.getCount()
                     << endl;

                break;
            }

            case 7:
            {
                hashTable.display();
                break;
            }

            case 8:
            {
                int id;

                cout << "Enter Route ID: ";
                cin >> id;

                hashTable.search(id);

                break;
            }

            case 9:
            {
                bst.display();
                break;
            }

            case 10:
            {
                int id;

                cout << "Enter Route ID: ";
                cin >> id;

                bst.search(id);

                break;
            }

            case 11:
            {
                vector<RouteRecord> sortedRoutes = routes;

                sorter.sortByCost(sortedRoutes);

                cout << endl;
                cout << "Routes sorted using Merge Sort by Cost."
                     << endl;

                sorter.display(sortedRoutes);

                break;
            }

            case 12:
            {
                vector<RouteRecord> sortedRoutes = routes;

                sorter.sortByMoves(sortedRoutes);

                cout << endl;
                cout << "Routes sorted using Quick Sort by Moves."
                     << endl;

                sorter.display(sortedRoutes);

                break;
            }

            case 13:
            {
                int normalCells = 0;
                int walls = 0;
                int sourceCells = 0;
                int destinationCells = 0;
                int checkpointCells = 0;
                int difficultCells = 0;
                int hazardCells = 0;

                for (int i = 0; i < maze.getRows(); i++)
                {
                    for (int j = 0; j < maze.getCols(); j++)
                    {
                        int cell = maze.getCell(i, j);

                        if (cell == 0)
                            normalCells++;
                        else if (cell == 1)
                            walls++;
                        else if (cell == 2)
                            sourceCells++;
                        else if (cell == 3)
                            destinationCells++;
                        else if (cell == 4)
                            checkpointCells++;
                        else if (cell == 6)
                            difficultCells++;
                        else if (cell == 7)
                            hazardCells++;
                    }
                }

                int totalCells =
                    maze.getRows() * maze.getCols();

                int openCells =
                    totalCells - walls;

                cout << endl;
                cout << "========== PROJECT STATISTICS =========="
                     << endl;

                cout << endl;
                cout << "----- MAZE INFORMATION -----" << endl;

                cout << "Maze Size: "
                     << maze.getRows()
                     << " x "
                     << maze.getCols()
                     << endl;

                cout << "Total Cells: "
                     << totalCells
                     << endl;

                cout << "Total Vertices: "
                     << totalVertices
                     << endl;

                cout << "Open Cells: "
                     << openCells
                     << endl;

                cout << "Normal Cells: "
                     << normalCells
                     << endl;

                cout << "Walls: "
                     << walls
                     << endl;

                cout << "Difficult Cells: "
                     << difficultCells
                     << endl;

                cout << "Hazard Cells: "
                     << hazardCells
                     << endl;

                cout << "Source Cells: "
                     << sourceCells
                     << endl;

                cout << "Destination Cells: "
                     << destinationCells
                     << endl;

                cout << "Checkpoint Cells: "
                     << checkpointCells
                     << endl;

                cout << endl;
                cout << "----- ROUTE INFORMATION -----" << endl;

                cout << "Routes Stored: "
                     << history.getCount()
                     << endl;

                if (bfsMoves != -1)
                {
                    cout << "BFS Moves: "
                         << bfsMoves
                         << endl;

                    cout << "BFS Cost: "
                         << bfsCost
                         << endl;
                }
                else
                {
                    cout << "BFS: Not executed yet"
                         << endl;
                }

                if (dijkstraMoves != -1)
                {
                    cout << "Dijkstra Moves: "
                         << dijkstraMoves
                         << endl;

                    cout << "Dijkstra Cost: "
                         << dijkstraCost
                         << endl;
                }
                else
                {
                    cout << "Dijkstra: Not executed yet"
                         << endl;
                }

                cout << endl;
                cout << "----- DATA STRUCTURES USED -----"
                     << endl;

                cout << "Graph: Adjacency List" << endl;
                cout << "DFS: Recursion" << endl;
                cout << "BFS: Queue" << endl;
                cout << "Dijkstra: Priority Queue / Min Heap"
                     << endl;
                cout << "Route History: Linked List" << endl;
                cout << "Route Search: Hash Table" << endl;
                cout << "Route Search: Binary Search Tree"
                     << endl;
                cout << "Sorting: Merge Sort and Quick Sort"
                     << endl;

                cout << endl;
                cout << "----- COMPLEXITY ANALYSIS -----"
                     << endl;

                cout << "DFS: O(V + E)" << endl;
                cout << "BFS: O(V + E)" << endl;
                cout << "Dijkstra: O((V + E) log V)"
                     << endl;
                cout << "Hash Search: Average O(1)" << endl;
                cout << "BST Search: Average O(log V)" << endl;
                cout << "Merge Sort: O(n log n)" << endl;
                cout << "Quick Sort: Average O(n log n)"
                     << endl;

                break;
            }

            case 14:
            {
                cout << endl;
                cout << "========== ROUTE COMPARISON =========="
                     << endl;

                if (bfsMoves == -1)
                {
                    cout << endl;
                    cout << "Please run BFS first." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "BFS" << endl;
                    cout << "Moves: " << bfsMoves << endl;
                    cout << "Cost: " << bfsCost << endl;
                }

                if (dijkstraMoves == -1)
                {
                    cout << endl;
                    cout << "Please run Dijkstra first." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Dijkstra" << endl;
                    cout << "Moves: "
                         << dijkstraMoves
                         << endl;

                    cout << "Cost: "
                         << dijkstraCost
                         << endl;
                }

                if (bfsMoves != -1 &&
                    dijkstraMoves != -1)
                {
                    cout << endl;
                    cout << "BFS focuses on minimum number of moves."
                         << endl;

                    cout << "Dijkstra focuses on minimum weighted cost."
                         << endl;
                }

                break;
            }

            case 0:
            {
                cout << endl;
                cout << "Exiting Maze Path Finder System..."
                     << endl;

                break;
            }

            default:
            {
                cout << endl;
                cout << "Invalid choice. Please try again."
                     << endl;
            }
        }

    } while (choice != 0);

    return 0;
}