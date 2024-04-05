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

    // Node with only one child or no child
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the minimum value from the right subtree
        Node *minValueNode = Minimum(root->right);
        // Copy the inorder successor's content to this node
        root->data = minValueNode->data;
        // Delete the inorder successor
        root->right = Delete(root->right, minValueNode->data);
    }
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
