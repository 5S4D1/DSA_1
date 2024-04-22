/*
    Find the Parent Node and Node value by given root and a key value,
    from a Binary Search Tree.
*/

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
// parent node find
node *parent(node *root, int key)
{
    if (root == NULL)
        return NULL;

    node *temp = root;
    node *parent_node = NULL; // We'll store the parent node here

    while (temp != NULL)
    {
        if (temp->data < key)
        {
            parent_node = temp; // Update parent node
            temp = temp->right;
        }
        else if (temp->data > key)
        {
            parent_node = temp; // Update parent node
            temp = temp->left;
        }
        else // temp->data == key
        {
            if (temp == root) // If key is at the root
            {
                cout << "Key is at the root, so no parent." << endl;
                return NULL;
            }
            cout << "Parent is: " << parent_node->data << endl;
            return parent_node;
        }
    }
    cout << "Key not found." << endl;
    return NULL;
}

int main()
{
    node *root = createNode(25);
    insertNode(root, 20);
    insertNode(root, 28);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 15);
    insertNode(root, 12);

    cout << "InOrder Print: ";
    printInOrder(root);
    cout << endl;

    parent(root, 40);

    return 0;
}