#include <iostream>
#include "Maze.h"

using namespace std;

int main()
{
    cout << "====================================" << endl;
    cout << "     MAZE PATH FINDER SYSTEM" << endl;
    cout << "====================================" << endl;

    Maze maze(7, 7);

    maze.createSampleMaze();
    maze.display();

    return 0;
}