#include <stdio.h>
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int compair(int arr[], int n)
{
    int marra[n][n], count, tcount = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            marra[i][j] = 0;
        }
    }
    int m = 0, l;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            else
            {
                i += count - 1;
                break;
            }
        }
        tcount += count;

        l = 0;
        marra[m][l] = count;
        l++;
        marra[m][l] = arr[i];
        m++;

        if (tcount > n)
            break;
    }
    printf("\n");
    int f[m];
    int ff = 0;

    int store;
    for (int i = 0; i < m; i++)
    {
        store = i;
        for (int j = i + 1; j < m; j++)
        {
            if (marra[store][0] < marra[j][0])
            {
                store = j;
            }
        }
        int temp1 = marra[i][0];
        int temp2 = marra[i][1];
        marra[i][0] = marra[store][0];
        marra[i][1] = marra[store][1];
        marra[store][0] = temp1;
        marra[store][1] = temp2;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < marra[i][0]; j++)
        {
            printf("%d ", marra[i][1]);
        }
    }
    return 0;
}

int main()
{
    int a[] = {2, 5, 2, 8, 5, 6, 8, 8};
    int size = sizeof(a) / sizeof(int);
    print(a, size);
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[index] > a[j])
                index = j;
        }
        if (index != i)
        {
            int temp = a[index];
            a[index] = a[i];
            a[i] = temp;
        }
    }
    print(a, size);
    compair(a, size);

    return 0;
}
