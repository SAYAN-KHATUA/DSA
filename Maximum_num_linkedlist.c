#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Display_Linked_List(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null!\n");
}

int main()
{
    struct Node *node = NULL, *head = NULL, *temp;
    int val, max;
    do
    {
        printf("\nif you need to store data then press 1.\nif you did not need storage then press 0. \nPress : ");
        scanf("%d", &val);
        if (val == 1)

        {
            node = (struct Node *)malloc(sizeof(struct Node));
            if (node == NULL)
            {
                printf("Memory allocation failed!");
                return 1;
            }
            printf("\ndata : ");
            scanf("%d", &node->data);
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
    max = head->data;
    temp = head->next;
    while (temp != NULL)
    {
        if (temp->data > max)
        {
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("\nThe maximum value is : %d", max);
    return 0;
}