#include <stdio.h>
void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int a[] = {5, 3, 9, 1, 7};
    print(a, 5);
    printf("\n");

    // sorting
    for (int i = 0; i < 5; i++)
    {
        int c = i;
        for (int j = i + 1; j > 0; j--, c--)
        {
            if (a[c] > a[j])
            {
                int temp = a[c];
                a[c] = a[j];
                a[j] = temp;
            }
            print(a, 5);
        }
        printf("\n");
    }

    printf("\nSorted array in ascending order:\n");
    // final print
    print(a, 5);

    return 0;
}