#include <iostream>
#include "Maze.h"

using namespace std;

Maze::Maze(int r, int c)
{
    rows = r;
    cols = c;

    grid.resize(rows, vector<int>(cols, 0));
    pathOverlay.resize(rows, vector<bool>(cols, false));

    source = {0, 0};
    destination = {rows - 1, cols - 1};
}

void Maze::createSampleMaze()
{
    grid = {
        {2, 0, 6, 1, 0, 0, 0},
        {1, 1, 6, 1, 0, 1, 0},
        {0, 0, 0, 0, 6, 1, 0},
        {0, 1, 1, 1, 6, 1, 0},
        {0, 0, 0, 0, 7, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 3}
    };

    rows = 7;
    cols = 7;

    pathOverlay.assign(rows, vector<bool>(cols, false));

    source = {0, 0};
    destination = {6, 6};
}

void Maze::display()
{
    cout << endl;
    cout << "========== MAZE ==========" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (pathOverlay[i][j] &&
                !(i == source.row && j == source.col) &&
                !(i == destination.row && j == destination.col))
            {
                cout << "* ";
            }
            else if (grid[i][j] == 0)
            {
                cout << ". ";
            }
            else if (grid[i][j] == 1)
            {
                cout << "# ";
            }
            else if (grid[i][j] == 2)
            {
                cout << "S ";
            }
            else if (grid[i][j] == 3)
            {
                cout << "D ";
            }
            else if (grid[i][j] == 4)
            {
                cout << "C ";
            }
            else if (grid[i][j] == 6)
            {
                cout << "2 ";
            }
            else if (grid[i][j] == 7)
            {
                cout << "5 ";
            }
        }

        cout << endl;
    }

    cout << endl;
    cout << "S = Source" << endl;
    cout << "D = Destination" << endl;
    cout << "C = Checkpoint" << endl;
    cout << "# = Wall" << endl;
    cout << ". = Normal Path (Cost 1)" << endl;
    cout << "2 = Difficult Path (Cost 2)" << endl;
    cout << "5 = Hazard Path (Cost 5)" << endl;
    cout << "* = BFS Path" << endl;
}

void Maze::markPath(vector<int> path)
{
    pathOverlay.assign(rows, vector<bool>(cols, false));

    for (int vertex : path)
    {
        int row = vertex / cols;
        int col = vertex % cols;

        pathOverlay[row][col] = true;
    }
}

Point Maze::getSource()
{
    return source;
}

Point Maze::getDestination()
{
    return destination;
}

int Maze::getRows()
{
    return rows;
}

int Maze::getCols()
{
    return cols;
}

int Maze::getCell(int row, int col)
{
    return grid[row][col];
}

int Maze::getCellCost(int row, int col)
{
    int cell = grid[row][col];

    if (cell == 0 || cell == 2 || cell == 3 || cell == 4)
        return 1;

    if (cell == 6)
        return 2;

    if (cell == 7)
        return 5;

    return 1;
}