#include <bits/stdc++.h>
struct Node {
    int key;
    Node* left;
    Node* right;
};
struct Node* newNode(int value);
struct Node* insertValue(struct Node* root, int value, std::queue<Node *>& q);
Node* createTree(int arr[], int n);
void levelOrder(struct Node* root)

