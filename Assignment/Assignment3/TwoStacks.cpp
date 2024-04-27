/*
    You are tasked with implementing two stacks using  a single array.
    Design a class  TwoStacks that allows you to perform operations on these stacks efficiently.
*/
#include <bits/stdc++.h>
using namespace std;

class TwoStacks
{
private:
    int top1, top2, capacity;
    int *arr;

public:
    // Constructor to initialize the array and size
    TwoStacks(int maxSize)
    {
        arr = new int[maxSize];
        top1 = -1;
        top2 = maxSize;
        capacity = maxSize;
    }
    //  Push element x onto the first stack
    void pushStack1(int x)
    {
        if (top1 < top2 - 1)
        {
            arr[++top1] = x;
        }
        else
        {
            cout << "Stack Overflow. Cannot push. " << x << endl;
            exit(1);
        }
    }
    // Push element x onto the second stack
    void pushStack2(int x)
    {
        if (top1 < top2 - 1)
        {
            arr[--top2] = x;
        }
        else
        {
            cout << "Stack Overflow. Cannot push. " << x << endl;
            exit(1);
        }
    }
    // Pop the top element from the first stack
    int popStack1()
    {
        if (!isEmptyStack1())
            return arr[top1--];
        else
        {
            cout << "Stack Underflow." << endl;
            exit(1);
        }
    }
    // Pop the top element from the second stack
    int popStack2()
    {
        if (!isEmptyStack2())
            return arr[top2++];
        else
        {
            cout << "Stack Underflow." << endl;
            exit(1);
        }
    }
    //  Check if the first stack is empty
    bool isEmptyStack1()
    {
        return top1 == -1;
    }
    // Check if the second stack is empty
    bool isEmptyStack2()
    {
        return top2 == capacity;
    }
};

int main()
{
    TwoStacks myStacks(6);
    // Pushing elements onto Stack 1
    myStacks.pushStack1(5);
    myStacks.pushStack1(10);

    //  Pushing elements onto Stack 2
    myStacks.pushStack2(20);
    myStacks.pushStack2(25);
    // Popping elements from both stacks
    int popped1 = myStacks.popStack1();         // Should be 10
    int popped2 = myStacks.popStack2();         // Should be 25
    // Pushing more elements onto Stack 2
    myStacks.pushStack2(30);
    // Popping more elements from both stacks
    int popped3 = myStacks.popStack1();         // Should be 5
    int popped4 = myStacks.popStack2();         // Should be 30
    // Checking if stacks are empty
    bool isEmpty1 = myStacks.isEmptyStack1();   // Should be true
    bool isEmpty2 = myStacks.isEmptyStack2();   // Should be false

    cout << popped1 << " " << popped2 << " " << popped3 << " " << popped4 << endl;
    cout << isEmpty1 << " " << isEmpty2 << endl;

    return 0;
}