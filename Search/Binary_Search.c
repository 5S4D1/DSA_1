#include <stdio.h>
void Selection(int arr1[], int n)
{
    int min_index;
    for (int i = 0; i < n; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr1[min_index] > arr1[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            int temp = arr1[i];
            arr1[i] = arr1[min_index];
            arr1[min_index] = temp;
        }
    }
}
// Binary Searching
int Binary(int arr1[], int n, int key1)
{
    int low = 0, high = n, mid;
    while (low <= high)
    {
        mid = (low + high) / 2; // mid = low + (high - low) **perfect**
        if (arr1[mid] == key1)
        {
            return mid;
        }
        else if (arr1[mid] < key1)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
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
    int arr[] = {1, 3, 0, 4, 10, 9, 6, 8, 12};
    int size = sizeof(arr) / sizeof(int);
    int key = 1;
    print(arr, size);

    Selection(arr, size);
    printf("Selection sort is :\n");
    print(arr, size);

    int search_in_Bin = Binary(arr, size, key);
    printf("Search element using Binary is : %d\n", key);
    if (search_in_Bin == -1)
    {
        printf("Not found!\n");
    }
    else
        printf("Binary search index : %d\n", search_in_Bin);

    return 0;
}
