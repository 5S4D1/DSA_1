/*
    Succeccer is a minimum value of right subtree.
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

Node *Delete(Node *root, int value)
{
    Node *temp = malloc(sizeof(Node));
    temp = root;

    if (root->data == value)
    {
        if (root->left == NULL)
        {
            printf("Delete Succesful!\n");
            return root->right;
        }
        else if (root->right == NULL)
        {
            printf("Delete Succesful!\n");
            return root->left;
        }
    }

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            // find the succeccer
            if (temp->left == NULL)
            {
                printf("Delete Succesful!!\n");
                return temp->right;
            }
            else if (temp->right == NULL)
            {
                printf("Delete Succesful!!\n");
                return temp->left;
            }
        }
        else if (temp->data < value)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return root;
}


Node *Minimum(Node *root, int key)
{
    if (root == NULL)
        return root;
    Minimum(root->left, key);
    printf("\nSucceccer of %d is: %d\n",key, root->data);
    return root;
}

void Succeccer(Node *root, int key)
{
    if(root->data == key)
    {
        Node *temp = Minimum(root->right, key);
        temp = temp->left;
        printf("\n%d<--- ",temp->data);
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
