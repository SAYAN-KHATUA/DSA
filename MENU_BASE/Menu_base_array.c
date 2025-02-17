#include <stdio.h>
#define MAX 200
int arr[MAX];

void Insert_Any_Position(int *n)
{
    int pos, i, item;
    printf("Enter the position where you insert the element : ");
    scanf("%d", &pos);

    if (pos < 0 || pos > *n)
    {
        printf("You entered an invalid position.\n");
    }
    else
    {
        printf("Enter the element that you want to insert : ");
        scanf("%d", &item);

        for (i = *n; i > pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[pos] = item;
        (*n)++;
    }
}

void Insert_At_First(int *n)
{
    int i, item;
    printf("Enter the element that you want to insert : ");
    scanf("%d", &item);

    for (i = *n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    printf("Eelement is insert at the first position.\n");
    arr[0] = item;
    (*n)++;
}

void Insert_At_Last(int *n)
{
    int i, item;
    printf("Enter the element that you want to insert : ");
    scanf("%d", &item);
    printf("Eelement is insert at the last position.\n");
    arr[*n] = item;
    (*n)++;
}

void Delete_Any_Position(int *n)
{
    int item, pos, i;
    printf("\nEnter the position to delete an item: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > *n-1)
    {
        printf("\nYou entered an invalid position.");
    }
    else
    {
        for (i = pos; i < *n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    }
}

void Delete_At_First(int *n)
{
    int item, i;
    for (i = 0; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("Element is deleted at the first postion.\n");
    (*n)--;
}

void Delete_At_Last(int *n)
{
    printf("Eelement is deleted at the last position.\n");
    (*n)--;
}

void Display_Array(int n)
{
    if (n == 0)
    {
        printf("The list is emepty.");
    }
    else
    {
        printf("\nThe array is : ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
    printf("\n");
    }
}

int main()
{
    int size, i, val, check;
    printf("Enter the array size : ");
    scanf("%d", &size);
    printf("\nEnter the array elements...\n");
    for (i = 0; i < size; i++)
    {
        printf("arr[%d] -> ", i);
        scanf("%d", &arr[i]);
    }
    Display_Array(size);
    printf("\n");
    while (1)
    {
        printf("\nWhich operation you want to do with the list..\n"
               "1. Insert item at any position\n"
               "2. Insert item at first position\n"
               "3. Insert item at last position\n"
               "4. Delete item at any position\n"
               "5. Delete item at first position\n"
               "6. Delete item at last position\n"
               "7. Display the list\n"
               "8. Exit\n\nPress: ");
        scanf("%d", &val);
        printf("\n");
        switch (val)
        {
        case 1:
            while (1)
            {
                Insert_Any_Position(&size);
                printf("\nDo you want to continue insertion:\n1->yes\n0->No\nPress : ");
                scanf("%d", &check);
                printf("\n");
                if (check == 0)
                {
                    break;
                }
            }
            break;
        case 2:
            while (1)
            {
                Insert_At_First(&size);
                printf("\nDo you want to continue insertion at first :\n1->yes\n0->No\nPress : ");
                scanf("%d", &check);
                printf("\n");
                if (check == 0)
                {
                    break;
                }
            }
            break;
        case 3:
            while (1)
            {
                Insert_At_Last(&size);
                printf("\nDo you want to continue insertion at last :\n1->yes\n0->No\nPress : ");
                scanf("%d", &check);
                printf("\n");
                if (check == 0)
                {
                    break;
                }
            }
            break;
        case 4:
            while (1)
            {
                Delete_Any_Position(&size);
                printf("\nDo you want to continue deletion :\n1->yes\n0->No\nPress : ");
                scanf("%d", &check);
                printf("\n");
                if (check == 0)
                {
                    break;
                }
            }
            break;
        case 5:
            while (1)
            {
                Delete_At_First(&size);
                printf("\nDo you want to continue deletion at first :\n1->yes\n0->No\nPress : ");
                scanf("%d", &check);
                printf("\n");
                if (check == 0)
                {
                    break;
                }
            }
            break;
        case 6:
            while (1)
            {
                Delete_At_Last(&size);
                printf("\nDo you want to continue deletion at last :\n1->yes\n0->No\nPress : ");
                scanf("%d", &check);
                printf("\n");
                if (check == 0)
                {
                    break;
                }
            }
            break;
        case 7:
            Display_Array(size);
            printf("\n");
            break;
        case 8:
            return 0;
        default: printf("You enter a invalid number!");
        }
    }

    return 0;
}