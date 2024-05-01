/*
    C++ program for implementation of Heap Sort.
    The time complexity of heapify will be O(log n)
    Time Complexity of Build Heap: O(n)
    Thus the total time taken by HeapSort()
        = O(n) + (n - 1) O(log n)
        = O(n) + O(n log n)
        = O(n log n)
    Time Complexity : O(n log n)
    Auxiliary Space: O(1)
    Height of the heap is: log n
    Heap Sort is a comparison based sorting technique based on Binary Heap data structure.
    -> Heap Sort Algorithm for sorting in increasing order:
    1. Build a max heap from the input data.
    2. At this point, the largest item is stored at the root of the heap.
       Replace it with the last item of the heap followed by reducing the size of heap by 1.
       Finally, heapify the root of the tree.
*/
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int large = i;         //  initialize large as root
    int left = 2 * i + 1;  //  left = 2*i + 1
    int right = 2 * i + 2; //  right = 2*i + 2

    //  if left child is larger than root
    if (left < n && arr[left] > arr[large])
        large = left;

    //  if right child is larger than largest so far
    if (right < n && arr[right] > arr[large])
        large = right;

    //  if largest is not root
    if (large != i)
    {
        swap(arr[i], arr[large]);
        heapify(arr, n, large); //  recursively heapify the affected sub-tree
    }
}

void HeapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // call max heapify on the reduced heap
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1, 6, 14, 10, 8, 7, 9, 3, 2, 4, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is: \n";
    printArray(arr, n);
    HeapSort(arr, n);

    cout << "Sorted heap array is: \n";
    printArray(arr, n);

    return 0;
}