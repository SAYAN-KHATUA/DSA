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

void Insert_item_At_Last(struct Node *head)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation failed!");
        Display_Linked_List(head);
    }
    printf("\nEnter the element that you want to insert at last of the list : ");
    scanf("%d", &node->data);
    node->next = NULL;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    printf("\nAfter insert the element at the last the update list is : \n");
    Display_Linked_List(head);
}

int main()
{
    struct Node *node = NULL, *head = NULL, *temp;
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
    Insert_item_At_Last(head);
    return 0;
}