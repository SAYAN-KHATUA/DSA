#include <stdio.h>
#define MAX 200
int arr[MAX];

void Delete_double_item(int *n)
{
    int i, j, k;
    for (i = 0; i < *n; i++)
    {
        for (j = i + 1; j < *n; j++)
        {
            if (arr[i] == arr[j])
            {
                // Shift all elements to the left
                for (k = j; k < *n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                (*n)--; // Reduce the size of the array
                j--;    // Since we have shifted the elements, stay on the same index
            }
        }
    }
}

void Display_Array(int n)
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
    do
    {
        printf("Enter the number of array elements you want to enter (Max %d): ", MAX);
        scanf("%d", &n);

        if (n > MAX || n <= 0)
        {
            printf("\nInvalid number of elements. Please enter a value between 1 and %d.\n", MAX);
        }
    } while (n > MAX || n <= 0);

    printf("\nEnter the array elements....\n");
    for (i = 0; i < n; i++)
    {
        printf("arr[%d] -> ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array is : \n");
    Display_Array(n);

    printf("\nAfter deleting the duplicate items, the list is : \n");
    Delete_double_item(&n);
    Display_Array(n);

    return 0;
}
