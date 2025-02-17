#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// create a structure of for every node in linkedlist
typedef struct NodeList
{
    int value;
    struct NodeList *next;
} Node;

// create a structure for linkedlist where every linkedlist's have a head,tail and a size
typedef struct LinkedList
{
    Node *head;
    Node *tail;
    int size;
} linkedlist;

// initialise a linked list where initial size is 0 and head,tail is points to NULL
void intitLinkedList(linkedlist *list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

// create a fuction for show the linkedlist is empty
void showEmpty()
{
    printf("The linkedlist is empty!!!\n");
}
// create insertFist function
void insertFirst(linkedlist *list, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL)
    {
        list->tail = node;
    }
    list->size++;
}
// create insertLast function
void insertLast(linkedlist *list, int value)
{
    if (list->size == 0)
    {
        insertFirst(list, value); // if the size of the linkedlist is 0 then call insertFirst() function
        return;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    (list->tail)->next = node;
    list->tail = node;
    node->next = NULL;
    list->size++;
}

void insertAtTheIndex(linkedlist *list, int idx, int value)
{
    if (idx == 0 && list->size == 0) // if the index and size both 0 then call insertFirst() function
    {
        insertFirst(list, value);
        return;
    }
    if (idx > 0 && list->size == 0) // if the size is 0
    {
        showEmpty(); // call showEmpty() function
        return;
    }

    if (idx < 0 || idx > list->size)
    {
        printf("Invalid index!!!"); // if the index>0 or index > size then show "invalid"
        return;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    if (idx == 0) // if index is 0 means first index
    {
        node->next = list->head; // we have to update the head
        list->head = node;
    }
    else
    {
        Node *temp = list->head;
        for (int i = 1; i < idx; i++)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;

        if (idx == list->size) // if the index is equal to size means we have to update the tail
            list->tail = node;
    }
    list->size++;
}

void deleteFirst(linkedlist *list)
{
    if (list->size == 0)
    {
        showEmpty();
        return;
    }
    Node *temp = list->head;
    list->head = (list->head)->next;
    free(temp);
    list->size--;
}

void deleteLast(linkedlist *list)
{
    if (list->size == 0)
    {
        showEmpty();
        return;
    }
    Node *temp1 = list->head;
    Node *temp2 = list->head;
    for (int i = 1; i < list->size; i++)
    {
        if (i < list->size - 1)
            temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    list->tail = temp1;
    free(temp2);
    list->size--;
}

void deleteAtTheIndex(linkedlist *list, int idx)
{
    if (list->size == 0)
    {
        showEmpty();
        return;
    }
    if (idx > list->size - 1)
    {
        printf("Invalid index!!!");
        return;
    }
    Node *temp1 = list->head;
    Node *temp2 = list->head;
    for (int i = 1; i <= idx; i++)
    {
        if (i < idx)
            temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    free(temp2);
    list->size--;
}
void displayFromStart(linkedlist *list)
{
    if (list->size == 0)
    {
        printf("\nThere are no elements inside the linked list!!!");
        return;
    }
    Node *ap = list->head;
    printf("Start->");
    while (ap != NULL)
    {
        printf("%d->", ap->value);
        ap = ap->next;
    }
    printf("End");
}

int Size(linkedlist *list)
{
    return list->size;
}

void displayFromLast(linkedlist *list)
{
    if (list->size == 0)
    {
        printf("\nThere are no elements inside the linked list!!!");
        return;
    }
    Node *ap = list->head;
    int *arr = (int *)calloc(list->size, sizeof(int));
    int i = 0;
    while (ap != NULL)
    {
        arr[i++] = ap->value;
        ap = ap->next;
    }
    printf("End->");
    for (int i = list->size - 1; i >= 0; i--)
    {
        printf("%d->", arr[i]);
    }
    printf("Start");
}

int main()
{
    linkedlist list;
    intitLinkedList(&list);
    int choice1, choice2, value, check, idx, value_insert, length, a, showReverse, value_insert2, value_insert3;
    bool Forcase1 = true, Forcase2 = true, Forcase3 = true, Forcase4 = true;
    printf("Enter your choice:\nEnter 1 for insert:\nEnter 2 for delete:\n");
    scanf("%d", &choice1);
    switch (choice1)
    {
    case 1:
        printf("\nChoose an option:\nEnter 1 for insertFirst:\nEnter 2 for insertLast:\nEnter 3 for insert at any other index:\n");
        scanf("%d", &choice2);
        switch (choice2)
        {
        case 1:
            while (1)
            {
                printf("\nEnter the value for insertion:");
                scanf("%d", &value);
                insertFirst(&list, value);
                displayFromStart(&list);
                printf("\nThe size is:%d", Size(&list));
                printf("\nDo you want to continue insertion:\n1->yes\n0->No\n");
                scanf("%d", &check);
                if (check == 0)
                    break;
            }

            break;
        case 2:
            while (1)
            {
                printf("\nEnter the value for insertion:");
                scanf("%d", &value);
                insertLast(&list, value);
                displayFromStart(&list);
                printf("\nThe size is:%d", Size(&list));
                printf("\nDo you want to continue insertion:\n1->yes\n0->No\n");
                scanf("%d", &check);
                if (check == 0)
                    break;
            }
            break;
        case 3:
            while (1)
            {
                if (Forcase1)
                {
                    printf("Atfirst you have to insert some elements in the linkedlist:\n If don't insert any element then you must have to insert the value at 0th index:\n");
                    printf("Choose an option:\n1->Insert some elements\n2->don't insert any elements\n");
                    scanf("%d", &value_insert);
                    if (value_insert == 1)
                    {
                        printf("Enter how many elements you wants to enter:\n");
                        scanf("%d", &length);
                        printf("Enter value of the elements:\n");
                        for (int i = 0; i < length; i++)
                        {
                            scanf("%d", &a);
                            insertLast(&list, a);
                        }
                        displayFromStart(&list);
                        printf("\n");
                    }
                }
                Forcase1 = false;
                printf("Enter the index for insertion:\n");
                scanf("%d", &idx);
                printf("\nEnter the value for insertion:");
                scanf("%d", &value);
                insertAtTheIndex(&list, idx, value);
                displayFromStart(&list);
                printf("\nDo you want to continue insertion:\n1->yes\n0->No\n");
                scanf("%d", &check);
                if (check == 0)
                    break;
            }
            displayFromStart(&list);
            printf("\nDo you want to display the linkedlist in reverse format??\n1->Yes\n2->No\n");
            scanf("%d", &showReverse);
            if (showReverse == 1)
                displayFromLast(&list);
            break;
        default:
            printf("Pls choose a right option!!");
            break;
        }
        break;
    case 2:
        printf("Choose an option:\nEnter 1 for deleteFirst:\nEnter 2 for deleteLast:\nEnter 3 for delete any other index:\n");
        scanf("%d", &choice2);
        switch (choice2)
        {
        case 1:
            while (1)
            {
                if (Forcase2)
                {
                    printf("Before delete we have to insert some elements in the linked list:\nAre you want to insert elements?\n1->Yes\n0->No\n");
                    scanf("%d", &value_insert2);
                    if (value_insert2 == 1)
                    {
                        printf("Enter how many elements you want to insert:\n");
                        scanf("%d", &length);
                        printf("Enter value of the elements:\n");
                        for (int i = 0; i < length; i++)
                        {
                            scanf("%d", &a);
                            insertLast(&list, a);
                        }
                        displayFromStart(&list);
                        printf("\n");
                        Forcase2 = false;
                    }
                }
                deleteFirst(&list);
                if (Size(&list) != 0)
                    printf("After deletion the linked list is:\n");
                displayFromStart(&list);
                printf("\nAre you want to continue this deletion process?\n1->Yes\n0->No\n");
                scanf("%d", &check);
                if (check == 0)
                    break;
            }
            break;
        case 2:
            while (1)
            {
                if (Forcase3)
                {
                    printf("Before delete we have to insert some elements in the linked list:\nAre you want to insert elements?\n1->Yes\n0->No\n");
                    scanf("%d", &value_insert3);
                    if (value_insert3 == 1)
                    {
                        printf("Enter the number of nodes of the linked list:\n");
                        scanf("%d", &length);
                        printf("Enter value of the nodes:\n");
                        for (int i = 0; i < length; i++)
                        {
                            scanf("%d", &a);
                            insertLast(&list, a);
                        }
                        displayFromStart(&list);
                        printf("\n");
                        Forcase3 = false;
                    }
                }
                deleteLast(&list);
                if (Size(&list) != 0)
                    printf("After deletion the new linkedlist is:\n");
                displayFromStart(&list);
                printf("\nAre you want to continue this deletion process?\n1->Yes\n0->No\n");
                scanf("%d", &check);
                if (check == 0)
                    break;
            }
            break;
        case 3:
            while (1)
            {
                if (Forcase4)
                {
                    printf("The linked list is empty at first we have to insert some elements before delete\nAre you want to insert elements:\n1->Yes\n0->No\n");
                    scanf("%d", &check);
                    if (check == 1)
                    {
                        printf("Enter how many elements you want to insert:\n");
                        scanf("%d", &length);
                        printf("Enter values of elements in the linked list:\n");
                        for (int i = 0; i < length; i++)
                        {
                            scanf("%d", &a);
                            insertLast(&list, a);
                        }
                        displayFromStart(&list);
                        printf("\n");
                    }
                    Forcase4 = false;
                }
                printf("Enter the index for deletion:\n");
                scanf("%d", &idx);
                deleteAtTheIndex(&list, idx);
                displayFromStart(&list);
                printf("\nThe size is:%d", Size(&list));
                printf("\nAre you want to continue this deletion process\n1->Yes\n0->No\n");
                scanf("%d", &check);
                if (check == 0)
                    break;
            }
            break;
        default:
            printf("Pls choose a valid option!!!");
            break;
        }
        break;
    default:
        printf("Pls choose a valid option!!!");
        break;
    }

    return 0;
}