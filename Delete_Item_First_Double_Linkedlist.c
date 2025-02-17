#include <stdio.h>
#include <stdlib.h>

typedef struct Linked_list
{
    struct Linked_list *previous;
    int data;
    struct Linked_list *next;
} Node;

void Display_Linked_List(Node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null!\n");
}

void Display_Reverse_Linked_List(Node *temp)
{
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->previous;
    }
    printf("Null!\n");
}

void Delete_Item_At_First(Node *head, Node *tail)
{
    head->next->previous = NULL;
    head = head->next;
    printf("\nAfter deleted the updated list is : \n");
    Display_Linked_List(head);

    printf("\nAfter deleted the updated reverse list is : \n");
    Display_Reverse_Linked_List(tail);
}

int main()
{
    Node *head = NULL, *tail = NULL, *node = NULL, *temp;
    int val , check;
    do
    {
        printf("\nIf you need to store data then press 1.\nIf you don't need to store data then press 0.\nPress: ");
        scanf("%d", &val);
        if (val == 1)
        {
            node = (Node *)malloc(sizeof(Node));

            if (node == NULL)
            {
                printf("Memory allocation failed\n");
                return 1;
            }
            printf("\nData: ");
            scanf("%d", &node->data);
            node->previous = NULL;
            node->next = NULL;

            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                temp = tail;
                temp->next = node;
                node->previous = temp;
                tail = node;
            }
        }
    } while (val);

    if (head == NULL)
    {
        printf("There is no memory allocated.\n");
        return 1;
    }

    printf("\nThe list is: \n");
    Display_Linked_List(head);

    printf("\nThe reverse list is: \n");
    Display_Reverse_Linked_List(tail);
    while (1)
    {
        Delete_Item_At_First(head, tail);
        printf("\nDo you want to continue deletion at first :\n1->yes\n0->No\nPress : ");
        scanf("%d", &check);
        printf("\n");
        if (check == 0)
        {
            break;
        }
    }

    return 0;
}
