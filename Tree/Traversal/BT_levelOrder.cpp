#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef struct BT_levelOrder
{
    int data;
    struct BT_levelOrder *right;
    struct BT_levelOrder *left;
} Node;

Node *createNode(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = value;
    temp->right = NULL;
    temp->left = NULL;

    return temp;
}

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    else
    {
        if (root->data > value)
            root->left = insertNode(root->left, value);
        else
            root->right = insertNode(root->right, value);
    }
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
    if (root == NULL)
        return;

    queue<Node *> Q;
    Q.push(root);

    // while there is at least one discovered
    while (!Q.empty())
    {
        Node *current = Q.front();
        cout << current->data << " ";

        if (current->left != NULL)
            Q.push(current->left);
            
        if (current->right != NULL)
            Q.push(current->right);

        Q.pop(); // remove the element at front
    }
}

int main()
{
    Node *root = createNode(30);
    insertNode(root, 23);
    insertNode(root, 25);
    insertNode(root, 35);
    insertNode(root, 48);
    insertNode(root, 50);
    insertNode(root, 42);
    insertNode(root, 45);
    insertNode(root, 43);
    insertNode(root, 46);

    cout << "Level Order Traversal:" << endl;
    levelOrder(root);

    cout << "\n\n" << "In-Order Traversal:" << endl;
    inOrderPrint(root);

    return 0;
}