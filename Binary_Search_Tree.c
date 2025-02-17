#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Binary_Search_Tree
{
    int data;
    struct Binary_Search_Tree *right, *left;
} Node;

Node *Get_Node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed!");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node *Insert_Node(Node *root, int data)
{
    if (root == NULL)
    {
        root = Get_Node(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Insert_Node(root->left, data);
    }
    else
    {
        root->right = Insert_Node(root->right, data);
    }
    return root;
}

bool Search_item(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return Search_item(root->left, data);
    }
    else
    {
        return Search_item(root->right, data);
    }
}

void In_order_Traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    In_order_Traversal(root->left);
    printf("%d->", root->data);
    In_order_Traversal(root->right);
}

void free_Tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    free_Tree(root->left);
    free_Tree(root->right);
    free(root);
}

int main()
{
    Node *root = NULL;
    int choice = 0;
    int value;
    bool found;
    printf("**********Operation on Binary Search Tree**********");
    printf("\n---------------------------------------------------\n");
    while (choice != 4)
    {
        printf("\nBinary Search Tree Operations......\n");
        printf("\n1.Insert\n2.Search\n3.In-order Traversal\n4.Exit\nchoice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to insert : ");
            scanf("%d", &value);
            root = Insert_Node(root, value);
            break;
        case 2:
            printf("\nEnter the value of search : ");
            scanf("%d", &value);
            found = Search_item(root, value);
            if (found)
            {
                printf("The value %d found in the BST.\n", value);
            }
            else
            {
                printf("The value %d is not found in the BST.\n", value);
            }
            break;
        case 3:
            printf("The inorder traversal is : ");
            In_order_Traversal(root);
            printf("\n");
            break;
        case 4:
            free_Tree(root);
            printf("Exiting....\n");
            break;
        default:
            printf("Invalid choice. Plz try again.\n");
        }
    }
    return 0;
}