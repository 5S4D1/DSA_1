#include <stdio.h>
#define n 5

int array[n];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == n - 1)
        printf("Queue is Full\n");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        array[rear] = x;
        printf("%d is insert in the Queue\n", array[rear]);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty \n");
        return;
    }
    else if (front == rear)
    {
        printf("%d is removed from the queue \n", array[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("%d is Deleted from the Queue\n", array[front]);
        front++;
    }
}

void peek()
{
    if (front == -1 || front > rear)
    {
        printf("The Queue is empty.\n");
    }
    else
    {
        printf("The element at the front of the Queue is %d.\n", array[front]);
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("The queue is empty.\n");
    }
    else
    {
        printf("\nElements in the queue are : ");
        for (i = front; i <= rear; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    display();

    return 0;
}