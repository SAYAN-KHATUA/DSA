#include <stdio.h>
#define MAX 200
int arr[200];

void Selection_sort(int n)
{
    int temp, i, j, small_value_loc;
    // int size = sizeof(arr[n])/sizeof(arr[0]);("to calculate the size of a array.")
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
}

void Print_array(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n, i;
    printf("Enter the number of array elements you want to enter (Max %d): ", MAX);

    scanf("%d", &n);

    while (1)
    {
        if (n > MAX || n <= 0)
        {
            printf("\nInvalid number of elements. Please enter a value between 1 and %d.\n", MAX);
            printf("nter the number of array elements you want to enter (Max %d): ", MAX);
            scanf("%d", &n);
        }
        if (n < MAX || n >= 0)
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
    printf("\nThe array is  : \n");

    Print_array(n);

    printf("\nAfter sorting the array is  : \n");

    Selection_sort(n);

    Print_array(n);
    printf("\n");
    return 0;
}