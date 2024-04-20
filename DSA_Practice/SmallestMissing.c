#include <stdio.h>

int findSmallestMissing(int nums[], int size)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        if (nums[left] != left)
            return left;

        int mid = left + (right - left) / 2;
        if (nums[mid] != mid)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int main()
{
    int nums[] = {0, 1, 2, 6, 9, 11, 15};

    // int nums[]={1,2,3,4,6,9,11,15};

    // int nums[]={0,1,2,3,4,5,6};

    int size = sizeof(nums) / sizeof(nums[0]);

    int smallestMissing = findSmallestMissing(nums, size);
    printf("The smallest missing element is : %d\n", smallestMissing);

    return 0;
}
