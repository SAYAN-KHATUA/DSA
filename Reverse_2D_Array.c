#include <stdio.h>
#define MAX 200
int arr[MAX][MAX];
void Reverse_Array(int row, int col)
{
    int i, j, temp;
    for (i = 0; i < row / 2; i++)
    {
        for (j = 0; j < col; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[row - i - 1][col - j - 1];
            arr[row - i - 1][col - j - 1] = temp;
        }
    }
}

void Display_Array(int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int row, col, i, j;
    printf("Enter the size of row : ");
    scanf("%d", &row);
    printf("Enter the size of col : ");
    scanf("%d", &col);
    printf("\nEnter the array elements....\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("arr[%d][%d] -> ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nThe array is : \n");
    Display_Array(row, col);
    printf("\nAfter reverse the array is : \n");
    Reverse_Array(row, col);
    printf("\nThe array is : \n");
    Display_Array(row, col);
    return 0;
}