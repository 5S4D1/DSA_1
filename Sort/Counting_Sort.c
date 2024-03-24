#include <stdio.h>
int print(int a[], int len)
{
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {2, 1, 1, 0, 2, 5};
    int n = sizeof(arr) / sizeof(int);
    int fiarr[n];
    int i, j, high = 0;
    print(arr, n);

    for (i = 0; i < n; i++)
    {
        if (high < arr[i])
            high = arr[i];
    }
    printf("high: %d\n", high);
    int count[high];
    
    for (int i = 0; i <= high; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i <= high; i++)
    {
        count[arr[i]]++;
    }
    printf("count array:");
    print(count, n);
    
    // update count array
    for (int i = 1; i <= high; i++)
    {
        count[i] += count[i - 1];
    }
    printf("updated count array:");
    print(count, n);
    int temp, d;

    for (i = n - 1; i >= 0; i--)
    {
        temp = arr[i];
        d = --count[temp];
        fiarr[d] = temp;

    }
    printf("Final Sort is:");
    print(fiarr,n);

    return 0;
}