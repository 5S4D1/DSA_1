#include <bits/stdc++.h>
using namespace std;
// chack Palindrome or not
bool isPalindrome(string str)
{
    queue<char> c;
    int i = 0;
    int j = str.length() / 2;

    while (i < j)
    {
        c.push(str[i]);
        i++;
    }
    i = str.length() - 1;
    while (i > j)
    {
        if (c.front() != str[i])
        {
            return false;
        }
        c.pop();
        i--;
    }
    return true;
}
// chack Valid Expression
bool isValidExpression(string a)
{
    bool hasOperator = false;
    bool hasDigits = false;
    int countOperator = 0, countDigits = 0;
    string p;
    stack<char> s;
    int i = 0;
    while (i < a.length())
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
        {
            s.push(a[i]);
        }
        else if (a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            char b = s.top();
            if ((a[i] == ')' && b == '(') || (a[i] == '}' && b == '{' || (a[i] == ']' && b == '[')))
                s.pop();
            else
                return false;
        }
        else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            bool hasOperator = true;
            if (a[i + 1] == ')' || a[i + 1] == '}' || a[i + 1] == ']')
            {
                return false;
            }
        }
        else
        {
            hasDigits = true;
            p += a[i];
        }
        i++;
    }

    if (s.empty() && isPalindrome(p) && hasDigits)
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    if (isValidExpression(s))
        cout << "Valid Expression.";
    else
        cout << "Invalid Expression!";

    return 0;
}