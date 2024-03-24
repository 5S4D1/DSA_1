#include <stdio.h>
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			printf("\n ");
			printArray(arr, n);
			
		}printf("\n ");
	}
}

int main()
{
	int arr[] = {64, 34, 25, 12, 22, 90, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, n);
	bubbleSort(arr, n);
	printf("\nSorted array: \n");
	printArray(arr, n);
	return 0;
}