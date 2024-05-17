/*
    Recursive Algorithm for "TOWER OF HANOI"

    S = Source
    D = Destination
    A = Auxiliary
    n = Number of disks
    ------------------------------------------------------------
        |               |                 |
        |               |                 |
        |               |                 |
     -------         -------           -------
     Source         Auxiliary        Destination
*/

#include <iostream>
using namespace std;

void TOH(int n, char S, char A, char D)
{
    if (n > 0)
    {
        TOH(n - 1, S, D, A);
        cout << "Move top Disc from:  " << S << "  to  " << D << endl;
        TOH(n - 1, A, S, D);
    }
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    TOH(n, 'S', 'A', 'D');

    return 0;
}