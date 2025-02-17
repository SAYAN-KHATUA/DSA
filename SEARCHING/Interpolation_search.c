// Interpolation Search with dsa.
#include <stdio.h>
#define MAX 200
int SearchingElement(int arr[], int size, int num)
{
    int start = 0, end = size, mid;
    while (start <= end)
    {
        mid = start + (end - start) * ((num - arr[start]) / (arr[end] - arr[start]));
        if (num == arr[mid])
        {
            return mid + 1;
        }
        if (num < arr[mid])
        {
            end = mid - 1;
        }
        if (num > arr[mid])
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[MAX], n, item, i, j, small_value_loc;

    printf("Enter the number of elements that you want to enter : ");

    scanf("%d", &n);

    printf("\nEnter the array elements....\n");

    for (i = 0; i < n; i++)
    {
        printf("arr[%d] -> ", i);

        scanf("%d", &arr[i]);
    }
    // Selection sort.
    for (i = 0; i < n - 1; i++) // One by one move boundary of unsorted subarray
    {
        small_value_loc = i; // minimum element in unsorted array

        for (j = i + 1; j < n; j++)

            if (arr[j] < arr[small_value_loc])

                small_value_loc = j;

        // Swap the minimum element with the first element
        int temp = arr[small_value_loc];

        arr[small_value_loc] = arr[i];

        arr[i] = temp;
    }
    printf("\nAfter sorting the array is...\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\nEnter the searching element : ");

    scanf("%d", &item);

    int index = SearchingElement(arr, n, item);

    if (index != -1)
    {
        printf("The searching element is found at index -> %d\n\n", index);
    }
    else
    {
        printf("The item is not available in this array.\n\n");
    }

    return 0;
}