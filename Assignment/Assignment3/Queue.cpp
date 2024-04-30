/*
    4.  Basic Queue Implementation
        ●   void enqueue(int x)
        ●   int dequeue()
        ●   bool isEmpty()
    5.  Stack Implementation Using Queues
        ●   void push(int x)
        ●   int pop()
        ●   bool isEmpty()
    6.  Testing the Stack Implementation
*/
#include <iostream>
using namespace std;
class Queue
{
private:
    static const int MAX_SIZE = 100;
    int array1[MAX_SIZE];
    int frontIndex, rearIndex;

public:
    Queue()
    {
        frontIndex = -1;
        rearIndex = -1;
    }
    //  Add element x to the back of the queue.
    void enqueue(int x)
    {
        if (rearIndex == MAX_SIZE - 1)
            cout << "Queue is full!" << endl;
        else
        {
            if (frontIndex == -1)
                frontIndex = 0;
            rearIndex++;
            array1[rearIndex] = x;
            cout << "Element " << x << " is added to the queue." << endl;
        }
    }
    //  Remove and retrieve the element from the front of the  queue.
    int dequeue()
    {
        int n = array1[frontIndex];
        if (frontIndex == -1 || frontIndex > rearIndex)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else if (frontIndex == rearIndex)
        {
            cout << array1[frontIndex] << " removed from the Queue." << endl;
            frontIndex = -1;
            rearIndex = -1;
            return n;
        }
        else
        {
            cout << array1[frontIndex] << " removed from the Queue." << endl;
            frontIndex++;
            return n;
        }
        return n;
    }
    //  Determine if the queue is empty, returning true if it is, and  false otherwise.
    bool isEmpty()
    {
        return frontIndex == -1 && rearIndex == -1;
    }
};
class Stack
{
private:
    Queue q2, q1;

public:
    //  Add element x to the top of the stack.
    void push(int x)
    {
        q1.enqueue(x);
        while (!q2.isEmpty())
        {
            q1.enqueue(q2.dequeue());
        }
        swap(q2, q1);
    }
    //  Remove and retrieve the element from the top of the stack.
    int pop()
    {
        if (q2.isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return q2.dequeue();
    }
    //  Determine if the stack is empty, returning true if it is, and  false otherwise.
    bool isEmpty()
    {
        return q2.isEmpty();
    }
};
int main()
{
    Queue q;
    Stack s;
    q.enqueue(1);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    cout << q.isEmpty() << endl;
    s.push(4);
    s.push(2);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl;

    return 0;
}