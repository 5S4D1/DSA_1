/*
                    Binary Tree is:
              6             |           8
             / \            |          / \
            /   \           |         3   13
           4     8          |            /  \
          / \   / \         |           7   19
         3   5 7   9        |              /
    it's a balanced BST.    |            14
                            |              \
    *this tree use for      |               15
        below code.         |                 \
                            |                  18
                            |   it's a unbalanced BST.

    Balanced BT : (max_height - min_height) <= 1
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inOrderPrint(struct node *root)
{
    if (root == NULL)
        return;

    inOrderPrint(root->left);
    printf("%d ", root->data);
    inOrderPrint(root->right);
}

void search(struct node *root, int x)
{
    if (root == NULL)
    {
        printf("Tree is empty.");
        return;
    }

    while (root != NULL)
    {
        if (root->data == x)
        {
            printf("\n%d found.", x);
            return;
        }
        else if (root->data < x)
        {
            root = root->right;
        }
        else
            root = root->left;
    }
    printf("\n%d not found.", x);
    return;
}

int main()
{
    struct node *root = create_node(6);

    struct node *t1 = create_node(4);
    root->left = t1;
    struct node *t2 = create_node(8);
    root->right = t2;
    struct node *t3 = create_node(3);
    t1->left = t3;
    struct node *t4 = create_node(5);
    t1->right = t4;
    struct node *t5 = create_node(7);
    t2->left = t5;
    struct node *t6 = create_node(9);
    t2->right = t6;

    printf("In-order Traversal is: ");

    inOrderPrint(root);
    search(root, 2);
    search(root, 6);

    free(root);
    free(t1);
    free(t2);
    free(t3);
    free(t4);
    free(t5);
    free(t6);

    return 0;
}