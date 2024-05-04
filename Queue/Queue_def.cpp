#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(5);
    q.push(6);
    q.push(4);
    q.push(3);
    q.push(4);
    cout << "Size of stack: " << q.size() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << "Size of stack: " << q.size() << endl;
    cout << "isEmpty: " << q.empty() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    return 0;
}