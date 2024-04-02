/*
    Succeccer is a minimum value of right subtree.

    How it works:
    Case 1. If the node is a leaf node, remove it by removing the link to it.
    Case 2. If the node only has one child node, connect the parent node of the node you want to remove to that child node.
    Case 3. If the node has both right and left child nodes: Find the node's in-order successor, change values with that node, then delete it.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct BST_DeleteNode
{
    int data;
    struct BST_DeleteNode *right;
    struct BST_DeleteNode *left;
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

Node *Minimum(Node *root)
{
    Node *current = root;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node *Delete(Node *root, int value)
{

    if (root == NULL)
    {
        printf("\nBinary Tree is Empty!\n");
        return NULL;
    }

    if (value < root->data)
        root->left = Delete(root->left, value);

    else if (value > root->data)
        root->right = Delete(root->right, value);

    /* 2. If the node to be deleted is a leaf node */
    else if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    /* 3. If node to be deleted has two children:
         a) Get the inorder successor (next_node)  of the node to be deleted
         b) Copy the content of next_node to the node to be deleted
         c) Delete the copy of next_node as we don't need it anymore
    */
    Node *minValueNode = Minimum(root->right);
    root->data = minValueNode->data;
    root->right = Delete(root->right, minValueNode->data);

    return root;
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
    printf("\n");
    root = Delete(root, 30);
    inOrderPrint(root);

    return 0;
}
