// Binary search with dsa.
#include <stdio.h>
#define MAX 200
int SearchingElement(int arr[], int start, int end, int element)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == element)
        {
            return mid;
        }
        if (element > arr[mid])
        {
            return SearchingElement(arr, mid + 1, end, element);
        }
        if (element < arr[mid]) // ar bodole else o use kora jabe
        {
           return SearchingElement(arr, start, mid + 1, element);
        }
    }
    return -1;
}
int main()
{
    int arr[MAX], n, item, i, j, small_value_loc, temp;

    printf("Enter the number of array elements you want to enter (Max %d): ", MAX);

    scanf("%d", &n);

    while (1)
    {
        if (n > MAX || n <= 0)
        {
            printf("\nInvalid number of elements. Please enter a value between 1 and %d.\n", MAX);
            printf("Enter the number of array elements you want to enter (Max %d): ", MAX);
            scanf("%d", &n);
        }
        else
        {
            break;
        }
    }

    printf("\nEnter the array elements....\n");

    for (i = 0; i < n; i++)
    {
        printf("arr[%d] -> ", i);

        scanf("%d", &arr[i]);
    }
    // Selection sort.
    for (i = 0; i < n - 1; i++) // One by one move boundary of unsorted subarray.
    {
        small_value_loc = i; // minimum element in unsorted array.

        for (j = i + 1; j < n; j++)

            if (arr[j] < arr[small_value_loc])
            {
                small_value_loc = j;
            }
        // Swap the minimum element with the first element.
        temp = arr[small_value_loc];

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

    int index = SearchingElement(arr, 0, n - 1, item);

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