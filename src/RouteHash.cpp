#include <iostream>
#include "RouteHash.h"

using namespace std;

int RouteHash::hashFunction(int key)
{
    return key % 10;
}

void RouteHash::insert(int routeId, string algorithm, int cost)
{
    int index = hashFunction(routeId);

    int start = index;

    while (table[index].occupied)
    {
        index = (index + 1) % 10;

        if (index == start)
        {
            cout << "Hash table is full." << endl;
            return;
        }
    }

    table[index].routeId = routeId;
    table[index].algorithm = algorithm;
    table[index].cost = cost;
    table[index].occupied = true;
}

void RouteHash::search(int routeId)
{
    int index = hashFunction(routeId);
    int start = index;

    while (table[index].occupied)
    {
        if (table[index].routeId == routeId)
        {
            cout << endl;
            cout << "Route found in Hash Table!" << endl;
            cout << "Route ID: " << table[index].routeId << endl;
            cout << "Algorithm: " << table[index].algorithm << endl;
            cout << "Cost: " << table[index].cost << endl;
            return;
        }

        index = (index + 1) % 10;

        if (index == start)
            break;
    }

    cout << endl;
    cout << "Route not found." << endl;
}

void RouteHash::display()
{
    cout << endl;
    cout << "========== HASH TABLE ==========" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "Index " << i << ": ";

        if (table[i].occupied)
        {
            cout << "Route " << table[i].routeId
                 << " | "
                 << table[i].algorithm
                 << " | Cost "
                 << table[i].cost;
        }
        else
        {
            cout << "Empty";
        }

        cout << endl;
    }
}