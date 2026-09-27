#include <iostream>
#include "RouteHistory.h"

using namespace std;

RouteHistory::RouteHistory()
{
    head = NULL;
}

void RouteHistory::addRoute(int routeId, vector<int> path, int moves,
                            int totalCost, string algorithm)
{
    RouteNode *newNode = new RouteNode;

    newNode->routeId = routeId;
    newNode->path = path;
    newNode->moves = moves;
    newNode->totalCost = totalCost;
    newNode->algorithm = algorithm;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        RouteNode *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void RouteHistory::displayHistory()
{
    if (head == NULL)
    {
        cout << endl;
        cout << "No route history available." << endl;
        return;
    }

    RouteNode *temp = head;

    cout << endl;
    cout << "========== ROUTE HISTORY ==========" << endl;

    while (temp != NULL)
    {
        cout << endl;
        cout << "Route ID: " << temp->routeId << endl;
        cout << "Algorithm: " << temp->algorithm << endl;
        cout << "Moves: " << temp->moves << endl;
        cout << "Total Cost: " << temp->totalCost << endl;

        cout << "Path: ";

        for (int i = 0; i < temp->path.size(); i++)
        {
            cout << temp->path[i];

            if (i != temp->path.size() - 1)
                cout << " -> ";
        }

        cout << endl;

        temp = temp->next;
    }
}

int RouteHistory::getCount()
{
    int count = 0;

    RouteNode *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}