#include <stdio.h>
#define MAX 200
int arr[MAX];

void Insertion_sort(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
        }
    }
}

void Print_array(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
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
    printf("\nEnter the array elements...\n");

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] -> ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array is : \n");

    Print_array(n);

    printf("\n\nAfter sorting the array is : \n");

    Insertion_sort(n);

    Print_array(n);

    printf("\n");

    return 0;
}