#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

struct Node deletion(struct Node *head, struct Node *del)   // this is a function return pointer
{
    if (head == del)
    {
        struct Node *new = head->link;
        return *new;
    }
    struct Node *current = head;
    while (current->link != del)
    {
        current = current->link;
    }
    if (current->link == NULL)
    {
        return *head;
    }
    struct Node *temp = current->link;
    current->link = current->link->link;
    
    return *head;
}

int main()
{
    struct Node *node1 = malloc(sizeof(struct Node));
    node1->data = 34;
    node1->link = NULL;

    struct Node *head = node1;

    struct Node *node2 = malloc(sizeof(struct Node));
    node2->data = 4;
    node2->link = NULL;
    node1->link = node2;

    struct Node *node3 = malloc(sizeof(struct Node));
    node3->data = 57;
    node3->link = NULL;
    node2->link = node3;

    print(node1);
    deletion(node1, node2);
    print(node1);

    return 0;
}