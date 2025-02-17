#include <stdio.h>

int main()
{
    int arr[50], n, i, pos;

    printf("Enter the array size : ");
    
    scanf("%d", &n);

    printf("Enter the array elements : \n");

    for (i = 0; i < n; i++)
    {
        printf("arr[%d] -> ", i);

        scanf("%d", &arr[i]);
    }
    printf("Enter the position of the item that you want delete = ");

    scanf("%d", &pos);

    if (pos < 0 || pos > n - 1)
    {
        printf("You enter a invalid position.");
    }
    else
    {
        for (i = pos; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        printf("After deleting the element the array is : ");
        
        for (i = 0; i < n - 1; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}