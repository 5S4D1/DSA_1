/*
Question 1 (10 Marks) - Merge Sort

You are tasked with implementing the Merge Sort algorithm. Write a program that takes
an unsorted list of integers as input and returns two lists: one sorted in ascending order
and the other sorted in descending order using the Merge Sort algorithm.
Requirements:
    ● Your program should implement the Merge Sort algorithm from scratch.
    ● Test your implementation on various input lists to ensure correctness.

*/

#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int p, int q, int r, char x)
{
    // Create Left ← A[p..q] and Right ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int Left[n1], Right[n2];

    int i, j, k;
    for (i = 0; i < n1; i++)
        Left[i] = arr[p + i];

    for (j = 0; j < n2; j++)
        Right[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either Left or Right, pick larger among
    // elements Left and Right and place them in the correct position at A[p..r]
    if (x == 'a')
    {
        while (i < n1 && j < n2)
        {
            if (Left[i] <= Right[j])
            {
                arr[k] = Left[i];
                i++;
            }
            else
            {
                arr[k] = Right[j];
                j++;
            }
            k++;
        }
    }
    else
    {
        while (i < n1 && j < n2)
        {
            if (Left[i] >= Right[j])
            {
                arr[k] = Left[i];
                i++;
            }
            else
            {
                arr[k] = Right[j];
                j++;
            }
            k++;
        }
    }

    while (i < n1)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r, char x)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, x);
        mergeSort(arr, m + 1, r, x);

        // Merge the sorted subarrays
        merge(arr, l, m, r, x);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int array[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nGiven array is : ");
    printArray(array, size);

    mergeSort(array, 0, size - 1, 'a');
    printf("\nAscending Order Sorted array is: ");
    printArray(array, size);

    mergeSort(array, 0, size - 1, 'd');
    printf("\nAscending Order Sorted array is: ");
    printArray(array, size);

    return 0;
}