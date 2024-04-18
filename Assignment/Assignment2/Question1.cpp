#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} node;

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    else
    {
        if (root->data > key)
            root->left = insert(root->left, key);

        else
            root->right = insert(root->right, key);
    }

    return root;
}

void inorderPrint(node *root)
{
    if (root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 10);

    return 0;
}