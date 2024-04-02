#include <stdio.h>
#include <stdlib.h>

struct BST_Insert
{
    int data;
    struct BST_Insert *left;
    struct BST_Insert *right;
};

struct BST_Insert *create_node(int x)
{
    struct BST_Insert *temp = malloc(sizeof(struct BST_Insert));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
struct BST_Insert *Insert(struct BST_Insert *root, int value)
{
    if (root == NULL)
    {
        return create_node(value);
    }
    else
    {
        if (root->data > value)
            root->left = Insert(root->left, value);

        else
            root->right = Insert(root->right, value);
    }
    return root;
}

void inOrderPrint(struct BST_Insert *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    printf(" %d ", root->data);
    inOrderPrint(root->right);
}

int main()
{
    struct BST_Insert *root = create_node(5);

    Insert(root, 8);
    Insert(root, 4);

    inOrderPrint(root);

    return 0;
}
