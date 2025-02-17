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
    if (temp == NULL)
    {
        printf("Polynomial is empty!\n");
        return;
    }

    printf("Polynomial: ");
    while (temp != NULL)
    {
        printf("[%dX^%d]", temp->coef, temp->expo);
        if (temp->next != NULL)
        {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL, *head1 = NULL, *result = NULL, *node = NULL, *temp, *temp1;
    int val;
    printf("Enter the first equation value...\n");
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
        printf("No terms added to the first polynomial.\n");
        return 1;
    }
    printf("\nEnter the second equation value...\n");
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
            if (head1 == NULL)
            {
                head1 = node;
            }
            else
            {
                temp = head1;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = node;
            }
        }
    } while (val);
    if (head1 == NULL)
    {
        printf("No terms added to the second polynomial.\n");
        return 1;
    }
    printf("\nThe first equation is : \n");
    Display_Linked_List(head);
    printf("\nThe second polynomial is:\n");
    Display_Linked_List(head1);
    printf("\n\n");
    while (head != NULL && head1 != NULL)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        if (node == NULL)
        {
            printf("Memory allocation failed\n");
            return 1;
        }

        node->coef = head->coef + head1->coef;
        node->expo = head1->expo;
        node->next = NULL;
        head = head->next;
        head1 = head1->next;
        if (result == NULL)
        {
            result = node;
        }
        else
        {
            temp = result;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
        printf("\nThe result is : \n");
        Display_Linked_List(result);
        return 0;
    }
}