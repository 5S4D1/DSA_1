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
    printf("%d ", root->data);
    inOrderPrint(root->right);
}

int Height(Node *root)
{
    if (root == NULL)
        return -1;

    int left_height = Height(root->left);
    int right_height = Height(root->right);

    return left_height > right_height ? left_height + 1 : right_height + 1;
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
    cout << endl;

    cout << "Height is: " << Height(root);

    return 0;
}