#include <stdio.h>
int main()
{
    int a[] = {5, 3, 1, 2, 6, 9};
    int key = 8;
    int temp = -1;
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            temp = i;
            break;
        }
    }

    if (temp == -1)
        printf("Not found.\n");
    else
        printf("%d", temp);

    return 0;
}