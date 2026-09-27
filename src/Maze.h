#ifndef MAZE_H
#define MAZE_H

#include <vector>
using namespace std;

struct Point
{
    int row;
    int col;
};

class Maze
{
private:
    vector<vector<int>> grid;
    vector<vector<bool>> pathOverlay;

    int rows;
    int cols;

    Point source;
    Point destination;

public:
    Maze(int r, int c);

    void createSampleMaze();
    void display();

    Point getSource();
    Point getDestination();

    int getRows();
    int getCols();

    int getCell(int row, int col);
    int getCellCost(int row, int col);

    void markPath(vector<int> path);
};

#endif