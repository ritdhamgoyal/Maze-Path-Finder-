#ifndef ROUTE_HASH_H
#define ROUTE_HASH_H

#include <string>
using namespace std;

struct HashEntry
{
    int routeId;
    string algorithm;
    int cost;
    bool occupied;

    HashEntry()
    {
        routeId = -1;
        algorithm = "";
        cost = 0;
        occupied = false;
    }
};

class RouteHash
{
private:
    HashEntry table[10];

    int hashFunction(int key);

public:
    void insert(int routeId, string algorithm, int cost);
    void search(int routeId);
    void display();
};

#endif