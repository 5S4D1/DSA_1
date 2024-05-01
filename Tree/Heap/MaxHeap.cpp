/* 
    C++ program for implementation of Max Heap.
    Time Complexity of heapify: O(log n)
    Time Complexity of Build Heap: O(n)
    Time Complexity of Heap Sort: O(n log n)
    Auxiliary Space: O(1)
*/
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int large = i;          //  initialize large as root
    int left = 2 * i + 1;   //  left = 2*i + 1
    int right = 2 * i + 2;  //  right = 2*i + 2

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
        heapify(arr, n, large);     //  recursively heapify the affected sub-tree
    }
}

void HeapSort(int arr[], int n)
{
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {1,6, 14,10, 8, 7, 9,3,2,4,16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given array is: \n";
    printArray(arr, n);
    HeapSort(arr, n);

    cout << "Max heap array is: \n";
    printArray(arr, n);

    return 0;
}