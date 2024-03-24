#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> number;

    cout << "Size:: " << number.size() << endl;
    if (number.empty())
    {
        cout << "Stack is empty." << endl;
    }

    number.push(4);
    number.push(6);
    cout << "Size:: " << number.size() << endl;

    cout << "Top: " << number.top() << endl;
    number.push(2);
    cout << "Top: " << number.top() << endl;
    number.pop();
    cout << "Pop value: " << number.top() << endl;
    cout << "Top: " << number.top() << endl;


    stack<int> num;
    num.push(1);

    num.swap(number);
    cout << "Size:: num->" << num.size() << endl;
    cout << "Size:: number->" << number.size() << endl;


    return 0;
}