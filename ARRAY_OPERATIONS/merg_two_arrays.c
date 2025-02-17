#include <stdio.h>
#define MAX 200

void sorting(int arr[], int n)
{
    int i, j, small_loc, temp;
    for (i = 0; i < n - 1; i++)
    {
        small_loc = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[small_loc])
            {
                small_loc = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[small_loc];
        arr[small_loc] = arr[i];
        arr[i] = temp;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int size1, size2, i, k = 0, size3;
    int arr1[MAX], arr2[MAX], arr3[MAX];

    printf("Enter the first array size: ");
    scanf("%d", &size1);

    printf("Enter the second array size: ");
    scanf("%d", &size2);

    // Input first array elements
    printf("\nEnter the first array elements...\n");
    for (i = 0; i < size1; i++)
    {
        printf("arr1[%d] -> ", i);
        scanf("%d", &arr1[i]);
    }

    // Input second array elements
    printf("\nEnter the second array elements...\n");
    for (i = 0; i < size2; i++)
    {
        printf("arr2[%d] -> ", i);
        scanf("%d", &arr2[i]);
    }

    // Display the first array
    printf("\nThe first array is: ");
    display(arr1, size1);

    // Display the second array
    printf("\nThe second array is: ");
    display(arr2, size2);

    // Merging the two arrays
    size3 = size1 + size2;
    for (i = 0; i < size3; i++)
    {
        if (i < size1)
        {
            arr3[i] = arr1[i];
        }
        else
        {
            arr3[i] = arr2[k++];
        }
    }

    // Display merged array
    printf("\n\nAfter merging, the array is: ");
    display(arr3, size3);

    // Sort and display the sorted merged array
    printf("\n\nAfter sorting the merged array: ");
    sorting(arr3, size3);
    display(arr3, size3);

    return 0;
}
