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
    struct Node *head = NULL, *node = NULL, *temp;
    int val, element;
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
            printf("\nData : ");
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
    printf("\nEnter the searching element : ");
    scanf("%d", &element);
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            printf("The searching element is found in the list.");
            return 1;
        }
        temp = temp->next;
    }
    printf("\nThe searching element is not found in the last.\n");
    return 0;
}