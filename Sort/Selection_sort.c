#include <stdio.h>
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 3, 0, 4, 10, 9, 6, 8, 12};
    int len = sizeof(a) / sizeof(int);
    int min_index;
    print(a, len);

    // sorting
    for (int i = 0; i < len; i++)
    {
        min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
        }
        if (min_index != i) // if don't use it. it will be work properly.
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }

    print(a, len);

    return 0;
}