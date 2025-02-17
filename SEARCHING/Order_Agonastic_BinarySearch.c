// Binary search with dsa.
#include <stdio.h>
#include <stdbool.h>
#define MAX 200
int arr[MAX];
int SearchingElement(int start, int end, int target)
{
    bool isAsc = arr[start] < arr[end]; // Determine if the array is ascending

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid; // Target found
        }

        if (isAsc)
        {
            if (target < arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        { // Descending part of the array
            if (target > arr[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    return -1;
}
void Sort_Arry(int end, int n)
{
    int i, j, small_value_loc, temp;
    if (n)
    {
        for (i = 0; i < end - 1; i++) // One by one move boundary of unsorted subarray.
        {
            small_value_loc = i; // minimum element in unsorted array.

            for (j = i + 1; j < end; j++)

                if (arr[j] < arr[small_value_loc])
                {
                    small_value_loc = j;
                }
            // Swap the minimum element with the first element.
            temp = arr[small_value_loc];

            arr[small_value_loc] = arr[i];

            arr[i] = temp;
        }
    }
    else
    {
        for (i = 0; i < end - 1; i++) // One by one move boundary of unsorted subarray.
        {
            small_value_loc = i; // minimum element in unsorted array.

            for (j = i + 1; j < end; j++)

                if (arr[j] > arr[small_value_loc])
                {
                    small_value_loc = j;
                }
            // Swap the maximum element with the first element.
            temp = arr[small_value_loc];

            arr[small_value_loc] = arr[i];

            arr[i] = temp;
        }
    }
}
int main()
{
    int size, item, i, j;

    char choose;

    printf("Enter the number of array elements you want to enter (Max %d): ", MAX);

    scanf("%d", &size);

    while (1)
    {
        if (size > MAX || size <= 0)
        {
            printf("\nInvalid number of elements. Please enter a value between 1 and %d.\n", MAX);
            printf("Enter the number of array elements you want to enter (Max %d): ", MAX);
            scanf("%d", &size);
        }
        else
        {
            break;
        }
    }

    printf("\nEnter the array elements....\n");

    for (i = 0; i < size; i++)
    {
        printf("arr[%d] -> ", i);

        scanf("%d", &arr[i]);
    }

    printf("\nIf you want to sort the array in ascending orde then press -> a\n"
           "If you want to sort the array in descending orde then press -> d\nPress : ");
    scanf(" %c", &choose);
    switch (choose)
    {
    case 'a':
        Sort_Arry(size, 1);
        break;
    case 'd':
        Sort_Arry(size, 0);
        break;
    default:
        printf("\nEnter invalid option!");
        return 1;
    }
    printf("\nAfter sorting the array is...\n");

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\nEnter the searching element : ");

    scanf("%d", &item);

    int index = SearchingElement(0, size - 1, item);

    if (index != -1)
    {
        printf("The searching element %d is found at index -> %d\n\n",item, index);
    }
    else
    {
        printf("The item is not available in this array.\n\n");
    }

    return 0;
}