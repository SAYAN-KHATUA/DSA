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

void Insert_Item_At_First(struct Node *head)
{
    struct Node *New_node = (struct Node *)malloc(sizeof(struct Node));
    if (New_node == NULL)
    {
        printf("Memory allocation failed!");
        Display_Linked_List(head);
    }
    printf("\nEnter the element that you want to insert at the first position in the list: ");
    scanf("%d", &New_node->data);
    New_node->next = head;
    head = New_node;
    printf("\nAfter insert the updated list is : \n");
    Display_Linked_List(head);
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
    Insert_Item_At_First(head);
    return 0;
}