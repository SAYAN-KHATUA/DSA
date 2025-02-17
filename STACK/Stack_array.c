#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE];
int top = -1;

int Isempty() { return top == -1; }

int Isfull() { return top == MAXSIZE - 1; }

void push()
{
    int val;
    if (!Isfull())
    {
        printf("\nEnter the data : ");
        scanf("%d", &val);
        printf("\n");
        top = top + 1;
        stack[top] = val;
    }
    else
    {
        printf("\nCould not insert data, Stack is full.\n\n");
    }
}

void pop()
{
    if (!Isempty())
    {
        int val = stack[top];
        top--;
        printf("\nPopped element: %d\n", val);
    }
    else
    {
        printf("\nCould not retrieve data, Stack is empty.\n");
    }
    printf("\n");
}

void peek()
{
    if (top == -1)
    {
        printf("\nUnderflow\n\n");
    }
    else
    {
        printf("\nThe top of the stack is : %d\n\n", stack[top]);
    }
}

void show()
{
    if (Isempty())
    {
        printf("\nStack is empty.\n\n");
    }
    else
    {
        printf("\nThe stack data elements are : ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n\n");
    }
}

int main()
{
    int choice = 0;
    printf("*********Stack operations using array*********");

    printf("\n----------------------------------------------\n");
    while (choice != 5)
    {
        printf("Chose one from the below options...");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit");
        printf("\nEnter your choice : ");
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
            printf("Exiting....");
            break;
        default:
            printf("Please Enter valid choice ");
        }
    }
    return 0;
}