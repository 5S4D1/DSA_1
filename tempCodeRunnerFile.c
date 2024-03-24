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
    // print array
    print(a, len);

    // sorting
    for (int i = 1; i < len; i++)
    {
        // min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[min_index] > a[j])
            {
                // min_index = j;
                int temp = a[i];
                a[i] = a[min_index];
                a[min_index] = temp;
            }
        }
    }

    // print final array
    print(a, len);

    return 0;
}