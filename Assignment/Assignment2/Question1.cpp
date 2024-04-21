#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
} node;
// Create a Node for Binary Tree
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
// Insertion Operation
node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    else
    {
        if (root->data > key)
            root->left = insert(root->left, key);

        else
            root->right = insert(root->right, key);
    }
    return root;
}
// Minimum Find Operation
node *Minimum(node *root)
{
    node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
// Deletion Operation
node *Delete(node *root, int key)
{
    if (root == NULL)
    {
        cout << "Binary Tree Is Empty or key not found!!" << endl;
        return NULL;
    }
    if (root->data < key)
        root->right = Delete(root->right, key);
    else if (root->data > key)
        root->left = Delete(root->left, key);
    else
    {
        // Node with only one child or no child
        if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        // Node with two children: Get the minimum value from the right subtree
        node *minimumNode = Minimum(root->right);
        // Copy the inorder successor's content to this node
        root->data = minimumNode->data;
        root->right = Delete(root, minimumNode->data);
    }
    return root;
}
// Search Operation
bool find(node *root, int key)
{
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;
    else if (root->data < key)
        find(root->right, key);
    else
        find(root->left, key);
}
// PostOrder Traversal Operations
void printPostOrder(node *root)
{
    if (root == NULL)
        return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}
// PreOrder Traversal Operations
void printPreOrder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
// InOrder Traversal Operations
void printInOrder(node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Height of a Binary Tree
int height(node *root)
{
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int main()
{
    node *root = NULL;
    root = insert(root, 28);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 18);
    insert(root, 50);

    if (find(root, 50) == true)
        cout << "Found." << endl;
    else
        cout << "Not Found." << endl;
    
    cout<<"PreOrder Print: ";
    printPreOrder(root);
    cout<<endl;
    cout<<"InOrder Print: ";
    printInOrder(root);
    cout<<endl;
    cout<<"PostOrder Print: ";
    printPostOrder(root);
    cout<<endl;

    root = Delete(root,45);
    cout<<"InOrder Print: ";
    printInOrder(root);
    cout<<endl;

    //int heigh = 
    cout<<"Binary Tree Height is:"<< height(root)<<endl;

    return 0;
}