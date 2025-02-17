#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Display_Linked_List(Node *temp)
{
    if (temp == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null!\n");
}

void Delete_Item_At_First(Node *head)
{
    Node *tail,*temp = head;
    while (temp->next != NULL)
    {
        tail = temp;
        temp = temp->next;
    }
    tail->next = NULL;
    printf("\nAfter deleting the lirst item of the list\n\nThe new list is :\n");
    Display_Linked_List(head);
}

int main()
{
    Node *head = NULL, *node = NULL, *temp;
    int val;
    do
    {
        printf("\nif you need to store data then press 1.\nif you did not need storage then press 0. \nPress : ");
        scanf("%d", &val);
        if (val == 1)
        {
            node = (Node *)malloc(sizeof(Node));

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
        printf("There is no data in the list.\n");
        return 1;
    }
    printf("\nThe list is : \n");
    Display_Linked_List(head);
    Delete_Item_At_First(head);
    return 0;
}
