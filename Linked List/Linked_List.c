#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;  // Now, struct node is a data type remember.
};

void print(struct node *head)
{
    if (head == NULL)
        printf("Linked List is empty.");
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *node1 = malloc(sizeof(struct node));
    node1->data = 98;
    node1->link = NULL;
    head->link = node1;

    struct node *node2 = malloc(sizeof(struct node));
    node2->data = 8;
    node2->link = NULL;
    node1->link = node2;
    printf("Linked list is:\n");
    print(head);

    return 0;
}