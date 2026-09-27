#include <iostream>
#include "Maze.h"

using namespace std;

Maze::Maze(int r, int c)
{
    rows = r;
    cols = c;

    grid.resize(rows, vector<int>(cols, 0));

    source = {0, 0};
    destination = {rows - 1, cols - 1};
}

void Maze::createSampleMaze()
{
    grid = {
        {2, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 3}
    };

    rows = 7;
    cols = 7;

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
            if (grid[i][j] == 0)
                cout << ". ";
            else if (grid[i][j] == 1)
                cout << "# ";
            else if (grid[i][j] == 2)
                cout << "S ";
            else if (grid[i][j] == 3)
                cout << "D ";
            else
                cout << "* ";
        }

        cout << endl;
    }

    cout << endl;
    cout << "S = Source" << endl;
    cout << "D = Destination" << endl;
    cout << "# = Wall" << endl;
    cout << ". = Open Path" << endl;
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