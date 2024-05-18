/*
    Level Order Print of the binary tree.
    Time complexity of Level Order is 𝑂(N)     N = number of Nodes
    T(n) = T(n-1) + T(1) + 𝑂(1) = 𝑂(n)
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct BST_Height
{
    int data;
    struct BST_Height *left;
    struct BST_Height *right;
} Node;

Node *createNode(int x)
{
    Node *temp = (Node *)malloc(sizeof(Node)); // in C++ mustbe do typecast
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node *InsertNode(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    else
    {
        if (root->data > value)
            root->left = InsertNode(root->left, value);

        else
            root->right = InsertNode(root->right, value);
    }
    return root;
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

void levelOrder(Node *root)
{
    queue<Node *> queue;
    queue.push(root);
    Node *currentNode = NULL;
    while (queue.empty() == false)
    {
        currentNode = queue.front();
        queue.pop();
        cout << currentNode->data << " ";

        if (currentNode->left != NULL)
        {
            queue.push(currentNode->left);
        }
        if (currentNode->right != NULL)
        {
            queue.push(currentNode->right);
        }
    }
}

int main()
{
    Node *root = createNode(30);
    InsertNode(root, 23);
    InsertNode(root, 25);
    InsertNode(root, 35);
    InsertNode(root, 48);
    InsertNode(root, 50);
    InsertNode(root, 42);
    InsertNode(root, 45);
    InsertNode(root, 43);
    InsertNode(root, 46);

    cout << "In-Order Traversal of the constructed tree is :" << endl;
    inOrderPrint(root);
    cout << "\n \n";

    cout << "Level Order is: \n";
    levelOrder(root);

    return 0;
}