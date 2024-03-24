#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void printLL(struct node *head)
{
    if (head == NULL)
    {
        printf("Nothing in the Linked List.");
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

struct node *insert(struct node *head, struct node *new, int position)  // this is a function pointer
{
    if (position == 1)
    {
        new->link = head;
        return new;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->link;
    }
    if (temp != NULL)
    {
        new->link = temp->link;
        temp->link = new;
    }
    return head;
}

int main()
{
    struct node *node1 = malloc(sizeof(struct node));
    node1->data = 5;
    node1->link = NULL;

    struct node *node2 = malloc(sizeof(struct node));
    node2->data = 3;
    node2->link = NULL;
    node1->link = node2;

    printLL(node1);

    struct node *node3 = malloc(sizeof(struct node));
    node3->data = 7;
    node3->link = NULL;

    struct node *head = insert(node1, node3, 2);

    printLL(head);

    free(node1);
    free(node2);
    free(node3);
    free(head);

    return 0;
}