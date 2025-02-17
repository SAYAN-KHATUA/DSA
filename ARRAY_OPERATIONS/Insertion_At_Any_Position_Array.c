#include <stdio.h>

int main()
{
    int n, arr[50], i, pos, item;

    printf("Enter the array size : ");

    scanf("%d", &n);

    printf("Enter the array elements : \n");

    for (i = 0; i < n; i++)
    {
        printf("arr[%d] -> ", i);

        scanf("%d", &arr[i]);
    }
    printf("Enter the position where you insert the position : ");
    
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        printf("You enter a invalid position.");
    }
    else
    {
        printf("Enter the element that you want to insert : ");

        scanf("%d", &item);

        for (i = n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[pos] = item;
        
        printf("After insert the element the array is : ");

        for (i = 0; i <= n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}