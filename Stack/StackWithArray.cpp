#include <bits/stdc++.h>
using namespace std;

int arr[5], i = 0;

//  push Function
void push(int x)
{
    if (i < 5)
    {
        arr[i] = x;
        i++;
    }
    else
    {
        cout << "Stack Overflow" << endl;
    }
}

//  pop Function
void pop()
{
    if (i > 0)
    {
        i--;
    }
    else
    {
        cout << "Stack Underflow" << endl;
    }
}

//  top Function
int top()
{
    return arr[i - 1];
}

//  empty Function
bool empty()
{
    if (i == 0)
    {
        return 1;
    }
    return 0;
}

//  Print Stack
void print(){
    while(!empty()){
        cout<<top()<<" ";
        pop();
    }
    cout<<endl;
}

// Main Function
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);

    cout << top() << endl;
    pop();
    print();
    
    // cout << top() << endl;
    // pop();
    // cout << top() << endl;
    return 0;
}