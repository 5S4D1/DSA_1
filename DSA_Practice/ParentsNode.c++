#include <bits/stdc++.h>
using namespace std;

typedef struct ParentsNode
{
    int data;
    struct ParentsNode *left;
    struct ParentsNode *right;
} node;

node *createNode(int value)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
node *insertNode(node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    else
    {
        if (value < root->data)
            root->left = insertNode(root->left, value);
        else
            root->right = insertNode(root->right, value);
    }
    return root;
}

void printInOrder(node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    node *root = createNode(25);
    insertNode(root, 20);
    insertNode(root, 28);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 15);

    cout << "InOrder Print: ";
    printInOrder(root);
    cout << endl;
}