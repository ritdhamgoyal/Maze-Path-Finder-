#ifndef ROUTE_SORTER_H
#define ROUTE_SORTER_H

#include <vector>
#include <string>
using namespace std;

struct RouteRecord
{
    int routeId;
    string algorithm;
    int moves;
    int cost;
};

class RouteSorter
{
private:
    void merge(vector<RouteRecord> &routes, int left, int mid, int right);
    void mergeSort(vector<RouteRecord> &routes, int left, int right);

    int partition(vector<RouteRecord> &routes, int low, int high);
    void quickSort(vector<RouteRecord> &routes, int low, int high);

public:
    void sortByCost(vector<RouteRecord> &routes);
    void sortByMoves(vector<RouteRecord> &routes);

    void display(vector<RouteRecord> routes);
};

#endif