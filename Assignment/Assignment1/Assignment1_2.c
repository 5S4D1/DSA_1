/*
Question 2 (15 Marks) - Doubly Linked List Operations

You are given the task of implementing various operations on a Doubly Linked List.
Write a class or structure for a Doubly Linked List that includes the following functionalities:

    ● Insertion: Implement a method to insert a new node at the beginning of the Doubly Linked List.
    ● Deletion: Implement a method to delete a specified node from the Doubly Linked List.
    ● Search: Implement a method to search for a given value in the Doubly Linked List.
    ● Traversal: Implement a method to traverse and print the elements of the Doubly Linked List.
    ● Size Count: Implement a method to count the number of nodes in the Doubly Linked List.

Requirements:
    ● Your class should maintain the doubly linked structure.
    ● Test your class by performing insertion, deletion, searching, traversal, and size count operations on a sample Doubly Linked List.

*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("\nMemory error!\n");
        exit(0);
    }
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Add a new node at the beginning of the Doubly Linked List
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = newNode(new_data);
    new_node->next = *head_ref;
    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}
// delete the n number node
struct Node deleteNode(struct Node *head, int n)
{
    printf("\nDelete %d no. node from the list. \n", n);
    struct Node *current = head;
    int cout = 0;
    while (current->next != NULL)
    {
        cout++;
        if (n == 1)
        {
            current->next->prev = NULL;
            head = current->next;
            break;
        }
        if (cout == n)
        {
            current->next->prev = current->prev;
            current->prev->next = current->next;
            break;
        }
        else
            current = current->next;
    }
    return *head;
}

void search(struct Node *head, int key)
{
    printf("\nSearch for %d: ", key);
    int count = 0;
    while (head != NULL)
    {
        if (head->data == key)
            count++;
        head = head->next;
    }
    if (count == 0)
        printf("Not Found.\n");
    else
        printf("Found %d Times.\n", count);
}

// print linked list
void printList(struct Node *head)
{
    printf("\nLinked list is :-\n");
    struct Node *temp = head;
    struct Node *hold = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        if (temp->next == NULL)
            hold = temp;

        temp = temp->next;
    }
    printf("\n");

    temp = hold;

    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Linked list size
void size_count(struct Node *head)
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty.\n");
        return;
    }
    int size = 0;
    while (head != NULL)
    {
        head = head->next;
        size++;
    }
    printf("\nLinked list size: %d\n", size);
}

int main()
{

    struct Node *head = NULL;
    size_count(head);
    printList(head);

    // pushing elements to the list
    push(&head, 7);
    push(&head, 1);
    push(&head, 5);
    push(&head, 9);
    push(&head, 3);
    push(&head, 6);
    push(&head, 8);
    push(&head, 2);
    push(&head, 4);
    push(&head, 4);

    
    printList(head);

    search(head, 10);
    search(head, 4);

    size_count(head);

    *head = deleteNode(head, 1);    // delete by it's node number.

    printList(head);
    size_count(head);

    return 0;
}