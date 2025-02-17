#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_Linkedlist
{
    int data;
    struct Stack_Linkedlist *next;
} Node;

Node *head = NULL, *node = NULL, *tail = NULL, *temp;

void push()
{
    node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("\nEnter the Data : ");
    scanf("%d", &node->data);
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
        tail = node;
    }
    printf("\n");
}

void pop()
{
    if (head == NULL)
    {
        printf("\nUnderflow.\n\n");
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        free(tail);
        tail = temp;
        tail->next = NULL;
    }
    printf("\nElement popped successfully.\n\n");
}

void peek()
{
    if (head == NULL)
    {
        printf("\nNo data element is store in the stack\n\n");
    }
    else
    {
        printf("\nThe top of the stack is : %d\n\n", tail->data);
    }
}

void show()
{
    if (head == NULL)
    {
        printf("\nThe stack is empty.\n\n");
    }
    else
    {
        printf("\nThe stack elements are : ");
        temp = head;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("Null!\n\n");
    }
}

void freeStack()
{
    temp = head;
    while (temp != NULL)
    {
        Node *toFree = temp;
        temp = temp->next;
        free(toFree);
    }
    head = tail = NULL;
}

int main()
{
    int choice = 0;
    printf("\n----------Operations of stack using linkedlist----------\n");
    printf("********************************************************\n");
    while (choice != 5)
    {
        printf("Chose one from the below options...");
        printf("\n1.push\n2.pop\n3.peek\n4.show\n5.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            show();
            break;
        case 5:
            freeStack();
            printf("Exiting.......");
            break;
        default:
            printf("Plz enter a valid choice.");
        }
    }
    return 0;
}