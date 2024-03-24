#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *left_node1, struct ListNode *right_node1)
{
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));
    struct ListNode *current = dummyHead;   //  initially, 'dummyHead' and 'current' point to the same node.
    int carry = 0;

    while (left_node1 != NULL || right_node1 != NULL)
    {
        //            condition              true       false
        int x = (left_node1 != NULL) ? left_node1->val : 0;
        int y = (right_node1 != NULL) ? right_node1->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        if (left_node1 != NULL)
            left_node1 = left_node1->next;
        if (right_node1 != NULL)
            right_node1 = right_node1->next;
    }

    if (carry > 0)
    {
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
        current->next = NULL;
    }

    struct ListNode *result = dummyHead->next;

    return result;
}

void printList(struct ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // Left side value
    struct ListNode *left_node1 = malloc(sizeof(struct ListNode));
    left_node1->val = 2;
    struct ListNode *left_node2 = malloc(sizeof(struct ListNode));
    left_node2->val = 4;
    left_node1->next = left_node2;
    struct ListNode *left_node3 = malloc(sizeof(struct ListNode));
    left_node2->next = left_node3;
    left_node3->val = 3;
    left_node3->next = NULL;

    // Right side value
    struct ListNode *right_node1 = malloc(sizeof(struct ListNode));
    right_node1->val = 5;
    struct ListNode *right_node2 = malloc(sizeof(struct ListNode));
    right_node2->val = 6;
    right_node1->next = right_node2;
    struct ListNode *right_node3 = malloc(sizeof(struct ListNode));
    right_node3->val = 4;
    right_node2->next = right_node3;
    right_node3->next = NULL;

    // Printing the input linked lists
    printf("Input List 1: ");
    printList(left_node1);
    printf("Input List 2: ");
    printList(right_node1);

    // Adding the two numbers
    struct ListNode *result = addTwoNumbers(left_node1, right_node1);

    // Printing the result
    printf("Sum: ");
    printList(result);

    free(left_node1);
    free(left_node2);
    free(left_node3);
    free(right_node1);
    free(right_node2);
    free(right_node3);
    free(result);

    return 0;
}
