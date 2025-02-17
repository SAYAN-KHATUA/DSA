#include <stdio.h>
#define MAX 200
int arr[MAX];

void print_array(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void Bubble_sort(int n)
{
    int temp, i, j, swap;

    for (i = 0; i < n - 1; i++)
    {
        swap = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        if (!swap)
        {
            break;
        }
    }
    printf("\nAfter sorting, the array is : \n");
    print_array(n);
    printf("\n");
}

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
    printf("\nAfter sorting, the array is : \n");
    print_array(n);
    printf("\n");
}

void Selection_sort(int n)
{
    int temp, i, j, small_value_loc;

    for (i = 0; i < n - 1; i++)
    {
        small_value_loc = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[small_value_loc])
            {
                small_value_loc = j;
            }
        }

        temp = arr[small_value_loc];
        arr[small_value_loc] = arr[i];
        arr[i] = temp;
    }
    printf("\nAfter sorting, the array is : \n");
    print_array(n);
    printf("\n");
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

    printf("\nmjThe array is : \n");
    print_array(n);
    printf("\n");

    while (1)
    {
        printf("\n\nWhich sort you want to do this array.\nb - Bubble sort\ni - insertion sort\ns - selection sort\ne - exit\nChoose = ");
        char choose;
        scanf(" %c", &choose); 
        switch (choose)
        {
        case 'b':
            Bubble_sort(n);
            break;
        case 'i':
            Insertion_sort(n);
            break;
        case 's':
            Selection_sort(n);
            break;
        case 'e':
            return 0;
        default:
            printf("Please enter a valid character!\n");
        }
    }

    return 0;
}
