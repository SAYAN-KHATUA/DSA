#include <stdio.h>
#define MAX 200
int arr[MAX];

void swap(int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int Partition(int lower_bound, int upper_bound)
{
    int pivot = arr[lower_bound];
    int start = lower_bound;
    int end = upper_bound;
    while (start < end)
    {
        while (start <= upper_bound && arr[start] <= pivot)
        {
            start++;
        }
        while (end >= lower_bound && arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(start, end);
        }
    }
    swap(lower_bound, end);
    return end;
}

void quick_sort(int start, int end)
{
    if (start < end)
    {
        int pivot_loc = Partition(start, end);
        quick_sort(start, pivot_loc - 1);
        quick_sort(pivot_loc + 1, end);
    }
}

void print(int n)
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
    print(n);
    printf("\n");

    printf("\nAfter sorting, the array is : \n");
    quick_sort(0, n - 1);
    print(n);
    printf("\n");
    return 0;
}