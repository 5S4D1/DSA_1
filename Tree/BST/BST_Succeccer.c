#include <stdio.h>
#include <stdlib.h>

typedef struct BST_Succeccer
{
    int data;
    struct BST_Succeccer *right;
    struct BST_Succeccer *left;
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

Node *Minimum(Node *root, int key)
{
    if (root == NULL)
        return root;

    Minimum(root->left, key);
    printf("\nSucceccer of %d is: %d\n",key, root->data);
    exit(1);
}

void Succeccer(Node *root, int key)
{
    if(root->data == key)
    {
        root = Minimum(root->right, key);
        return;
    }
    else if(root->data > key)
        Succeccer(root->left, key);
    else
        Succeccer(root->right, key);

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
    Succeccer(root,35);

    return 0;
}