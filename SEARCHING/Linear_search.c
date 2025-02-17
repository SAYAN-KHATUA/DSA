#include <stdio.h>
#define MAX 200
int arr[MAX];

void Linear_search(int n, int item)
{
    for (int i = 0; i < n; i++)
    {
        if (item == arr[i])
        {
            printf("The item is found.\nThe location is : %d", i);

            return;
        }
    }
    printf("The item is not found.");
}

void Display_Array(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n, i, item;

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
    printf("\nThe array is...\n");

    Display_Array(n);

    printf("\n\nEnter the that you want to find : ");

    scanf("%d", &item);

    Linear_search(n, item);
    return 0;
}