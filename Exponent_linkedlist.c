#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;
    int expo;
    struct Node *next;
};

void Display_Linked_List(struct Node *temp)
{
    printf("First polynomial is : ");
    while (temp != NULL)
    {
        printf("[%dX^%d] + ", temp->coef, temp->expo);
        temp = temp->next;
    }
    // printf("Null!\n");
}

int main()
{
    struct Node *head = NULL, *node = NULL, *temp;
    int val;
    do
    {
        printf("\nif you need to store data then press 1.\nif you did not need storage then press 0. \nPress : ");
        scanf("%d", &val);
        if (val == 1)
        {
            node = (struct Node *)malloc(sizeof(struct Node));

            if (node == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }
            printf("\nCoef : ");
            scanf("%d", &node->coef);
            printf("Exponent in decreasing order : ");
            scanf("%d", &node->expo);
            node->next = NULL;
            if (head == NULL)
            {
                head = node;
            }
            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = node;
            }
        }
    } while (val);
    if (head == NULL)
    {
        printf("There is no memory allocate.");
        return 1;
    }
    printf("\nThe list is : \n");
    Display_Linked_List(head);
    return 0;
}
