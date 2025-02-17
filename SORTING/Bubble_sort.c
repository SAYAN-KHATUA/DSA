#include <stdio.h>
#include <stdbool.h>
#define MAX 200
int arr[200];

void swap(int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

void Bubble_sort(int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(j, j + 1);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
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

    while (n > MAX || n <= 0)
    {
        printf("\nInvalid number of elements. Please enter a value between 1 and %d.\n", MAX);
        printf("Enter the number of array elements you want to enter (Max %d): ", MAX);
        scanf("%d", &n);
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

    Bubble_sort(n);

    Print_array(n);
    printf("\n");
    return 0;
}