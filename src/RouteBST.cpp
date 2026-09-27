#include <iostream>
#include "RouteBST.h"

using namespace std;

RouteBST::RouteBST()
{
    root = NULL;
}

BSTNode* RouteBST::insertNode(BSTNode *node,
                              int routeId,
                              int cost,
                              string algorithm)
{
    if (node == NULL)
    {
        BSTNode *newNode = new BSTNode;

        newNode->routeId = routeId;
        newNode->cost = cost;
        newNode->algorithm = algorithm;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (routeId < node->routeId)
    {
        node->left = insertNode(
            node->left,
            routeId,
            cost,
            algorithm
        );
    }
    else if (routeId > node->routeId)
    {
        node->right = insertNode(
            node->right,
            routeId,
            cost,
            algorithm
        );
    }

    return node;
}

void RouteBST::insert(int routeId,
                      int cost,
                      string algorithm)
{
    root = insertNode(
        root,
        routeId,
        cost,
        algorithm
    );
}

void RouteBST::inorder(BSTNode *node)
{
    if (node == NULL)
        return;

    inorder(node->left);

    cout << "Route ID: " << node->routeId
         << " | Algorithm: " << node->algorithm
         << " | Cost: " << node->cost
         << endl;

    inorder(node->right);
}

void RouteBST::display()
{
    cout << endl;
    cout << "========== BST ROUTES ==========" << endl;

    inorder(root);
}

BSTNode* RouteBST::searchNode(BSTNode *node,
                              int routeId)
{
    if (node == NULL || node->routeId == routeId)
        return node;

    if (routeId < node->routeId)
        return searchNode(node->left, routeId);

    return searchNode(node->right, routeId);
}

void RouteBST::search(int routeId)
{
    BSTNode *result = searchNode(root, routeId);

    if (result != NULL)
    {
        cout << endl;
        cout << "Route found in BST!" << endl;
        cout << "Route ID: " << result->routeId << endl;
        cout << "Algorithm: " << result->algorithm << endl;
        cout << "Cost: " << result->cost << endl;
    }
    else
    {
        cout << endl;
        cout << "Route not found in BST." << endl;
    }
}