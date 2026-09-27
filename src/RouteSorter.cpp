#include <iostream>
#include "RouteSorter.h"

using namespace std;

void RouteSorter::merge(vector<RouteRecord> &routes,
                        int left, int mid, int right)
{
    vector<RouteRecord> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (routes[i].cost <= routes[j].cost)
        {
            temp.push_back(routes[i]);
            i++;
        }
        else
        {
            temp.push_back(routes[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(routes[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(routes[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++)
    {
        routes[left + k] = temp[k];
    }
}

void RouteSorter::mergeSort(vector<RouteRecord> &routes,
                            int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(routes, left, mid);
    mergeSort(routes, mid + 1, right);

    merge(routes, left, mid, right);
}

void RouteSorter::sortByCost(vector<RouteRecord> &routes)
{
    if (routes.size() > 1)
        mergeSort(routes, 0, routes.size() - 1);
}

int RouteSorter::partition(vector<RouteRecord> &routes,
                           int low, int high)
{
    int pivot = routes[high].moves;

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (routes[j].moves <= pivot)
        {
            i++;

            RouteRecord temp = routes[i];
            routes[i] = routes[j];
            routes[j] = temp;
        }
    }

    RouteRecord temp = routes[i + 1];
    routes[i + 1] = routes[high];
    routes[high] = temp;

    return i + 1;
}

void RouteSorter::quickSort(vector<RouteRecord> &routes,
                            int low, int high)
{
    if (low < high)
    {
        int pi = partition(routes, low, high);

        quickSort(routes, low, pi - 1);
        quickSort(routes, pi + 1, high);
    }
}

void RouteSorter::sortByMoves(vector<RouteRecord> &routes)
{
    if (routes.size() > 1)
        quickSort(routes, 0, routes.size() - 1);
}

void RouteSorter::display(vector<RouteRecord> routes)
{
    if (routes.empty())
    {
        cout << endl;
        cout << "No routes available for sorting." << endl;
        return;
    }

    cout << endl;
    cout << "========== SORTED ROUTES ==========" << endl;

    for (int i = 0; i < routes.size(); i++)
    {
        cout << "Route ID: " << routes[i].routeId
             << " | Algorithm: " << routes[i].algorithm
             << " | Moves: " << routes[i].moves
             << " | Cost: " << routes[i].cost
             << endl;
    }
}