#ifndef ROUTE_HISTORY_H
#define ROUTE_HISTORY_H

#include <string>
#include <vector>
using namespace std;

struct RouteNode
{
    int routeId;
    vector<int> path;
    int moves;
    int totalCost;
    string algorithm;
    RouteNode *next;
};

class RouteHistory
{
private:
    RouteNode *head;

public:
    RouteHistory();

    void addRoute(int routeId, vector<int> path, int moves,
                  int totalCost, string algorithm);

    void displayHistory();
    int getCount();
};

#endif