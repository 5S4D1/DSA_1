#include <stdio.h>
#include <stdlib.h>

typedef struct BST_MinimunValue
{
    int data;
    struct BST_MinimunValue *right;
    struct BST_MinimunValue *left;
} Node;

Node *createNode(int x)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    printf("%d ", root->data);
    inOrderPrint(root->right);
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

void Minimum(Node *root)
{
    if (root == NULL)
        return;
    Minimum(root->left);
    printf("\nMinimum value is: %d\n", root->data);
    exit(1);
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

    inOrderPrint(root);
    Minimum(root);

    return 0;
}