#ifndef ROUTE_BST_H
#define ROUTE_BST_H

#include <string>
using namespace std;

struct BSTNode
{
    int routeId;
    int cost;
    string algorithm;

    BSTNode *left;
    BSTNode *right;
};

class RouteBST
{
private:
    BSTNode *root;

    BSTNode* insertNode(BSTNode *node,
                        int routeId,
                        int cost,
                        string algorithm);

    void inorder(BSTNode *node);

    BSTNode* searchNode(BSTNode *node, int routeId);

public:
    RouteBST();

    void insert(int routeId, int cost, string algorithm);
    void search(int routeId);
    void display();
};

#endif